#include "Cylinder.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Wall.hpp"
#include <math.h>
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
	printf("%lf %lf\n",top.z, bottom.z);
	raio = r;
	height = h;
	
}
Cylinder::~Cylinder(){}


int Cylinder::intersection(Ray &ray, double &t){
	
	t = DBL_MAX;
	
	double a = pow(ray.direction.x,2)+pow(ray.direction.z,2);
	double b = 2*ray.start.x*ray.direction.x + 2*ray.start.z*ray.direction.z;
	double c = pow(ray.start.x,2)+pow(ray.start.z,2) - raio*raio;
	
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
	Wall *bottom_ = new Wall(bottom.x, bottom.y, bottom.z, 0.0, -1.0, 0.0, 1.0, 1.0, 1.0);
	Wall *top_ = new Wall(top.x, top.y, top.z, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);
	if(bottom_->intersection(ray,t3)) { /* intersects plane */
		intersection = ray.start+(ray.direction*t3);
		if( pow(intersection.x,2) + pow(intersection.z,2) <= raio*raio ) { /* intersects cylinder */
			if(t3<t)
				t = t3;
		}
	}
	if(top_->intersection(ray,t4)) { /* intersects plane */
		intersection = ray.start+(ray.direction*t4);
		if( pow(intersection.x,2) + pow(intersection.z,2) <= raio*raio ) { /* intersects cylinder */
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

Point Cylinder::getCentre2(Point hitPoint){
	Point normal;
	if (hitPoint.y==top.y) { /* Hit the top */
		normal.x = 0;
		normal.y = 1;
		normal.z = 0;
	} else if (hitPoint.y==bottom.y) { /* Hit the bottom */
		normal.x = 0;
		normal.y = 1;
		normal.z = 0;
	} else { /* Hit the side */
		normal.x = bottom.x;
		normal.y = hitPoint.y;
		normal.z = bottom.z;
	}
	return normal;
}
