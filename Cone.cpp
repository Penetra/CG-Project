#include "Cone.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Wall.hpp"
#include <cmath>
#include <stdio.h>

#define DBL_MAX 1.7976931348623158e+308 /* max value */

Cone::Cone(){}

Cone::Cone(double bottomX, double bottomY, double bottomZ, double red, double green, double blue, double r, double h){
	
	bottom.x = bottomX;
	bottom.y = bottomY;
	bottom.z = bottomZ;
	
	top.x = bottomX;
	top.y = bottomY+h;
	top.z = bottomZ;
	
	cor.red = red;
	cor.green = green;
	cor.blue = blue;

	raio = r;
	raio2 = r*r;
	height = h;
	
	bottom_ = new Wall(0, bottom.y, 0, 0.0, -1.0, 0.0, 1.0, 1.0, 1.0);
}

Cone::~Cone() {}

int Cone::intersection(Ray &ray, double &t){
	
	t = DBL_MAX;
	
	double rh = -raio2/(height*height);
	double a = pow(ray.direction.x,2)+pow(ray.direction.z,2) + rh*pow(ray.direction.y,2);
	double b = 2*( ray.direction.x*(ray.start.x-bottom.x) + ray.direction.z*(ray.start.z-bottom.z) + rh*ray.direction.y*(ray.start.y-bottom.y-height) );
	double c = pow(ray.start.x-bottom.x,2)+pow(ray.start.z-bottom.z,2) + rh*pow(ray.start.y-bottom.y-height,2);
	
	double root = b*b-4.0*a*c;
	if(root<0)
		return 0;
	
	double t1=DBL_MAX, t2=DBL_MAX;
	t1 = (-b+sqrtf(root))/(2.0*a);
	t2 = (-b-sqrtf(root))/(2.0*a);
	
	Point intersection = (ray.start)+ ((ray.direction) * t1);
	Point intersection2 = ray.start + ((ray.direction) *t2);
	
	if( intersection.y<=top.y && intersection.y>=bottom.y ) {
		if( intersection2.y<=top.y && intersection2.y>=bottom.y ) {
			if( t1<t2 && t1>0 && t2 >0 )
				t=t1;
			else {
				if(t2>0.0f)
					t = t2;
			}
		} else {
			if(t1>0.0f)
				t = t1;
		}
	} else {
		if( intersection2.y<=top.y && intersection2.y>=bottom.y ) {
			if( t2 > 0.0f)
				t = t2;
		}
	}
	
	double t3=DBL_MAX;
	
	if(bottom_->intersection(ray,t3)) { /* intersects plane */
		intersection = ray.start+(ray.direction*t3);
		if( pow(intersection.x-bottom.x,2) + pow(intersection.z-bottom.z,2) <= raio2 ) { /* intersects Cone */
			if(t3<t)
				t = t3;
		}
	}
	
	if(t!=DBL_MAX && t>0.00000001)
		return 1;
	
	return 0;
	
}

double Cone::getRaio(){
	return raio;
}

void Cone::calculateNormal(Point &hitPoint, Vector &normal){
	/*printf("%lf\n",hitPoint.y);*/
    if (hitPoint.y==bottom.y) { /* Hit the bottom */
		normal.x = 0;
		normal.y = -1;
		normal.z = 0;
	} else { /* Hit the side */
		double e = -raio2/(height*height);
		normal.x = hitPoint.x-bottom.x;
		normal.y = hitPoint.y-bottom.y-height;
		normal.z = hitPoint.z-bottom.z;
		normal.y *= e;
		e = sqrtf(normal*normal);
		normal = normal*(1.0f/e);
	}
}

int Cone::refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal, double &t) {
	/*
	Water	1.33
	Glass	1.50
	Quartz crystal	1.54
	Glycerin	1.47
	Diamond	2.42
	*/
	Ray aux;
	aux.direction = -refraction_ray.direction;
	aux.normalizar();
	
	double cosTetaI = aux.direction*normal; /* Producto interno */
	double n = 1.0f/getRefraction();
	
	/* sin2 + cos2 = 1 */
	double cosTetaR = sqrtf(1-pow((n* sqrtf(1-pow(cosTetaI,2)) ),2));
	
	if(cosTetaR ==0.0f){
		return 0;
	}
		
	
	Vector refractado = refraction_ray.direction*(n) - normal*(n*cosTetaI - cosTetaR );
	
	refraction_ray.direction = refractado;
	refraction_ray.start = hitPoint;
	refraction_ray.normalizar();
	
	return 1;
	/*
	if( intersection(aux,t) ) {
		Point hitPoint2;
		hitPoint2 = aux.start + aux.direction*t;
		
		/* direcção é a mesma de antes */
		/*refraction_ray.start = hitPoint2;
		
		return 1;
	} else {
		return 0;
	}*/
}
