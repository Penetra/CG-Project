#ifndef _OBJECT_H
#define _OBJECT_H

class Ray;
#include "Structures.hpp"

class Object {
public:
    Point centre;
    Colour cor;
    double reflection, refraction, shininess;
    Colour diffuse, specular;

    Object();
    ~Object();

    int intersection(Ray &ray, double &t);

    Point getCentre();

    double getRed();
    double getGreen();
    double getBlue();

    double getReflection();
    double getRefraction();
    double getShininess();
    Colour getSpecular();
    Colour getDiffuse();

    void setReflection(double r);
    void setRefraction(double r);
    void setShininess(double s);
    void setSpecular(double r, double g, double b);
    void setDiffuse(double r, double g, double b);

};

#endif