#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#include "Structures.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Light.hpp"

extern Colour output[800][600];

void createImage(int screenWidth, int screenHeight, Object **objectList, int objectListSize, Light *lightList, int lightListSize){

    int i, j, k, l;
    int level, currentObject;
    int shadow = false;
    Colour cor;
    Ray raio;


    
    for (j = 0; j < screenHeight; j++) {
        for (i = 0; i < screenWidth; i++) {
            cor = 0.0f;
            raio.start.x = double(j);
            raio.start.y = double(i);
            raio.start.z = -1000.0;

            raio.direction.x = 0.0;
            raio.direction.y = 0.0;
            raio.direction.z = 1.0;
            raio.intensity = 1.0;

            level = 0;

            do{

                Point hitPoint;
                currentObject = -1;

                double t, minDistance = -1;
                for (k = 0; k < objectListSize; k++) {
                    if(objectList[k]->intersection(raio, t)){
                        
                        if( t < minDistance || minDistance ==-1){
                            minDistance = t;
                            currentObject = k;
                        }
                        
                    }
                }
                /* No intersections found*/
                if(currentObject != -1){
                
                
                    hitPoint = raio.start + (raio.direction * minDistance); 
                    /* Calculate Normal on the intersection point*/
                    Vector normal = hitPoint - objectList[currentObject]->centre;

                    double temp = normal * normal;
                    if (temp == 0.0f)
                            break;
                    temp = 1.0f / sqrtf(temp);
                    normal = normal * temp;

                    /* Check if any light hits the intersection point**/
                    Ray light;
                    light.start = hitPoint;

                    for(k=0;k < lightListSize; k++){

                        Light currentLight = lightList[k];

                        light.direction = currentLight.centre - hitPoint;
                        double lightProj = light.direction * normal;

                        if(lightProj <= 0.0f)
                            continue;

                        double lightDistance = light.direction * light.direction;

                        if(lightDistance == 0.0f)
                            continue;

                        temp = 1.0f/sqrtf(lightDistance);
                        light.direction = light.direction * temp;
                        lightProj = temp * lightProj;

                        /* We need to know if there's any object between our intersection point and the light**/

                        t = lightDistance;
                        shadow = false;

                        for(l = 0;l < objectListSize; l++){
                            if(objectList[l]->intersection(light,t)){
                                shadow = true;
                                break;
                            }
                        }


                        if(!shadow){
                            double lambert = (light.direction * normal) * raio.getIntensity();
                            /*double lambert = (light.direction * normal);*/
                            cor.red += lambert * objectList[currentObject]->getRed() * currentLight.getRed();
                            cor.green += lambert * objectList[currentObject]->getGreen() * currentLight.getGreen();
                            cor.blue += lambert * objectList[currentObject]->getBlue() * currentLight.getBlue();


                            Vector blinnDir = light.direction - raio.direction;
                            double temp = blinnDir * blinnDir;


                            if (temp != 0.0f) {
                                double viewProjection = raio.direction * normal;
                                double blinn;

                                if(lightProj - viewProjection < 0){
                                    blinn = 0.0;
                                    blinn = raio.getIntensity() * powf(blinn, objectList[currentObject]->getShininess());
                                }
                                else{
                                    blinn = 1.0/sqrtf(temp) * (lightProj - viewProjection);
                                    blinn = raio.getIntensity() * powf(blinn, objectList[currentObject]->getShininess());
                                }

                                /*cor += (c * blinn * currentLight.intensity);**/
                                cor.red += (blinn * objectList[currentObject]->getSpecular().red * currentLight.getIntensity());
                                cor.green += (blinn * objectList[currentObject]->getSpecular().green * currentLight.getIntensity() );
                                cor.blue += (blinn * objectList[currentObject]->getSpecular().blue * currentLight.getIntensity());
                            }

                        }   
                    }

                    /*reflection *= 0.5;*/

                    double reflet = 2.0f*(raio.direction * normal);
                    raio.start = hitPoint;
                    raio.direction = raio.direction - (normal * reflet);
                    raio.direction = raio.direction * (1.0/(sqrtf( raio.direction * raio.direction)));
                    raio.intensity = raio.intensity * objectList[currentObject]->getReflection();
                }
                
                if(currentObject == -1 || level == 10 || raio.intensity <= 0.00000001){
                        output[j][i].red += cor.red;
                        output[j][i].green += cor.green;
                        output[j][i].blue += cor.blue;
                        break;
                } 
                level++;
            }while (level < 10 );
           
        }

    }
    
    /*for(j=0; j < screenHeight; j++) {
        printf("%.3f\n", output[j][0]);
    }*/

}


