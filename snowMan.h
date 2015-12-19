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
    
    virtual void snowOperate();
};

#endif /* snowMan_h */
