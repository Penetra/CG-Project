#include "Wall.hpp"
#include "Ray.hpp"
#include <cstdio>
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
    
    double d = - (centre * normal);
    
    t = (getNormal() * ray.direction);
    /* If t == 0 the ray and the plane are parallel so there's no intersection*/
    if(t==0){
        return 0;
    }
    t= 1/t;
    t *= -( ray.start * getNormal() + d );
    
    /* If t < 0 there's no intersection*/
    if( t < 0)
        return 0;
    
    printf("intersection\n");
    return 1;     
    
}

Vector Wall::getNormal() {
    return normal;
}