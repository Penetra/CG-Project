#include "Sphere.hpp"
#include "Object.hpp"

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


}

double Sphere::getRaio(){
	return raio;
}
