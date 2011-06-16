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
    
    /*double d = 0 - (getNormal() * centre);
    
    double temp = (getNormal() * ray.direction);
    /* If t == 0 the ray and the plane are parallel so there's no intersection**
    if(temp==0){
        return 0;
    }
    t = (-d - (getNormal() * ray.start)) / temp;
    
    /* If t < 0 there's no intersection*
    if( t < 0)
        return 0;
    
    return 1; */
    
    double distance = sqrtf(ray.direction * ray.direction);
    
    double numerator = (centre - ray.start)*normal;
    double denominator = ray.direction*normal;

    /* The ray is parallel to the plane. Can be either
     * inside the plane or outside it.
     */
    if (denominator == 0)
        return false;

    t = numerator/denominator;
    /* Just to make sure we invalidate rT1. */

    /* We are only looking for forward intersections. */
    if (t <= 0.00000001)
        return false;

    /* We have to check if intersection point is beyond the light
     * or not.
    if (ray.isToLightRay())
        if (rT0 > ray.getToLightDistance())
            return false;*/
    /*if(ray.intersectionToLight && t > distance){
        printf("ola\n");
        return false;
    }*/

    return true;
    
}


Vector Wall::getNormal() {
    return normal;
}