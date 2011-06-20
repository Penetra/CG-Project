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
#include "Cone.hpp"
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
	int scene = 2;
	
	if(scene == 0){
		objectListSize = 8;
		lightListSize = 1;

	    objectList = new Object *[objectListSize];
	    lightList = new Light [lightListSize];
		
		Cylinder *cyl = new Cylinder(0.0, 0.0, 0, 0.0, 1.0, 0.0, 100.0, 100.0);
        (*cyl).setSpecular(0.0, 1.0, 0.0);
        (*cyl).setDiffuse(1.0, 1.0, 1.0);
        (*cyl).setReflection(0.0);
        (*cyl).setShininess(30.0);
        objectList[1] = cyl;
		
		Sphere *sphere3 = new Sphere(300.0, 100, 100, 0.5, 0.5, 0.5, 100.0);

        (*sphere3).setDiffuse(0.0, 0.0, 0.0);
        (*sphere3).setReflection(1.0);
        (*sphere3).setSpecular(1.0, 1.0, 1.0);
        (*sphere3).setShininess(30.0);

        objectList[3] = sphere3;

		Cone *cone = new Cone(500.0, 0.0, 0, 0.0, 0.0, 1.0, 100.0, 200.0);
		(*cone).setSpecular(1.0, 1.0, 1.0);
        (*cone).setDiffuse(1.0, 1.0, 1.0);
        (*cone).setShininess(30.0);
        objectList[2] = cone;
		
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        //(*floor).setReflection(1.0);
        (*floor).setShininess(30.0);
		(*floor).chess = false;
        objectList[0] = floor;
		
		
		Wall *right = new Wall(1000, 0, 0 , -1.0, 0.0, 0.0, 0.2, 0.2, 0.2);

        (*right).setSpecular(1.0, 1.0, 1.0);
        (*right).setDiffuse(1.0, 1.0, 1.0);
		(*right).setReflection(0.0);
		(*right).chess = false;
        (*right).setShininess(30.0);
        objectList[4] = right;

		Wall *left = new Wall(-400, 0, 0 , 1.0, 0.0, 0.0, 0.2, 0.2, 0.2);

        (*left).setSpecular(1.0, 1.0, 1.0);
        (*left).setDiffuse(1.0, 1.0, 1.0);
		(*left).setReflection(0.0);
		(*left).chess = false;
        (*left).setShininess(30.0);
        objectList[5] = left;
        
		Wall *hinten = new Wall(0, 0, 1000 , 0.0, 0.0, -1.0, 0.0, 0.0, 0.0);

        (*hinten).setSpecular(1.0, 1.0, 1.0);
        (*hinten).setDiffuse(1.0, 1.0, 1.0);
		(*hinten).setReflection(1.0);
		(*hinten).chess = false;
        (*hinten).setShininess(30.0);
        objectList[6] = hinten;

		Sphere *sphere4 = new Sphere(300.0, 800, 100, 0.5, 0.5, 0.5, 500.0);

        (*sphere4).setDiffuse(0.0, 0.0, 0.0);
        (*sphere4).setReflection(1.0);
        (*sphere4).setSpecular(1.0, 1.0, 1.0);
        (*sphere4).setShininess(30.0);

        objectList[7] = sphere4;
		
        lightList[0] = Light(300, 700.0, -500.0, 1.0, 1.0, 1.0, 1.0);
		lightList[0].type = 0;
		
	} else if (scene == 1) {
		objectListSize = 5;
		lightListSize = 1;

	    objectList = new Object *[objectListSize];
	    lightList = new Light [lightListSize];
		
		Cylinder *cyl = new Cylinder(0.0, 0.0, 0, 0.0, 1.0, 0.0, 100.0, 100.0);
        (*cyl).setSpecular(0.0, 1.0, 0.0);
        (*cyl).setDiffuse(1.0, 1.0, 1.0);
        (*cyl).setReflection(0.0);
        (*cyl).setShininess(30.0);
        objectList[1] = cyl;
		
		Sphere *sphere3 = new Sphere(300.0, 100, 100, 0.0, 0.0, 0.0, 100.0);

        (*sphere3).setDiffuse(0.0, 0.0, 0.0);
        (*sphere3).setReflection(1.0);
        (*sphere3).setSpecular(1.0, 1.0, 1.0);
        (*sphere3).setShininess(30.0);

        objectList[3] = sphere3;

		Cone *cone = new Cone(500.0, 0.0, 0, 0.0, 0.0, 1.0, 100.0, 200.0);
		(*cone).setSpecular(1.0, 1.0, 1.0);
		(*cone).setDiffuse(1.0, 1.0, 1.0);
		(*cone).setShininess(30.0);
		//(*cone).setReflection(1.0);
        objectList[2] = cone;

		Sphere *sphere4 = new Sphere(800.0, 100, 100, 0.5, 0.5, 0.5, 100.0);

        (*sphere4).setDiffuse(0.0, 0.0, 0.0);
        (*sphere4).setReflection(1.0);
        (*sphere4).setSpecular(1.0, 1.0, 1.0);
        (*sphere4).setShininess(30.0);

        objectList[4] = sphere4;
		
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 0.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        //(*floor).setReflection(1.0);
        (*floor).setShininess(30.0);
		(*floor).chess = false;
        objectList[0] = floor;
		
        lightList[0] = Light(300, 700.0, -500.0, 1.0, 1.0, 1.0, 1.0);
		lightList[0].type = 1;
		lightList[0].raio = 50;
	} else if (scene == 2) {
		objectListSize = 7;
		lightListSize = 1;

	    objectList = new Object *[objectListSize];
	    lightList = new Light [lightListSize];
		
		Cylinder *cyl = new Cylinder(400.0, 0.0, -100, 1.0, 1.0, 0.0, 100.0, 100.0);
        (*cyl).setSpecular(0.0, 1.0, 0.0);
        (*cyl).setDiffuse(1.0, 1.0, 1.0);
        //(*cyl).setReflection(1.0);
        (*cyl).setShininess(30.0);
        objectList[1] = cyl;

		Cone *cone = new Cone(800.0, 0.0, -100.0, 0.0, 0.0, 1.0, 100.0, 200.0);
		(*cone).setSpecular(1.0, 1.0, 1.0);
		(*cone).setDiffuse(1.0, 1.0, 1.0);
		(*cone).setShininess(30.0);
		//(*cone).setReflection(1.0);
        objectList[6] = cone;
		
		Sphere *sphere3 = new Sphere(400.0, 100, 100, 0.0, 0.0, 0.0, 100.0);

        (*sphere3).setDiffuse(0.0, 0.0, 0.0);
        (*sphere3).setReflection(1.0);
        (*sphere3).setSpecular(1.0, 1.0, 1.0);
        (*sphere3).setShininess(30.0);

        objectList[2] = sphere3;
		
		Sphere *sphere4 = new Sphere(800.0, 100, 100, 0.2, 0.2, 0.2, 100.0);

        (*sphere4).setDiffuse(0.0, 0.0, 0.0);
        (*sphere4).setReflection(1.0);
        (*sphere4).setSpecular(1.0, 1.0, 1.0);
        (*sphere4).setShininess(30.0);

        objectList[3] = sphere4;

		Sphere *sphere5 = new Sphere(0.0, 100, 100, 0.0, 0.0, 0.0, 100.0);

        (*sphere5).setDiffuse(0.0, 0.0, 0.0);
        (*sphere5).setReflection(1.0);
        (*sphere5).setSpecular(1.0, 1.0, 1.0);
        (*sphere5).setShininess(30.0);

        objectList[4] = sphere5;

		Sphere *sphere6 = new Sphere(0.0, 100, -200, 1.0, 0.0, 0.0, 100.0);

        (*sphere6).setDiffuse(0.0, 0.0, 0.0);
        (*sphere6).setSpecular(1.0, 1.0, 1.0);
        (*sphere6).setShininess(30.0);

        objectList[5] = sphere6;
		
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        //(*floor).setReflection(1.0);
        (*floor).setShininess(30.0);
		(*floor).chess = true;
        objectList[0] = floor;
		
        lightList[0] = Light(300, 700.0, -500.0, 1.0, 1.0, 1.0, 1.0);
		lightList[0].type = 0;
		//lightList[0].raio = 50;
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
