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
#include "Cylinder.hpp"
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
    if(true){
        /*
        Cylinder *cyl = new Cylinder(300.0, 0, 200, 0.0, 0.0, 1.0, 100.0, 100.0);
        (*cyl).setSpecular(1.0, 1.0, 1.0);
        (*cyl).setDiffuse(1.0, 0.0, 0.0);
        (*cyl).setReflection(0);
		(*cyl).setRefraction(1.2);
        (*cyl).setShininess(50.0);
        objectList[1] = cyl;
		*/
		Sphere *sphere = new Sphere(500.0, 200, 100, 1.0, 0.0, 0.0, 100.0);

        (*sphere).setDiffuse(1.0, 0.0, 0.0);
        (*sphere).setReflection(0.0);
		(*sphere).setRefraction(1.5);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(100.0);

        objectList[1] = sphere;
        
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        (*floor).setReflection(0);
        (*floor).setShininess(30.0);
		(*floor).chess = true;
        objectList[0] = floor;
		/*
		Wall *right = new Wall(0, 0, 1000 , 0.0, 0.0, -1.0, 1.0, 1.0, 1.0);

        (*right).setSpecular(1.0, 1.0, 1.0);
        (*right).setDiffuse(1.0, 1.0, 1.0);
        (*right).setReflection(0.0);
        (*right).setShininess(30.0);
        objectList[2] = right;
		*/
        
        lightList[0] = Light(300, 1000.0, 100, 1.0, 1.0, 1.0, 1.0);
    }
    else{
        Sphere *sphere = new Sphere(300.0, 200, 100, 1.0, 0.0, 0.0, 100.0);

        (*sphere).setDiffuse(1.0, 0.0, 0.0);
        (*sphere).setReflection(0.0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(100.0);

        objectList[1] = sphere;
        
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 0.5, 0.5, 0.5);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        (*floor).setReflection(0);
        (*floor).setShininess(10.0);
		(*floor).chess = true;
        objectList[0] = floor;
        
        
        lightList[0] = Light(300, 5000.0, 500, 1.0, 1.0, 1.0, 1.0);
    } 

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

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	//--------------------------- EXIT
	case 27:
		exit(0);
		break;
	}
	
	glutPostRedisplay();
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
	glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}
