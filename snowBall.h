//
//  snowBall.h
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifndef snowBall_h
#define snowBall_h

#include <stdio.h>
#include "snow.h"
#include "structs.h"

class SnowBall: public Snow{
public:
    SnowBall();//constructor
    
    Vector3D color;
    
    //each snowball has a life based on time.
    //EX: after 10s, if the snowball does not hit, it disappears
    float time;
    
    int size; // use size to represent the snowball power; the bigger size, the more power
    
    void draw();//draw a snowball
};
#endif /* snowBall_h */
