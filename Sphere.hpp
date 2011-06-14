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
    bool intersects(Ray &ray, double &rT0, double &rT1);
    double getRaio();


};

#endif
