//
//  snow.h
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifndef snow_h
#define snow_h

//snow class
//it is a template class for other sub-type class: snowman, snowball, player

#include <vector>

using namespace std;

enum SnowType{
    man,
    ball
};

class Snow{
public:
    Snow();//constructor
    
    SnowType snowType;
    int HP;
    float* pos;
    float speed;
    float* dir;
    float* acc;//accelerate
    
    virtual void draw();
};
#endif /* snow_h */
