#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#include "Structures.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Light.hpp"
#include "Cylinder.hpp"

extern Colour output[800][600];
Colour cor;

void saturation(Colour &cor){
    if(cor.red > 1.0)
        cor.red = 1.0;
    if(cor.green > 1.0)
        cor.green = 1.0;
    if(cor.blue > 1.0)
        cor.blue = 1.0;
}
double r, x, teta;
Vector use;
Vector v;
Ray shadow_ray;
void ray_trace(Ray raio, int level, Object **objectList, int objectListSize, Light *lightList, int lightListSize, int i, int j, Colour &cor) {
	int currentObject;
	int k,l;
	int shadow;
	Light currentLight;

	
	while (level < 10){
        Point hitPoint;
        currentObject = -1;

        double t, minDistance = -1;
        for (k = 0; k < objectListSize; k++) {
            if(objectList[k]->intersection(raio, t) == 1){
                if( t < minDistance || minDistance ==-1){
                    minDistance = t;
                    currentObject = k;
                }
            }
            
        }
        /* Intersections found*/
        if(currentObject != -1){
            
            hitPoint = raio.start + (raio.direction * minDistance); 
            /* Calculate Normal on the intersection point*/
            Vector normal;
            objectList[currentObject]->calculateNormal(hitPoint,normal);
			
			if( objectList[currentObject]->getRefraction() ) {
				Ray refraction_ray;
				refraction_ray.start = raio.start;
				refraction_ray.direction = raio.direction;
				
				if(objectList[currentObject]->refractionDirection(refraction_ray, hitPoint, normal, t)) {
					refraction_ray.intensity = raio.intensity;
					Colour aux_cor = {0.0f,0.0f,0.0f};
					
					ray_trace(refraction_ray, level+1, objectList, objectListSize, lightList, lightListSize, i, j, aux_cor);
					
					/* Beer's Law */
					//printf("%lf ",t);

					Colour absorbance = objectList[currentObject]->cor;
					absorbance.red *= 0.15*t*(-1);
					absorbance.green *= 0.15*t*(-1);
					absorbance.blue *= 0.15*t*(-1);
					Colour transparency = absorbance;
					transparency.red = exp(absorbance.red);
					transparency.green = exp(absorbance.green);
					transparency.blue = exp(absorbance.blue);
					cor.red += aux_cor.red*transparency.red;
					cor.green += aux_cor.green*transparency.green;
					cor.blue += aux_cor.blue*transparency.blue;
					
				}
			}
            
            Ray light;
            light.start = hitPoint;

            for(k=0;k < lightListSize; k++){

                currentLight = lightList[k];
                
                /*Define the direction to the light*/
                light.direction = currentLight.centre - hitPoint;
                
                double lightDistance = light.direction * light.direction;
                
                if(lightDistance == 0.0f)
                    continue;

                double temp = 1.0f/sqrtf(lightDistance);
                
                light.direction = light.direction * temp;
                
                double lightProj = light.direction * normal;

                /* We need to know if there's any object between our intersection point and the light**/
				if(!currentLight.type) { //normal
	                shadow = false;
	                for(l = 0;l < objectListSize; l++){
	                    t = lightDistance;
	                    if(currentObject != l && objectList[l]->intersection(shadow_ray,t)){
	                        shadow = true;
	                        break;
	                    }
	                }

				
	                if(!shadow){
					
	                    double lambert = light.direction * normal * raio.getIntensity();
                    
	                    cor.red += lambert * objectList[currentObject]->getRed() * currentLight.getRed();
	                    cor.green += lambert * objectList[currentObject]->getGreen() * currentLight.getGreen();
	                    cor.blue += lambert * objectList[currentObject]->getBlue() * currentLight.getBlue();

	                    Vector blinnDir = light.direction - raio.direction;
	                    double temp = blinnDir * blinnDir;


	                    if (temp != 0.0){
	                        double viewProjection = raio.direction * normal;
	                        double blinn;

	                        if(lightProj - viewProjection < 0){
	                            blinn = 0.0;
	                        }
	                        else{
	                            blinn = (1.0/sqrtf(temp)) * (lightProj - viewProjection);
                            
	                        }
	                        blinn = raio.getIntensity() * powf(blinn, objectList[currentObject]->getShininess());

	                        /*cor += (c * blinn * currentLight.intensity);**/
						
	                        cor.red += (blinn * objectList[currentObject]->getSpecular().red * currentLight.getIntensity());
	                        cor.green += (blinn * objectList[currentObject]->getSpecular().green * currentLight.getIntensity() );
	                        cor.blue += (blinn * objectList[currentObject]->getSpecular().blue * currentLight.getIntensity());
				
	                    }
	                } // end if shadow
				} else { // soft shadows
					r = currentLight.raio;
					for(teta=0.0; teta<360.0 ;teta+=10.0) {
						x = r *cos( teta*3.14158265/180.0); // converte para radianos
						use.x = x;
						use.y = 0.0;
						use.z = sqrtf(r*r - x*x);
						if(teta>180.0)
							use.z = -use.z;
						v = (currentLight.centre+use)-hitPoint;
						
						
						shadow = false;
						v = v*((v*v)*(1.0/sqrt(v*v))); // normalizar
						shadow_ray.start = hitPoint;
						
						shadow_ray.direction = v;
						for(l = 0;l < objectListSize; l++){
		                    t = lightDistance;
		                    if(currentObject != l && objectList[l]->intersection(shadow_ray,t)){
		                        shadow = true;
		                        break;
		                    }
		                }
						if(!shadow) {
							double lambert = light.direction * normal * raio.getIntensity();

		                    cor.red += lambert * objectList[currentObject]->getRed() * currentLight.getRed();
		                    cor.green += lambert * objectList[currentObject]->getGreen() * currentLight.getGreen();
		                    cor.blue += lambert * objectList[currentObject]->getBlue() * currentLight.getBlue();

		                    Vector blinnDir = light.direction- raio.direction;
		                    double temp = blinnDir * blinnDir;


		                    if (temp != 0.0){
		                        double viewProjection = raio.direction * normal;
		                        double blinn;

		                        if(lightProj - viewProjection < 0){
		                            blinn = 0.0;
		                        }
		                        else{
		                            blinn = (1.0/sqrtf(temp)) * (lightProj - viewProjection);

		                        }
		                        blinn = raio.getIntensity() * powf(blinn, objectList[currentObject]->getShininess());

		                        /*cor += (c * blinn * currentLight.intensity);**/

		                        cor.red += (blinn * objectList[currentObject]->getSpecular().red * currentLight.getIntensity());
		                        cor.green += (blinn * objectList[currentObject]->getSpecular().green * currentLight.getIntensity() );
		                        cor.blue += (blinn * objectList[currentObject]->getSpecular().blue * currentLight.getIntensity());

		                    }
						}
					}
					cor.red = cor.red/36.0;
					cor.green = cor.green/36.0;
					cor.blue = cor.blue/36.0;
				} // end if type light
            }

            /*double reflet = 2.0f*(raio.direction * normal);*/
            raio.start = hitPoint;
            raio.direction = raio.direction - (normal*(2*(raio.direction*normal)));
            raio.normalizar();
            raio.intensity = raio.intensity * objectList[currentObject]->getReflection();
        }
        level++;                
        if(currentObject == -1 || level == 10 || raio.intensity <= 0.00000001){
            saturation(cor);
            output[i][j].red += cor.red;
            output[i][j].green += cor.green;
            output[i][j].blue += cor.blue;
            break;
        }
    }
}

void createImage(int screenWidth, int screenHeight, Object **objectList, int objectListSize, Light *lightList, int lightListSize){

    int i, j, k, l;
    int shadow = false;
    Ray raio;
    Light currentLight;
    Point camera = {300,400,-1000};
    Point end;
    
    for (j = 0; j < screenHeight; j++) {
        for (i = 0; i < screenWidth; i++) {
            cor = 0.0f;
            
            /* Define plane projection with start and end point*/
            end.x = double(i)+ 0.5;
            end.y = double(j)+ 0.5;
			end.z = -500;
            
            raio.start = camera;
            raio.direction = end - camera;
            raio.normalizar();
            raio.intensity = 1.0;
			
			ray_trace(raio, 0, objectList, objectListSize, lightList, lightListSize, i, j, cor);
			
        }
    }
}


