#include "Cylinder.hpp"
#include "Object.hpp"
#include "Ray.hpp"

Cylinder::Cylinder(){}

Cylinder::Cylinder(double centreX, double centreY, double centreZ, double red, double green, double blue, double r, double h){
	
	centre.x = centreX;
	centre.y = centreY;
	centre.z = centreZ;
	
	cor.red = red;
	cor.green = green;
	cor.blue = blue;
	
	raio = r;
	height = h;
	
}
Cylinder::~Cylinder(){}


int Cylinder::intersection(Ray &ray, double &t){
    
    t = (( centre - ray.start) * ray.direction) / ( ray.direction * ray.direction);
    
    Point intersect;
    
    intersect = ray.start + (ray.direction * t);
    
    double d = raio * raio - ((intersect - centre)* (intersect - centre));
    
    if(d < 0 || t <= 0){
        return 0;
    }
    
    if(d == 0){
        return 1;
    }


}

double Cylinder::getRaio(){
	return raio;
}
