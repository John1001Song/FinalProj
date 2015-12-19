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
#include "structs.h"

using namespace std;

enum SnowType{
    man;
    ball;
};

class Snow{
public:
    Snow();//constructor
    
    SnowType snowType;
    int HP;
    Vector3D pos[3];
    float speed;
    Vector3D dir;
    Vector3D acc[3];//accelerate
    
    virtual void snowOperate();
    
}
#endif /* snow_h */
