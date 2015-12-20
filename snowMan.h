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

enum ManType{
    smallAI,
    mediumAI,
    largeAI,
    player
};

class SnowMan:public Snow{
public:
    SnowMan(ManType whatType);//constructor
    ManType manType;
    
    virtual ~SnowMan();//deconstructor
    
    //we could use draw() to draw different size snowman base on its type
    virtual void draw();
    
    //we could use fire() to let snowman shoots snowball
    void fire();
    
    void setPos(float *pos);
    float* getPos();
    
    void setDir(float *dir);
    float* getDir();
    
    void setAngle(float angle);
    float getAngle();
    
    void update();
    
    
    
    
private:
    float pos[3];
    float dir[3];
    float angle;
    
};

#endif /* snowMan_h */
