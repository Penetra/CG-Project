#include "Sphere.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include <cmath>
#include <cstdio>

Sphere::Sphere() {
}

Sphere::Sphere(double centreX, double centreY, double centreZ, double red, double green, double blue, double r) {

    centre.x = centreX;
    centre.y = centreY;
    centre.z = centreZ;

    cor.red = red;
    cor.green = green;
    cor.blue = blue;

    raio = r;

}

Sphere::~Sphere() {
}

bool Sphere::intersects(Ray &ray, double &rT0, double &rT1) {

}

/*int Sphere::intersection(Ray &ray, double &t){
    
    t = (( centre - ray.start) * ray.direction) / (sqrtf(ray.direction * ray.direction));
    
    Point intersect;
    
    intersect = ray.start + (ray.direction * t);
    
    double d = raio * raio - ((intersect - centre)* (intersect - centre));
    
    if(d < 0 || t <= 0){
        return 0;
    }
    
    if(d == 0){
        return 1;
    }


}*/

int Sphere::intersection(Ray &ray, double &t) {

    
    double t1 = ((centre - ray.start) * ray.direction) / (sqrtf(ray.direction * ray.direction));

    if (t1 <= 0)
        return 0;

    /* d = sqrt( ||L||^2 - t1^2 )**/
    double d = sqrtf((centre - ray.start)*(centre - ray.start) - pow(t1, 2));

    if (d > raio)
        return 0;

    double t2 = sqrt(pow(raio, 2) - pow(d, 2));

    t = t1 - t2;    
    return 1;
}

double Sphere::getRaio() {
    return raio;
}
