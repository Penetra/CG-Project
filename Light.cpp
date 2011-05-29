#include "Light.hpp"

Light::Light(){

}

Light::Light(double centreX, double centreY, double centreZ, double red, double green, double blue, double intensity){
	centre.x = centreX;
	centre.y = centreY;
	centre.z = centreZ;
	
	cor.red = red;
	cor.green = green;
	cor.blue = blue;
	
	intensity = intensity;
}

Light::~Light(){

}

Point Light::getCentre(){
	return centre;
}

double Light::getRed(){
	return cor.red;
}
double Light::getGreen(){
	return cor.green;
}
double Light::getBlue(){
	return cor.blue;
}

double Light::getIntensity(){
	return intensity;
}

void Light::setRed(double r){
	cor.red = r;
}

void Light::setGreen(double g){
	cor.green = g;
}

void Light::setBlue(double b){
	cor.blue = b;
}
	
