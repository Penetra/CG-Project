#include "Object.hpp"

Object::Object(){ 

}

Object ::~Object(){

}

double Object::getRed(){
	return cor.red;
}

double Object::getGreen(){
	return cor.green;
}

double Object::getBlue(){
	return cor.blue;
}

Point Object::getCentre(){
	return centre;
}

double Object::getReflection(){
	return reflection;
}
double Object::getRefraction(){
	return refraction;
}
double Object::getShininess(){
	return shininess;
}
Colour Object::getSpecular(){
	return specular;
}
Colour Object::getDiffuse(){
	return diffuse;
}

void Object::setReflection(double r){
	reflection = r;
}
void Object::setRefraction(double r){
	refraction = r;
}
void Object::setShininess(double s){
	shininess = s;
}
void Object::setSpecular(double r, double g, double b){
	specular.red = r;
	specular.green = g;
	specular.blue = b;
}
void Object::setDiffuse(double r, double g, double b){
	diffuse.red = r;
	diffuse.green = g;
	diffuse.blue = b;
}