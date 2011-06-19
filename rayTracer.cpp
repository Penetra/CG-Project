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
extern Object **objectList;
extern int objectListSize;
extern Light *lightList;
extern int lightListSize;


void saturation(Colour &cor){
    if(cor.red > 1.0)
        cor.red = 1.0;
    if(cor.green > 1.0)
        cor.green = 1.0;
    if(cor.blue > 1.0)
        cor.blue = 1.0;
}

void ray_trace(Ray raio, int level,int i, int j, Colour cor) {
	int currentObject;
	int k,l,m;
	int shadow;
	Light currentLight;
	
	while(level < 10){
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

                    if(objectList[currentObject]->refractionDirection(refraction_ray, hitPoint, normal)) {
                        refraction_ray.intensity = raio.intensity*objectList[currentObject]->getRefraction();
                        ray_trace(refraction_ray, level+1, i, j, cor);
                    }
                }

                Ray light;
                light.start = hitPoint;

                for(m=0; m < lightListSize; m++){

                    currentLight = lightList[m];

                    /*Define the direction to the light*/
                    light.direction = currentLight.centre - hitPoint;

                    
                    if(normal * light.direction < 0.00000001)
                        continue;
                    
                    light.normalizar();

                    /* We need to know if there's any object between our intersection point and the light**/

                    shadow = false;
                    
                    for(l = 0;l < objectListSize; l++){
                        if(currentObject != l && objectList[l]->intersection(light,t) ){
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
                            double lightProj = light.direction * normal;
                            double blinn;

                            
                            blinn = 1.0/sqrtf(temp) * max(lightProj - viewProjection , 0.0);
                            blinn = raio.getIntensity() * powf(blinn, objectList[currentObject]->getShininess());
                            
                            cor.red += (blinn * objectList[currentObject]->getSpecular().red * currentLight.getIntensity());
                            cor.green += (blinn * objectList[currentObject]->getSpecular().green * currentLight.getIntensity() );
                            cor.blue += (blinn * objectList[currentObject]->getSpecular().blue * currentLight.getIntensity());
                        }

                    }
                }

                /*double reflet = 2.0f*(raio.direction * normal);*/
                raio.start = hitPoint;
                raio.direction = raio.direction - (normal*(2*(raio.direction*normal)));
                raio.normalizar();
                raio.intensity = raio.intensity * objectList[currentObject]->getReflection();
            }
            level++;                
            if(currentObject == -1 || level == 3 || raio.intensity <= 0.00000001){
                saturation(cor);
                output[i][j].red += cor.red;
                output[i][j].green += cor.green;
                output[i][j].blue += cor.blue;
                cor = 0.0f;
                break;
            }
        }
}

void createImage(int screenWidth, int screenHeight){

    int i, j;
    Colour cor;
    Ray raio;
    //Point camera = {100,700,-700};
     Point camera = {280,700,-700};
    Point end;
    
    raio.start = camera;
    
    for (j = 0; j < screenHeight; j++) {
        for (i = 0; i < screenWidth; i++) {
            cor = 0.0f;
            
            /* Define plane projection with start and end point*/
            end.x = double(i)+ 0.5;
            end.y = double(j)+ 0.5;
            end.z = 0;
            
            raio.direction = end - camera;
            
            raio.normalizar();
            raio.intensity = 1.0;
			
            ray_trace(raio, 0,i, j, cor);
			
        }
    }
}


