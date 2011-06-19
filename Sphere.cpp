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

int Sphere::intersection(Ray &ray, double &t) {
    
    double t1 = ((centre - ray.start) * ray.direction) / (sqrtf(ray.direction * ray.direction));

    if (t1 <= 0.0f)
        return 0;

    /* d = sqrt( ||L||^2 - t1^2 )**/
    double d = sqrtf((centre - ray.start)*(centre - ray.start) - pow(t1, 2));

    if (d > raio)
        return 0;

    double t2 = sqrtf(pow(raio, 2) - pow(d, 2));

<<<<<<< HEAD
	t = t1 - t2;
	
	if(t>0.0f)
		return 1;
	return 0;
=======
    t = t1 - t2;
    
    if( t < 0)
        return 0;
    
    return 1;
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4
}

void Sphere::calculateNormal(Point &hitPoint, Vector &normal){
    
    normal = hitPoint - centre;
    
    double temp = normal * normal;
    temp = 1.0f / sqrtf(temp);
    normal = normal * temp;
}

double Sphere::getRaio() {
    return raio;
}

int Sphere::refractionDirection(Ray &refraction_ray, Point &hitPoint, Vector &normal, double &t) {
	/*
	Water	1.33
	Glass	1.50
	Quartz crystal	1.54
	Glycerin	1.47
	Diamond	2.42
	*/
	Ray aux;
	aux.direction = -refraction_ray.direction;
	aux.normalizar();
	
	double cosTetaI = aux.direction*normal; /* Producto interno */
	double n = 1.0/getRefraction();
	
	/* sin2 + cos2 = 1 */
	double cosTetaR = sqrtf(1-pow((n* sqrtf(1-pow(cosTetaI,2)) ),2));
	
	Vector refractado = refraction_ray.direction*(n) - normal*(n*cosTetaI - cosTetaR );
	
	aux.direction = refractado;
	aux.start = hitPoint;
	//aux.normalizar();
	
	if( intersection(aux,t) ) {
		Point hitPoint2;
		hitPoint2 = aux.start + aux.direction*t;
		
		/* direcção é a mesma de antes */
		refraction_ray.start = hitPoint2;
		return 1;
	} else {
		return 0;
	}
}
