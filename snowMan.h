//
//  snowMan.h
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifndef snowMan_h
#define snowMan_h

#include <stdio.h>
#include "snow.h"

static float SNOWMAN_SPEED = 0.01;

//there are two kind of snowmans: AI and Player
//AI contains small, medium, and large size
enum ManType{
    smallAI,
    mediumAI,
    largeAI,
    player
};

class SnowMan:public Snow{
public:
    SnowMan();
    SnowMan(ManType whatType);//constructor
    ManType manType;
    
    virtual ~SnowMan();//deconstructor
    
    //we could use draw() to draw different size snowman base on its type
    virtual void draw();
    
    //we could use fire() to let snowman shoots snowball
    void fire();
    
    //update the snowman position and direction
    void update();
    
    //use angle to let the snowman change direction
    float getAngle();
    void setAngle(float angle);
    
    void setDirInAngle(float someAngle);
    //change the angle from degree to number
    static float transfAngToNumb(float angle);
    
    //draw the snowman
    void DrawSnowman(float *pos, float angle);
    
private:
    float pos[3];
    float dir[3];
    float angle;
    
};

#endif /* snowMan_h */
