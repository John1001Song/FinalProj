//
//  main.cpp
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include "structs.h"
#include "snowMan.h"
#include "snowBall.h"
#include "snow.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

float camPos[] = {5, 5, 10};

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
            break;
            
        default:
            break;
    }
    
    glutPostRedisplay();
}

void special(int key, int x, int y){}

void mouse(int button, int state, int x, int y){}

void init(){
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
}

void display(){
    float origin[3] = {0, 0, 0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
    glColor3f(1, 1, 1);
    
    glutSwapBuffers();
}

int main(int argc, char ** argv){
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    
    glutCreateWindow("Snowman fighting");
    
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    
    init();
    
    glutMainLoop();
    return (0);
    
}