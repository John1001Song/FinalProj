//
//  snowMan.cpp
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

#include "snowMan.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cols[6][3] = { {1,0,0}, {0,1,1}, {1,1,0}, {0,1,0}, {0,0,1}, {1,0,1} };
float pos[] = {0,1,0};
float rot[] = {0, 0, 0};
float headRot[] = {0, 0, 0};

float size;

/* drawPolygon - takes 4 indices and an array of vertices
 *   and draws a polygon using the vertices indexed by the indices
 */
void drawPolygon(int a, int b, int c, int d, float v[8][3]){
    glBegin(GL_POLYGON);
    glVertex3fv(v[a]);
    glVertex3fv(v[b]);
    glVertex3fv(v[c]);
    glVertex3fv(v[d]);
    glEnd();
}


/* cube - takes an array of 8 vertices, and draws 6 faces
 *  with drawPolygon, making up a box
 */
void cube(float v[8][3])
{
    glColor3fv(cols[1]);
    drawPolygon(0, 3, 2, 1, v);
    
    glColor3fv(cols[2]);
    drawPolygon(1, 0, 4, 5, v);
    
    glColor3fv(cols[3]);
    drawPolygon(5, 1, 2, 6, v);
    
    glColor3fv(cols[4]);
    drawPolygon(2, 3, 7, 6, v);
    
    glColor3fv(cols[5]);
    drawPolygon(6, 5, 4, 7, v);
    
    glColor3fv(cols[0]);
    drawPolygon(4, 0, 3, 7, v);
}

void DrawSnowman(float* pos, float* rot)
{
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glRotatef(rot[1], 0, 1, 0);
    
    //draw body
    glColor3f(1,1,1);
    glutSolidSphere(size, 16, 16);
    
    //draw buttons
    glPushMatrix();
    glTranslatef(0, 0.35, 0.95);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.15, 0.95);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -0.05, 0.95);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    
    glPushMatrix();
    //translate relative to body, and draw head
    glTranslatef(0, 1.25, 0);
    //glTranslatef(*sin(headRot[1]), .5, 0);
    glRotatef(headRot[1], 3, 3, 3); //turn the head relative to the body
    glColor3f(1,1,1);
    glutSolidSphere(size/2, 16, 16);
    
    //translate and draw right eye
    glPushMatrix();
    glTranslatef(0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(size/10, 10, 10);
    glPopMatrix();
    
    //translate and draw left eye
    glPushMatrix();
    glTranslatef(-0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(size/8, 10, 10);
    glPopMatrix();
    
    //translate and draw nose
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glColor3f(1,0.4,0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    glPopMatrix();//body
    glPopMatrix();//snowman
}

SnowMan::SnowMan(ManType whatType){
    setType(man);
    manType = whatType;
}

void SnowMan::draw(){
    switch (manType) {
        case smallAI:
            size = 1;
            DrawSnowman(getPos(), rot);
            break;
            
        case mediumAI:
            size = 2;
            DrawSnowman(getPos(), rot);
            break;
            
        case largeAI:
            size = 3;
            DrawSnowman(getPos(), rot);
            break;
            
        case player:
            size = 1;
            DrawSnowman(getPos(), rot);
            break;
            
        default:
            break;
    }
}

void SnowMan::fire(){
    
}

