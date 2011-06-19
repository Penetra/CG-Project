#ifndef CONE_H
#define CONE_H

#include "Structures.hpp"
#include "Object.hpp"

class Ray;
class Wall;

class Cone : public Object {
public:
	double raio, height, raio2;
	Point bottom, top;
	Point position;
	Wall *bottom_;

	Cone();
	Cone(double bottomX, double bottomY, double bottomZ, double red, double green, double blue, double r, double h);
	~Cone();

	int intersection(Ray &raio, double &t);
	void calculateNormal(Point &hitPoint, Vector &normal);
	double getRaio();
	int refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal, double &t);


};

#endif
