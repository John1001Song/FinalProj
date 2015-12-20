//
//  snowBall.cpp
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

#include "snowBall.h"
#include "snow.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

SnowBall::SnowBall() : Snow() {
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    time = 2000;
    size = 1;
}

SnowBall::SnowBall(float *origin, float *dir){
    normalize(dir);
    setPos(origin);
    setDir(dir);
    setSpeed(SnowBallSpeed);
}

void SnowBall::normalize(float *dir){
    float orig[3] = {0,0,0};
    float length = checkDis(orig, dir);
    dir[0] = dir[0] / length;
    dir[1] = dir[1] / length;
    dir[2] = dir[2] / length;
}

float SnowBall::checkDis(float *orig, float *target){
    float x = target[0] - orig[0];
    float y = target[1] - orig[1];
    float z = target[2] - orig[2];
    float result = sqrt(x*x + y*y + z*z);
    return result;
}

void SnowBall::update(){
    setHP(time-1);
    float tempSpeed = getSpeed();
    float tempDir[3] = {getDir()[0], getDir()[1], getDir()[2]};
    float tempPos[3] = {getPos()[0], getPos()[1], getPos()[2]};
    
    tempPos[0] = tempPos[0] + tempSpeed * tempDir[0];
    tempPos[1] = tempPos[1] + tempSpeed * tempDir[1];
    tempPos[2] = tempPos[2] + tempSpeed * tempDir[2];
    
    setPos(tempPos);
}

bool SnowBall::isHit(float *object, int size){
    //check the distance between current snowball and the target snowman
    float tempDis;
    tempDis = checkDis(getPos(), object);
    
    float tempSize;
    tempSize = this->size + size;
    
    bool result;
    
    result = (tempSize >= tempDis);
    return result;
}

void SnowBall::draw(){
    glutSolidSphere(0.5, 10, 10);
}