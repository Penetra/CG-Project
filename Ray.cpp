#include "Ray.hpp"
#include <cmath>

Ray::Ray(){

}
Ray::Ray(double x, double y, double z){

	start.x = x;
	start.y = y;
	start.z = z;
        intersectionToLight = false;

	
}
Ray::~Ray(){
}

Point Ray::getStart(){
	return start;
}
Vector Ray::getDirection(){
	return direction;
}
double Ray::getRed(){
	return cor.red;
}
double Ray::getGreen(){
	return cor.green;
}
double Ray::getBlue(){
	return cor.blue;
}
double Ray::getIntensity(){
	return intensity;
}
void Ray::setStart(double x, double y, double z){
	start.x = x;
	start.y = y;
	start.z = z;
}
void Ray::setDirection(double x, double y, double z){
	direction.x = x;
	direction.y = y;
	direction.z = z;
}
void Ray::normalizar(){
    double temp = sqrtf(direction * direction);
    
    if(temp != 0.0f)
        direction = direction*(1.0f / temp);
    
}
void Ray::setRed(double r){
	cor.red = r;
}
void Ray::setGreen(double g){
	cor.green = g;
}
void Ray::setBlue(double b){
	cor.blue = b;
}