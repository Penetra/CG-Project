#include "Wall.hpp"

Wall::Wall(){

}

Wall::Wall(double normalX, double normalY, double normalZ, double red, double green, double blue, double r){
	normal.x = normalX;
	normal.y = normalY;
	normal.z = normalZ;
	
	cor.red = red;
	cor.green = green;
	cor.blue = blue;
}

Wall::~Wall(){

}

int Wall::intersection(Ray &ray, double &t){


}

Vector Wall::getNormal(){
	return normal;
}