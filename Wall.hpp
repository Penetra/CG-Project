#ifndef WALL_HPP
#define WALL_HPP

#include "Structures.hpp"
#include "Object.hpp"

class Wall: public Object{

public:
	Vector normal;
        bool chess;
	Wall();
	Wall(double centreX, double centreY, double centreZ, double normalX, double normalY, double normalZ, double red, double green, double blue);
	~Wall();
	
	int intersection(Ray &ray, double &t);
        void calculateNormal(Point &hitPoint, Vector &normal);
        bool intersects(Ray &ray, double &rT0, double &rT1);
	Vector getNormal();
        void setChess(bool b);

};

#endif