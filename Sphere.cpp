#include "Sphere.hpp"
#include "Object.hpp"
#include "Ray.hpp"

Sphere::Sphere(){}

Sphere::Sphere(double centreX, double centreY, double centreZ, double red, double green, double blue, double r){
	
	centre.x = centreX;
	centre.y = centreY;
	centre.z = centreZ;
	
	cor.red = red;
	cor.green = green;
	cor.blue = blue;
	
	raio = r;
	
}
Sphere::~Sphere(){}


int Sphere::intersection(Ray &ray, double &t){
    
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

double Sphere::getRaio(){
	return raio;
}
