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

void createObjects() {

    objectListSize = 0;
    Sphere *sphere = new Sphere(233.0, 290.0, 0.0, 1.0, 1.0, 0.0, 100.0);

    (*sphere).setDiffuse(1.0, 1.0, 0.0);
    (*sphere).setReflection(0.5);
    (*sphere).setSpecular(1.0, 1.0, 1.0);
    (*sphere).setShininess(30.0);

    objectList[0] = sphere;

    objectListSize++;

    /* Floor - centre, normal, colour*/
    Wall *floor = new Wall(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0);

    (*floor).setSpecular(0.1, 0.1, 0.1);
    (*floor).setDiffuse(0.1, 0.1, 0.1);
    (*floor).setReflection(0.0);
    (*floor).setShininess(0.0);

    objectList[1] = floor;






}

void display() {
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Apagar ]
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Projecto RayTracing - {jpenetra,rjrocha}@student.dei.uc.pt");

    createObjects();

    createImage(screenWidth, screenHeight, objectList, objectListSize);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
