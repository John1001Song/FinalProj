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

using namespace std;

static int SnowBallLife = 2000;//asume the snowball could fly for 2000s
static float SnowBallSpeed = 0.1;

class SnowBall: public Snow{
public:
    SnowBall();//constructor
	
	SnowBall(float *origin, float* dir);
    
    //update snowball as it travels
	void update();
    
    //this func is used in direction. it will return an normalized direction
	static void normalize(float* vec);
    
    //this func is used for check distance between this snowball and other snowmen
    static float checkDis(float *origin, float *target);
    
    //this func is to check if this snowball hits the snowman; "*object" is the snowman and "size" is the snowman size
    bool isHit(float *object, int size);
    
    //this func is to draw the snowball
    void draw();
    
private:
    float color[3];
    
    //each snowball has a life based on time. time = HP
    //EX: after 10s, if the snowball does not hit, it disappears
    float time;
    
    int size;
    
    float speed;
};
#endif /* snowBall_h */
