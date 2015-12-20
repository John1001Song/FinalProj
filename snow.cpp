//
//  snow.cpp
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#include <stdio.h>
#include "snow.h"

Snow::Snow(){
    type = SnowType::ball;
    HP = 1;
    speed = 1;
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    acc[0] = 0;
    acc[1] = 0;
    acc[2] = 0;
}

float* Snow::getDir() {
    return dir;
}

void Snow::setDir(float* d) {
    dir[0] = d[0];
    dir[1] = d[1];
    dir[2] = d[2];
}

float* Snow::getAcc() {
    return acc;
}

void Snow::setAcc(float* d) {
    acc[0] = d[0];
    acc[1] = d[1];
    acc[2] = d[2];
}

float* Snow::getPos() {
    return pos;
}

void Snow::setPos(float* p) {
    pos[0] = p[0];
    pos[1] = p[1];
    pos[2] = p[2];
}

float Snow::getSpeed() const {
    return speed;
}

void Snow::setSpeed(float speed) {
    this->speed = speed;
}

int Snow::getHP() const {
    return HP;
}

void Snow::setHP(int hp){
    this->HP = hp;
}

void Snow::setType(SnowType t) {
    type = t;
}
SnowType Snow::getType() {
    return type;
}

//function needs to be overridden in child classes
void Snow::draw(){}
