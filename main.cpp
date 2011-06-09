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

    objectListSize = 3;
    lightListSize = 1;
    
    objectList = new Object *[objectListSize];
    lightList = new Light [lightListSize];
    
    Sphere *sphere = new Sphere(100, 300, 100, 1.0, 0.0, 0.0, 50.0);

    (*sphere).setDiffuse(1.0, 1.0, 0.0);
    (*sphere).setReflection(0.5);
    (*sphere).setSpecular(1.0, 1.0, 1.0);
    (*sphere).setShininess(30.0);

    objectList[0] = sphere;
    
    sphere = new Sphere(400, 300, 100, 1.0, 0.0, 0.0, 50.0);

    (*sphere).setDiffuse(1.0, 1.0, 0.0);
    (*sphere).setReflection(0.5);
    (*sphere).setSpecular(1.0, 1.0, 1.0);
    (*sphere).setShininess(30.0);

    objectList[1] = sphere;


    /* Floor - centre, normal, colour**/
    Wall *floor = new Wall(0.0, 800.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

    (*floor).setSpecular(1.0, 1.0, 1.0);
    (*floor).setDiffuse(1.0, 1.0, 1.0);
    (*floor).setReflection(0.5);
    (*floor).setShininess(30.0);

    objectList[2] = floor;
    
    
    /*Front Wall - 
    Wall *front = new Wall(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 1.0, 1.0);

    (*front).setSpecular(0.1, 0.1, 0.1);
    (*front).setDiffuse(0.1, 0.1, 0.1);
    (*front).setReflection(0.0);
    (*front).setShininess(0.0);

    objectList[2] = front;*/

    /* Lights*/
    
    lightList[0] = Light(200, 000.0, 100, 1.0, 1.0, 1.0, 1);
    

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
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Projecto RayTracing - {jpenetra,rjrocha}@student.dei.uc.pt");
    createObjects();

    createImage(screenWidth, screenHeight, objectList, objectListSize, lightList, lightListSize);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
