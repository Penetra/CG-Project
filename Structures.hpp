
#ifndef __STRUCTURES_H
#define __STRUCTURES_H
#include <vector>

using namespace std;

class Sphere;
class Light;

struct Point{
	double x,y,z;
	
	Point& operator += (const Point &p2)
    {
        this->x += p2.x;
        this->y += p2.y;
        this->z += p2.z;
        return *this;
    }
	
};

struct Vector{
	double x,y,z;	
	
	Vector& operator += (const Vector &v2){
	    this->x += v2.x;
        this->y += v2.y;
        this->z += v2.z;
	    return *this;
    }
	
};

inline Point operator + (const Point&p, const Vector &v){
	Point p2={ p.x + v.x, p.y + v.y, p.z + v.z };
	return p2;
}

inline Point operator - (const Point&p, const Vector &v){
	Point p2={p.x - v.x, p.y - v.y, p.z - v.z};
	return p2;
}

inline Vector operator + (const Vector&v1, const Vector &v2){
	Vector v={v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	return v;
}

inline Vector operator - (const Point&p1, const Point &p2){
	Vector v = {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
	return v;
}



struct Colour{

	double red, green, blue;
	
        inline Colour& operator += (const Colour &c2){
                this->red += c2.red;
                this->green += c2.green;
                this->blue += c2.blue;
                return *this;
        }
		
		inline Colour& operator = ( double c){
			this->red = c;
			this->green = c;
			this->blue = c;
			return *this;
		}

};


struct Material {
    Colour diffuse;
    double reflection;
    Colour specular;
    double power;
};

/*struct Sphere {
	Point pos;
	double size;
	
	Colour diffuse;
    double reflection;
    Colour specular;
    double power;
};

struct Light {
	Point pos;
	Colour intensity;
};

/*struct Ray {
	Point start;
	Vector direction;
};*/

struct Scene{
	vector<Sphere> spheres;
	vector<Light> lights;
};

void createImage(Scene scene, int screenWidth, int screenHeight);

#endif
