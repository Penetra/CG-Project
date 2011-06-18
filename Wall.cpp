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
    
    chess = false;
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
    
    /* If t < 0 there's no intersection*/
    if( t < 0)
        return 0;
    
    if(chess){
        Point hitPoint = ray.start + (ray.direction * t);
        int x,z;
        x = int(floor(hitPoint.x * 1/200));
        z = int(floor(hitPoint.z * 1/200));
        
        if((x % 2) == 0){
            if((z % 2) == 0){
                cor.red = 1.0;
                cor.green = 1.0;
                cor.blue = 1.0;
            }
            else{
                cor.red = 0.0;
                cor.green = 0.0;
                cor.blue = 0.0;
            }
        }
        else{
            if((z % 2) == 0){
                cor.red = 0.0;
                cor.green = 0.0;
                cor.blue = 0.0;
            }
            else{
                cor.red = 1.0;
                cor.green = 1.0;
                cor.blue = 1.0;
            }
        }
        
    }
    
    
    
    return 1;
    
    
}

void Wall::calculateNormal(Point &hitPoint, Vector &normalV){
    
    normalV.x = normal.x;
    normalV.y = normal.y;
    normalV.z = normal.z;
    
}


Vector Wall::getNormal() {
    return normal;
}

int Wall::refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal) {
	return 0;
}