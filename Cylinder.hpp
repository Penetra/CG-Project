#ifndef CYLINDER_H
#define CYLINDER_H

#include "Structures.hpp"
#include "Object.hpp"

class Ray;

class Cylinder : public Object {
public:
    double raio, height;
    Point position;
    Cylinder();
    Cylinder(double centreX, double centreY, double centreZ, double red, double green, double blue, double r);
    ~Cylinder();

    int intersection(Ray &raio, double &t);

    double getRaio();


};

#endif
