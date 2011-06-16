#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#include "Structures.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Light.hpp"

extern Colour output[800][600];

void saturation(Colour &cor){
    if(cor.red > 1.0)
        cor.red = 1.0;
    if(cor.green > 1.0)
        cor.green = 1.0;
    if(cor.blue > 1.0)
        cor.blue = 1.0;
}

void createImage(int screenWidth, int screenHeight, Object **objectList, int objectListSize, Light *lightList, int lightListSize){

    int i, j, k, l;
    int level, currentObject;
    int shadow = false;
    Colour cor;
    Ray raio;
    Light currentLight;
    Point camera = {400,10000,500};
    Point end;
    
    for (j = 0; j < screenHeight; j++) {
        for (i = 0; i < screenWidth; i++) {
            cor = 0.0f;
            
            /* Define plane projection with start and end point*/
            end.x = double(i)+ 0.5;
            end.y = 3000;
            end.z = double(j)+ 0.5;
            
            raio.start = camera;
            raio.direction = end - camera;
            raio.normalizar();
            raio.intensity = 1.0;           

            level = 0;

            do{

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
                    if(currentObject==1)
                        normal = hitPoint - objectList[currentObject]->centre;
                    if(currentObject==0){
                        normal.x = 0.0;
                        normal.y = 1.0;
                        normal.z = 0.0;
                    }
                    double temp = normal * normal;
                    if (temp == 0.0f){
                        break;
                    }
                    temp = 1.0f / sqrtf(temp);
                    normal = normal * temp;
                    /* Check if any light hits the intersection point**/
                    Ray light;
                    light.start = hitPoint;

                    for(k=0;k < lightListSize; k++){

                        currentLight = lightList[k];
                        
                        /*Define the direction to the light*/
                        light.direction = currentLight.centre - hitPoint;
                        
                        double lightDistance = light.direction * light.direction;
                        
                        if(lightDistance == 0.0f)
                            continue;

                        temp = 1.0f/sqrtf(lightDistance);
                        
                        light.direction = light.direction * temp;
                        
                        double lightProj = light.direction * normal;

                        /* We need to know if there's any object between our intersection point and the light**/

                        shadow = false;
                        for(l = 0;l < objectListSize; l++){
                            t = lightDistance;
                            if(objectList[l]->intersection(light,t) && k != l){
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

                        }
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
            }while (level < 10 );  
        }
    }
}


