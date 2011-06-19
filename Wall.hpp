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
<<<<<<< HEAD
	int refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal, double &t);
=======
        void setChess(bool b);
	int refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal);
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4

};

#endif