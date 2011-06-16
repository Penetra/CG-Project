#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Object.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "Structures.hpp"
#include "Light.hpp"
#include "Wall.hpp"

using namespace std;

int screenWidth = 800;
int screenHeight = 600;

Object **objectList;
int objectListSize;

Light *lightList;
int lightListSize;

Colour output[800][600];

void createObjects() {

    objectListSize = 2;
    lightListSize = 1;
    
    objectList = new Object *[objectListSize];
    lightList = new Light [lightListSize];
    
    Sphere *sphere = new Sphere(400, 200, 300, 1.0, 0.0, 0.0, 100.0);

    (*sphere).setDiffuse(1.0, 0.0, 0.0);
    (*sphere).setReflection(0);
    (*sphere).setSpecular(1.0, 1.0, 1.0);
    (*sphere).setShininess(30.0);

    objectList[1] = sphere;
    
    /*sphere = new Sphere(400, 300, 100, 0.0, 0.0, 1.0, 50.0);

    (*sphere).setDiffuse(1.0, 1.0, 0.0);
    (*sphere).setReflection(0.5);
    (*sphere).setSpecular(1.0, 1.0, 1.0);
    (*sphere).setShininess(30.0);

    objectList[1] = sphere;*/


    /* Floor - centre, normal, colour **/
    Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

    (*floor).setSpecular(1.0, 1.0, 1.0);
    (*floor).setDiffuse(1.0, 1.0, 1.0);
    (*floor).setReflection(0.0);
    (*floor).setShininess(30.0);

    objectList[0] = floor;
    
    /*Wall *back = new Wall(0, 0, 500 , 0.0, 0.0, -1.0, 0.1, 0.1, 0.8);

    (*back).setSpecular(1.0, 1.0, 1.0);
    (*back).setDiffuse(0.1, 0.1, 0.8);
    (*back).setReflection(0.0);
    (*back).setShininess(50.0);

    objectList[1] = back;*/
    
    /*Wall *ola = new Wall(-1000, 0, 0 , 1.0, 0.0, 0.0, 0.5, 0.5, 0.8);

    (*ola).setSpecular(1.0, 1.0, 1.0);
    (*ola).setDiffuse(0.0, 0.0, 0.0);
    (*ola).setReflection(0.2);
    (*ola).setShininess(50.0);

    objectList[2] = ola;*/
    
    
    /*Back Wall - 
    Sphere *sphere = new Sphere(200.0,300.0, 500.0, 1.0, 0.0, 0.0, 100.0);
    (*sphere).setReflection(0.0);
    (*sphere).setShininess(50);
    (*sphere).setSpecular(1, 1, 1);
    (*sphere).setDiffuse(0.0, 0.0, 1.0);
    (*sphere).setRefraction(0.0);

    objectList[0] = sphere;
    
    Wall *front = new Wall(0, 0, 0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

    (*front).setSpecular(1.0, 1.0, 1.0);
    (*front).setDiffuse(1.0, 1.0, 1.0);
    (*front).setReflection(0.0);
    (*front).setShininess(20.0);

    objectList[1] = front;*/

    /* Lights*/
    lightList[0] = Light(400, 900.0, 300, 1.0, 1.0, 1.0, 1);
    /*lightList[0] = Light(300,10000,-6000, 1.0, 1, 1, 1);
    lightList[1] = Light(10000,400,200, 1.0, 1, 1, 1);*/
    

}

void display() {
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Apagar ]

    float *image = new float[800*600*3];
    int i,j;
    for(i=0;i< screenHeight; i++){
        for(j=0; j < screenWidth; j++ ){
            
            image[i*(screenWidth*3) + j*3] = output[j][i].red;
            image[i*(screenWidth*3) + j*3 + 1] = output[j][i].green;
            image[i*(screenWidth*3) + j*3 + 2] = output[j][i].blue;
        }
    }
    
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Writes a block of pixels to the framebuffer. */
    glDrawPixels(screenWidth,screenHeight,GL_RGB,GL_FLOAT, image);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Projecto RayTracing - {jpenetra,rjrocha}@student.dei.uc.pt");
    
    createObjects();   
    createImage(screenWidth, screenHeight, objectList, objectListSize, lightList, lightListSize);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();

    return 0;

}
