#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Structures.hpp"
#include "Object.hpp"

class Light{

public:
	Point centre;
	Colour cor;
	double intensity;
	int type;
	double raio;
	
	Light();
	Light(double centreX, double centreY, double centreZ, double red, double green, double blue, double intensity);
	~Light();
	
	Point getCentre();
	double getRed();
	double getGreen();
	double getBlue();
	double getIntensity();
	void setRed(double r);
	void setGreen(double g);
	void setBlue(double b);
	void setIntensity(double it);
	void setType(int t);
	void setRaio(double r);
};

#endif
	