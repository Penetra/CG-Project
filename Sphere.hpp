#ifndef SPHERE_H
#define SPHERE_H

#include "Structures.hpp"
#include "Object.hpp"

class Ray;

class Sphere : public Object {
public:
    double raio;
    Point position;
    Sphere();
    Sphere(double centreX, double centreY, double centreZ, double red, double green, double blue, double r);
    ~Sphere();

    int intersection(Ray &raio, double &t);
    void calculateNormal(Point &hitPoint, Vector &normal);
    double getRaio();
	int refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal);

};

#endif
