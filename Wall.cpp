#include "Wall.hpp"
#include "Ray.hpp"
#include <cstdio>
#include <cmath>

Wall::Wall() {

}

Wall::Wall(double centreX, double centreY, double centreZ, double normalX, double normalY, double normalZ, double red, double green, double blue) {
    centre.x = centreX;
    centre.y = centreY;
    centre.z = centreZ;
    normal.x = normalX;
    normal.y = normalY;
    normal.z = normalZ;

    cor.red = red;
    cor.green = green;
    cor.blue = blue;
}

Wall::~Wall() {

}


int Wall::intersection(Ray &ray, double &t) {
    
    double d = 0 - (getNormal() * centre);
    
    double temp = (getNormal() * ray.direction);
    /* If t == 0 the ray and the plane are parallel so there's no intersection*/
    if(temp==0){
        return 0;
    }
    t = (-d - (getNormal() * ray.start)) / temp;
    
    /* If t < 0 there's no intersection**/
    if( t < 0)
        return 0;
    
    return 1;
    
    /*double distance = sqrtf(ray.direction * ray.direction);
    
    double numerator = (centre - ray.start)*normal;
    double denominator = ray.direction*normal;

    if (denominator == 0)
        return 0;

    t = numerator/denominator;

    if (t <= 0.00000001)
        return 0;

    if(ray.intersectionToLight && t > distance){
        printf("ola\n");
        return 0;
    }

    return 1;**/
    
}

void Wall::calculateNormal(Point &hitPoint, Vector &normalV){
    
    normalV.x = normal.x;
    normalV.y = normal.y;
    normalV.z = normal.z;
    
}


Vector Wall::getNormal() {
    return normal;
}