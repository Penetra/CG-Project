#ifndef WALL_HPP
#define WALL_HPP

#include "Structures.hpp"
#include "Object.hpp"

class Wall: public Object{

public:
	Vector normal;
	
	Wall();
	Wall(double normalX, double normalY, double normalZ, double red, double green, double blue, double r);
	~Wall();
	
	int intersection(Ray &ray, double &t);
	
	Vector getNormal();

};

#endif