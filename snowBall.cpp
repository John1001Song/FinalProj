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

SnowBall::SnowBall() : Snow() {
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    time = 2000;
    size = 1;
}

void SnowBall::draw(){
    glutSolidSphere(0.5, 10, 10);
}