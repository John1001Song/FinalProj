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
    
    //we could use snowOperate0() to draw different size snowman base on its type
    virtual void draw();
    
    //we could use snowOperate1() to let snowman shoots snowball
    void fire();
};

#endif /* snowMan_h */
