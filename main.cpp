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

<<<<<<< HEAD
    objectListSize = 2;
    lightListSize = 2;
=======
    objectListSize = 3;
    lightListSize = 1;
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4
    
    objectList = new Object *[objectListSize];
    lightList = new Light [lightListSize];
    if(false){
<<<<<<< HEAD
		Cylinder *cyl = new Cylinder(0.0, 0.0, 0, 0.0, 0.0, 1.0, 100.0, 100.0);
        (*cyl).setSpecular(1.0, 1.0, 1.0);
        (*cyl).setDiffuse(1.0, 1.0, 1.0);
        //(*cyl).setReflection(1.0);
		//(*cyl).setRefraction(1.0);
        (*cyl).setShininess(30.0);
        objectList[1] = cyl;
/*
		Sphere *sphere2 = new Sphere(0.0, 100.0, 0, 0.0, 0.0, 1.0, 100.0);

        (*sphere2).setDiffuse(0.0, 0.0, 0.0);
        //(*sphere).setReflection(1.0);
		//(*sphere).setRefraction(1.3);
        (*sphere2).setSpecular(1.0, 1.0, 1.0);
        (*sphere2).setShininess(30.0);

        objectList[3] = sphere2;
		Sphere *sphere = new Sphere(500.0, 300, 100, 0.5, 0.5, 0.5, 100.0);

        (*sphere).setDiffuse(0.0, 0.0, 0.0);
        (*sphere).setReflection(1.0);
		//(*sphere).setRefraction(1.0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(30.0);

        objectList[2] = sphere;
/*
		Sphere *sphere3 = new Sphere(200.0, 300, 100, 0.5, 0.5, 0.5, 100.0);

        (*sphere3).setDiffuse(0.0, 0.0, 0.0);
        (*sphere3).setReflection(1.0);
		//(*sphere).setRefraction(1.3);
        (*sphere3).setSpecular(1.0, 1.0, 1.0);
        (*sphere3).setShininess(30.0);

        objectList[3] = sphere3;
*/
		Cone *cone = new Cone(500.0, 0.0, 0, 0.0, 0.0, 1.0, 100.0, 200.0);
		(*cone).setSpecular(1.0, 1.0, 1.0);
        (*cone).setDiffuse(1.0, 1.0, 1.0);
        //(*cone).setReflection(1.0);
		//(*cone).setRefraction(1.0);
        (*cone).setShininess(30.0);
        objectList[2] = cone;
		
=======
        /*Sphere *sphere = new Sphere(500.0, 100, 100, 1.0, 0.0, 0.0, 100.0);

        (*sphere).setDiffuse(0.0, 0.0, 0.0);
        (*sphere).setReflection(0.0);
        (*sphere).setRefraction(0.0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(30.0);

        objectList[1] = sphere;*/
                
        Cylinder *cyl = new Cylinder(300.0, -50, 200, 0.0, 0.0, 1.0, 100.0, 100.0);
        (*cyl).setSpecular(1.0, 1.0, 1.0);
        (*cyl).setDiffuse(1.0, 0.0, 0.0);
        (*cyl).setReflection(0);
        (*cyl).setRefraction(0.0);
        (*cyl).setShininess(50.0);
        objectList[1] = cyl;
		

        
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
<<<<<<< HEAD
        //(*floor).setReflection(1.0);
		//(*floor).setRefraction(1.2);
=======
        (*floor).setReflection(0);
        (*floor).setRefraction(0.0);
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4
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
        
<<<<<<< HEAD
        /*lightList[0] = Light(300, 500.0, -100, 1.0, 1.0, 1.0, 1.0);
		lightList[0].type = 1;
		//lightList[0].raio = 50.0; */
		lightList[0] = Light(800, 500.0, 100, 1.0, 1.0, 1.0, 1.0);
    }
    else{
        lightList[0] = Light(220, 600.0, -200, 1.0, 1.0, 1.0, 1.0);
		lightList[0].type = 0;

		lightList[1] = Light(250, 0.0, -100, 1.0, 1.0, 1.0, 1.0);
		lightList[1].type = 0;

		Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 0.615, 0.384, 0.2588);

		(*floor).setSpecular(1.0, 1.0, 1.0);
		(*floor).setDiffuse(0.0, 0.0, 0.0);
		(*floor).setReflection(0.0);
		(*floor).setRefraction(0.0);
		(*floor).setShininess(30.0);
		(*floor).chess = false;

		objectList[1] = floor;

		Cylinder *cyl = new Cylinder(220.0, 0.0, 70.0, 0.0, 0.0, 1.0, 200.0, 200.0);
		(*cyl).setSpecular(1.0, 1.0, 1.0);
		(*cyl).setDiffuse(1.0, 0.0, 0.0);
		(*cyl).setReflection(0.0);
		(*cyl).setRefraction(0.0);
		(*cyl).setShininess(50.0);
		objectList[0] = cyl;
