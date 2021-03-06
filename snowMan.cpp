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
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float cols[6][3] = { {1,0,0}, {0,1,1}, {1,1,0}, {0,1,0}, {0,0,1}, {1,0,1} };
float AI_pos[] = {2,1,-3};
float AI_rot[] = {0, 0, 0};
float headRot[] = {0, 0, 0};

float size;


void SnowMan::DrawSnowman(float* pos, float angle)
{
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glRotatef(angle, 0, 1, 0);
    
    //draw body
    glColor3f(1,1,1); // color for body
    glutSolidSphere(1, 16, 16);
    //glScalef(2, 1, 1);
    
    // left arm
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.9);
    glScalef(0.25, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix(); // left wing
    
    // right arm
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0.9);
    glScalef(0.25, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix(); // right wing
    
    //draw buttons
    glPushMatrix();
    glTranslatef(0, 0.35, 0.9);
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
    glRotatef(headRot[1], 0, 1, 0); //turn the head relative to the body
    glColor3f(1,1,1);
    glutSolidSphere(0.5, 16, 16);
    
    //translate and draw right eye
    glPushMatrix();
    glTranslatef(0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    //translate and draw left eye
    glPushMatrix();
    glTranslatef(-0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
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

void DrawSmallSnowman(float* pos, float* rot)
{
    glPushMatrix();
    
    glTranslatef(AI_pos[0], AI_pos[1], AI_pos[2]);
    glRotatef(AI_rot[1], 0, 1, 0);
    
    //draw body
    glColor3f(1,1,1); // color for body
    glutSolidSphere(1, 16, 16);
    glScalef(1, 1, 1);
    
    // left arm
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.9);
    glScalef(0.1, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    
    // right arm
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0.9);
    glScalef(0.1, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    
    //draw buttons
    glPushMatrix();
    glTranslatef(0, 0.35, 0.9);
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
    glRotatef(headRot[1], 0, 1, 0); //turn the head relative to the body
    glColor3f(1,1,1);
    glutSolidSphere(0.5, 16, 16);
    
    //translate and draw right eye
    glPushMatrix();
    glTranslatef(0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    //translate and draw left eye
    glPushMatrix();
    glTranslatef(-0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
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

void DrawBigSnowman(float* pos, float* rot)
{
    glPushMatrix();
    
    glTranslatef(AI_pos[0]-6, AI_pos[1], AI_pos[2]-2);
    glRotatef(AI_rot[1], 0, 1, 0);
    
    //draw body
    glColor3f(1,1,1); // color for body
    glutSolidSphere(1, 16, 16);
    glScalef(0.5, 1, 1);
    
    // left arm
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.9);
    glScalef(0.1, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    
    // right arm
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0.9);
    glScalef(0.1, 1, 1);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    
    //draw buttons
    glPushMatrix();
    glTranslatef(0, 0.35, 0.9);
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
    glRotatef(headRot[1], 0, 1, 0); //turn the head relative to the body
    glColor3f(1,1,1);
    glutSolidSphere(0.5, 16, 16);
    glScalef(0.5, 1, 1);
    
    //translate and draw right eye
    glPushMatrix();
    glTranslatef(0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    //translate and draw left eye
    glPushMatrix();
    glTranslatef(-0.2, 0.15, 0.45);
    glColor3f(0,0,0);
    glutSolidSphere(0.1, 10, 10);
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


//caution: how could i initial the Snowman and set it type "man" when it inherits from Snow

SnowMan::SnowMan(ManType whatType){
    snowType = man;
    manType = whatType;
}

SnowMan::SnowMan(){
    //this random func is used for creating a random AI in the scene
    srand(time(NULL));
    pos[0] = rand() % 20;
    pos[1] = 0;
    pos[2] = rand() % 30;
    
    setSize(rand() % 3);
    
    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    
    angle = rand() % 180;
}

void SnowMan::draw(){
    switch (manType) {
        case smallAI:
            setSize(1.0);
            //DrawSmallSnowman(getPos(), rot);
            break;
            
        case mediumAI:
            setSize(2.0);
            DrawSnowman(getPos(), getAngle());
            break;
            
        case largeAI:
            setSize(3.0);
            //DrawBigSnowman(getPos(), rot);
            break;
            
        case player:
            setSize(1.0);
            //DrawSnowman(getPos(), getAngle());
            break;
            
        default:
            break;
    }
}

SnowMan::~SnowMan(){

}

void SnowMan::fire(){
    
}

void SnowMan::update(){
    float tempSpeed = getSpeed();
    float tempDir[3] = {getDir()[0], getDir()[1], getDir()[2]};
    float tempPos[3] = {getPos()[0], getPos()[1], getPos()[2]};
    
    tempPos[0] = tempPos[0] + tempSpeed * tempDir[0];
    tempPos[1] = tempPos[1] + tempSpeed * tempDir[1];
    tempPos[2] = tempPos[2] + tempSpeed * tempDir[2];
    
    setPos(tempPos);
}

float SnowMan::getAngle(){
    return angle;
}

void SnowMan::setAngle(float angle1){
    angle = angle1;
    setDirInAngle(angle);
}

void SnowMan::setDirInAngle(float someAngle){
    float thisAngle = someAngle * 3.14 / 180;
    
    float tempDir[3] = {getDir()[0], getDir()[1], getDir()[2]};
    tempDir[0] = -cosf(thisAngle);
    tempDir[2] = sinf(thisAngle);
    
    setDir(tempDir);
}

float SnowMan::transfAngToNumb(float angle){
    float tempResult = angle * 3.1415926 / 180;
    return tempResult;
}

