#ifndef RAY_HPP
#define RAY_HPP

#include "Structures.hpp"
#include "Object.hpp"

class Ray{

public:
	Point start;
	Vector direction;
	Colour cor;
	double intensity;
        bool intersectionToLight;
	Ray();
	Ray(double x, double y, double z);
	~Ray();
	
	Point getStart();
	Vector getDirection();
	double getRed();
	double getGreen();
	double getBlue();
	double getIntensity();
	void setStart(double x, double y, double z);
	void setDirection(double x, double y, double z);
	void setRed(double r);
	void setGreen(double g);
	void setBlue(double b);
        void normalizar();

};

#endif