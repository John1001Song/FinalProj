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

SnowMan::SnowMan(ManType whatType){
    setType(man);
    manType = whatType;
}

void SnowMan::draw(){
    switch (manType) {
        case smallAI:
            
            break;
            
        case mediumAI:
            break;
            
        case largeAI:
            break;
            
        case player:
            break;
            
        default:
            break;
    }
}
