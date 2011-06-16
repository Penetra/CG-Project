#ifndef CYLINDER_H
#define CYLINDER_H

#include "Structures.hpp"
#include "Object.hpp"

class Ray;
class Wall;

class Cylinder : public Object {
public:
    double raio, height;
    Point bottom, top;
    Point position;
    Cylinder();
    Cylinder(double bottomX, double bottomY, double bottomZ, double red, double green, double blue, double r, double h);
    ~Cylinder();

    int intersection(Ray &raio, double &t);
    void calculateNormal(Point &hitPoint, Vector &normal);
    double getRaio();


};

#endif
