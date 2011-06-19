#include "Cylinder.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Wall.hpp"
#include <cmath>
#include <stdio.h>

#define DBL_MAX 1.7976931348623158e+308 /* max value */

Cylinder::Cylinder(){}

Cylinder::Cylinder(double bottomX, double bottomY, double bottomZ, double red, double green, double blue, double r, double h){
	
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
	
}

Cylinder::~Cylinder() {}

int Cylinder::intersection(Ray &ray, double &t){
	
	t = DBL_MAX;
	
	double a = pow(ray.direction.x,2)+pow(ray.direction.z,2);
	double b = 2*( ray.direction.x*(ray.start.x-bottom.x) + ray.direction.z*(ray.start.z-bottom.z));
	double c = pow(ray.start.x-bottom.x,2)+pow(ray.start.z-bottom.z,2) - raio2;
	
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
				if(t2>0)
					t = t2;
			}
		} else {
			if(t1>0)
				t = t1;
		}
	} else {
		if( intersection2.y<=top.y && intersection2.y>=bottom.y ) {
			if( t2 > 0)
				t = t2;
		}
	}
	
	double t3=DBL_MAX,t4 = DBL_MAX;
	Wall *bottom_ = new Wall(0, bottom.y, 0, 0.0, -1.0, 0.0, 1.0, 1.0, 1.0);
	Wall *top_ = new Wall(0, top.y, 0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);
	if(bottom_->intersection(ray,t3)) { /* intersects plane */
		intersection = ray.start+(ray.direction*t3);
		if( powf(intersection.x-bottom.x,2) + powf(intersection.z-bottom.z,2) <= raio2 ) { /* intersects cylinder */
			if(t3<t)
				t = t3;
		}
	}
	if(top_->intersection(ray,t4)) { /* intersects plane */
		intersection = ray.start+(ray.direction*t4);
		if( powf(intersection.x-top.x,2) + powf(intersection.z-top.z,2) <= raio2 ) { /* intersects cylinder */
			if(t4<t)
				t = t4;
		}
	}
	
	if(t!=DBL_MAX && t>0)
		return 1;
	
	return 0;
	
}

double Cylinder::getRaio(){
	return raio;
}

void Cylinder::calculateNormal(Point &hitPoint, Vector &normal){
	/*printf("%lf\n",hitPoint.y);*/
    if (hitPoint.y==top.y) { /* Hit the top */
		normal.x = 0;
		normal.y = 1;
		normal.z = 0;
	} else if (hitPoint.y==bottom.y) { /* Hit the bottom */
		normal.x = 0;
		normal.y = -1;
		normal.z = 0;
	} else { /* Hit the side */
		normal.x = hitPoint.x-bottom.x;
		normal.y = 0;
		normal.z = hitPoint.z-bottom.z;
		double temp = sqrtf( normal*normal );
		if(temp!=0.0f)
			normal = normal*(1.0f/temp);
	}
}

int Cylinder::refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal) {
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
	double n = 1.0/getRefraction();
	
	/* sin2 + cos2 = 1 */
	double cosTetaR = sqrtf(1-(n* sqrtf(1-pow(cosTetaI,2)) ));
	
	Vector refractado = refraction_ray.direction*(n) - normal*(n*cosTetaI - cosTetaR );
	
	aux.direction = refractado;
	aux.start = hitPoint;
	aux.normalizar();
	
	double t;
	
	if( intersection(aux,t) ) {
		Point hitPoint2;
		hitPoint2 = aux.start + aux.direction*t;
		
		/* direcção é a mesma de antes */
		refraction_ray.start = hitPoint2;
		
		return 1;
	} else {
		return 0;
	}
}
