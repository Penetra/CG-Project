#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>

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


Object **objectList;
int objectListSize;

Light *lightList;
int lightListSize;

Colour output[screenWidth][screenHeight];

void createObjects(int scene) {
    
    
    if(scene == 1){
        /* CHESS BOARD CHECKERS*/
        objectListSize = 26;
        lightListSize = 1;

        objectList = new Object *[objectListSize];
        lightList = new Light [lightListSize];

        lightList[0] = Light(325, 800.0, 200, 1.0, 1.0, 1.0, 1.0);
        lightList[0].type = 0;


        Wall *floor = new Wall(0, 0, 0, 0.0, 1.0, 0.0, 0.615, 0.384, 0.2588);

        (*floor).setSpecular(0.0, 0.0, 0.0);
        (*floor).setDiffuse(0.615, 0.384, 0.2588);
        (*floor).setReflection(0.0);
        (*floor).setRefraction(0.0);
        (*floor).setShininess(30.0);
        (*floor).chess = false;

        objectList[0] = floor;

        Wall *board = new Wall(-150, 1, 0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0);

        (*board).setSpecular(0.0, 0.0, 0.0);
        (*board).setDiffuse(0, 0, 0);
        (*board).setReflection(0.0);
        (*board).setRefraction(0.0);
        (*board).setShininess(30.0);
        (*board).chess = true;
        (*board).limited = true;
        (*board).numberOfSquares = 8;

        objectList[1] = board;


        int i;
        Cylinder *cyl;
        for(i=0; i<4; i++){
            cyl = new Cylinder(-75.0 + (i*300), 2.0, 75.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[2+i] = cyl;
        }
        for(i=0; i<4; i++){
            cyl = new Cylinder(75.0 + (i*300), 2.0, 225.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[6+i] = cyl;
        }
        for(i=0; i<4; i++){
            cyl = new Cylinder(-75.0 + (i*300), 2.0, 375.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[10+i] = cyl;
        }

        Cylinder *cylinder1;
        for(i=0; i < 4; i++){
            cylinder1 = new Cylinder(75.0 + (i*300), 2.0, 1125.0, 0.3, 0.3, 0.3, 50.0, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[14+i] = cylinder1;
        }
        for(i=0; i < 4; i++){
            cylinder1 = new Cylinder(-75.0 + (i*300), 2.0, 975.0, 0.3, 0.3, 0.3, 50.0, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[18+i] = cylinder1;
        }

        for(i=0; i < 4; i++){
            cylinder1 = new Cylinder(75.0 + (i*300), 2.0, 825.0, 0.3, 0.3, 0.3, 50.0, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[22+i] = cylinder1;
        }
    }
    else if(scene == 2){
        objectListSize = 26;
        lightListSize = 3;

        objectList = new Object *[objectListSize];
        lightList = new Light [lightListSize];

        lightList[0] = Light(325, 300.0, -6100, 1.0, 1.0, 1.0, 1.0);
        lightList[0].type = 0;
        
        lightList[1] = Light(325, 1000.0, 400, 1.0, 1.0, 1.0, 1.0);
        lightList[1].type = 0;
        
        lightList[2] = Light(325, 300.0, 6100, 1.0, 1.0, 1.0, 1.0);
        lightList[2].type = 0;


        Wall *floor = new Wall(0, 0, 0, 0.0, 1.0, 0.0, 0.615, 0.384, 0.2588);

        (*floor).setSpecular(0.0, 0.0, 0.0);
        (*floor).setDiffuse(0.615, 0.384, 0.2588);
        (*floor).setReflection(0.0);
        (*floor).setRefraction(0.0);
        (*floor).setShininess(30.0);
        (*floor).chess = false;

        objectList[0] = floor;

        Wall *board = new Wall(-150, 1, 0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0);

        (*board).setSpecular(0.0, 0.0, 0.0);
        (*board).setDiffuse(0, 0, 0);
        (*board).setReflection(0.0);
        (*board).setRefraction(0.0);
        (*board).setShininess(30.0);
        (*board).chess = true;
        (*board).limited = true;
        (*board).numberOfSquares = 8;

        objectList[1] = board;

        int i;
        Sphere *cyl;
        for(i=0; i<4; i++){
            cyl = new Sphere(-75.0 + (i*300), 50.0, 75.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0);//, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[2+i] = cyl;
        }
        for(i=0; i<4; i++){
            cyl = new Sphere(75.0 + (i*300), 50.0, 225.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0);//, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[6+i] = cyl;
        }
        for(i=0; i<4; i++){
            cyl = new Sphere(-75.0 + (i*300), 50.0, 375.0, 239.0/255.0, 228.0/255.0, 176.0/255.0, 50.0);//, 25.0);
            (*cyl).setSpecular(1.0, 1.0, 1.0);
            (*cyl).setDiffuse(0.0, 0.0, 1.0);
            (*cyl).setReflection(0.0);
            (*cyl).setRefraction(0.0);
            (*cyl).setShininess(50.0);
            objectList[10+i] = cyl;
        }

        Sphere *cylinder1;
        for(i=0; i < 4; i++){
            cylinder1 = new Sphere(75.0 + (i*300), 50.0, 1125.0, 0.3, 0.3, 0.3, 50.0);//, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[14+i] = cylinder1;
        }
        for(i=0; i < 4; i++){
            cylinder1 = new Sphere(-75.0 + (i*300), 50.0, 975.0, 0.3, 0.3, 0.3, 50.0);//, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[18+i] = cylinder1;
        }

        for(i=0; i < 4; i++){
            cylinder1 = new Sphere(75.0 + (i*300), 50.0, 825.0, 0.3, 0.3, 0.3, 50.0);//, 25.0);
            (*cylinder1).setSpecular(1.0, 1.0, 1.0);
            (*cylinder1).setDiffuse(0.0, 0.0, 1.0);
            (*cylinder1).setReflection(0.0);
            (*cylinder1).setRefraction(0.0);
            (*cylinder1).setShininess(50.0);
            objectList[22+i] = cylinder1;
        }
        
    }
    if(scene == 3){
        
        objectListSize = 2;
        lightListSize = 1;

        objectList = new Object *[objectListSize];
        lightList = new Light [lightListSize];

        lightList[0] = Light(400, 100.0, -6100, 1.0, 1.0, 1.0, 1.0);
        lightList[0].type = 0;
        
        
        Sphere *sphere = new Sphere(300, 200, 100, 1.0, 0.0, 0.0, 100.0);

        (*sphere).setDiffuse(1.0, 0.0, 0.0);
        (*sphere).setReflection(0);
        (*sphere).setSpecular(1.0, 1.0, 1.0);
        (*sphere).setShininess(50.0);

        objectList[0] = sphere;
        
        Wall *floor = new Wall(0, 0, 1000 , 0.0, 0.0, -1.0, 1.0, 1.0, 1.0);

        (*floor).setSpecular(1.0, 1.0, 1.0);
        (*floor).setDiffuse(1.0, 1.0, 1.0);
        (*floor).setReflection(0);
        (*floor).setShininess(50.0);

        objectList[1] = floor;

    }

}

void display() {
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Apagar ]
    float *image = new float[screenWidth * screenHeight * 3];
    int i, j;
    for (i = 0; i < screenHeight; i++) {
        for (j = 0; j < screenWidth; j++) {

            image[i * (screenWidth * 3) + j * 3] = output[j][i].red;
            image[i * (screenWidth * 3) + j * 3 + 1] = output[j][i].green;
            image[i * (screenWidth * 3) + j * 3 + 2] = output[j][i].blue;
        }
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Writes a block of pixels to the framebuffer. */
    glDrawPixels(screenWidth, screenHeight, GL_RGB, GL_FLOAT, image);
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

    createObjects(2);
    createImage(objectList, objectListSize, lightList, lightListSize);
    
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;

}
