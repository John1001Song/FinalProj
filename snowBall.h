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

static int LIFE = 2000;

class SnowBall: public Snow{
public:
    SnowBall();//constructor
	
	SnowBall(float *origin, float* dir);

	void update();//update snowball as it travels may or may not need this

	//bool is_Hit(float* target, int size);

	static void normalize(float* vec);
    bool checkDis();//this func is used for check distance between this snowball and other snowmen
    
private:
    float color[3];
    
    //each snowball has a life based on time.
    //EX: after 10s, if the snowball does not hit, it disappears
    float time;
    int size; // use size to represent the snowball power; the bigger size, the more power
    
//    void draw();//draw a snowball
    
};
#endif /* snowBall_h */