=======
        lightList[0] = Light(300, 1000.0, 200, 1.0, 1.0, 1.0, 1.0);
    }
    else{
        lightList[0] = Light(300, 1000.0, 500, 1.0, 1.0, 1.0, 1.0);
        
        /*Wall *board = new Wall(0, 1, 0 , 0.0, 1.0, 0.0, 0.0, 0.0, 0.0);

        (*board).setSpecular(0.0, 0.0, 0.0);
        (*board).setDiffuse(0.0, 0.0, 0.0);
        (*board).setReflection(0);
        (*board).setRefraction(0.0);
        (*board).setShininess(10.0);
        (*board).setChess(true);

        objectList[0] = board;
        
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 0.615, 0.384, 0.2588);
        
        (*floor).setSpecular(0.0, 0.0, 0.0);
        (*floor).setDiffuse(0.0, 0.0, 0.0);
        (*floor).setReflection(0.0);
        (*floor).setRefraction(0.0);
        (*floor).setShininess(30.0);
        (*floor).setChess(false);

        objectList[0] = floor;
         
         /*Cylinder *cyl = new Cylinder(0.0, 0, 200, 0.0, 0.0, 1.0, 100.0, 100.0);
        (*cyl).setSpecular(1.0, 1.0, 1.0);
        (*cyl).setDiffuse(1.0, 0.0, 0.0);
        (*cyl).setReflection(0);
        (*cyl).setRefraction(0.0);
        (*cyl).setShininess(50.0);
        objectList[1] = cyl;
        
        Sphere *s = new Sphere(450.0, 500, 100, 1.0, 0.0, 0.0, 50.0);
        (*s).setDiffuse(1.0, 0.0, 0.0);
        (*s).setReflection(0.0);
        (*s).setRefraction(0.0);
        (*s).setSpecular(1.0, 1.0, 1.0);
        (*s).setShininess(50.0);
        
        objectList[1] = s;       
        
        s = new Sphere(100.0, 100, 100, 1.0, 0.0, 0.0, 50.0);
        (*s).setDiffuse(1.0, 0.0, 0.0);
        (*s).setReflection(0.0);
        (*s).setRefraction(0.0);
        (*s).setSpecular(1.0, 1.0, 1.0);
        (*s).setShininess(50.0);
        
        objectList[3] = s;
        
        Sphere *sphere = new Sphere(300.0, 50, 100, 1.0, 0.0, 0.0, 50.0);
        (*sphere).setDiffuse(1.0, 0.0, 0.0);
        (*sphere).setReflection(0.0);
        (*sphere).setRefraction(0.0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(50.0);
        
        objectList[2] = sphere;
        
               
        /*Wall *back = new Wall(0, 0, 50000 , 0.0, 0.0, -1.0, 1.0, 1.0, 1.0);

        (*back).setSpecular(1.0, 1.0, 1.0);
        (*back).setDiffuse(1.0, 1.0, 1.0);
        (*back).setReflection(0);
        (*back).setShininess(10.0);
        (*back).setChess(false);
        
        objectList[2] = back;*/
        
        Cylinder *cyl = new Cylinder(0.0, 0.0, 0, 0.0, 0.0, 1.0, 100.0, 100.0);
        (*cyl).setSpecular(1.0, 1.0, 1.0);
        (*cyl).setDiffuse(1.0, 1.0, 1.0);
        (*cyl).setShininess(30.0);
        objectList[1] = cyl;

        Sphere *sphere = new Sphere(500.0, 300, 100, 0.5, 0.5, 0.5, 100.0);
        (*sphere).setDiffuse(0.0, 0.0, 0.0);
        (*sphere).setReflection(1.0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(30.0);

        objectList[2] = sphere;
        
        Wall *floor = new Wall(0, 0, 0 , 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(0.0, 0.0, 0.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        //(*floor).setReflection(1.0);
        //(*floor).setRefraction(1.2);
        (*floor).setShininess(30.0);
        //(*floor).chess = true;
        objectList[0] = floor;
>>>>>>> 03617a74474459ac05799d60ae967d782711dac4
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
    createImage(screenWidth, screenHeight);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}
