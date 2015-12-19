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


#ifndef _BULLET_H_
#define _BULLET_H_

using namespace std;

static int LIFE = 2000;

class SnowBall: public Snow{
public:
    SnowBall();//constructor
	
	SnowBall(float *origin, float* dir);
	virtual ~Snowball();
	
	/* May or may not need the follow function*/
	void set_Dir(float* direction);
	float* get_Dir();

	float* get_Pos();
	void set_Pos(float* position);

	int get_Size() const;
	void set_Size(int size);

	float get_Speed() const;
	void set_Speed(float speed);

	int get_Life() const;
	void set_Life(int life);

	void update();//update snowball as it travels may or may not need this

	bool is_Hit(float* target, int size);

	static void normalize(float* vec);
    
    Vector3D color;
    
    //each snowball has a life based on time.
    //EX: after 10s, if the snowball does not hit, it disappears
    float time;
    
    int size; // use size to represent the snowball power; the bigger size, the more power
    
    void draw();//draw a snowball
    
    bool checkDis();//this func is used for check distance between this snowball and other snowmen
	
	
private:
	float position[3];
	int size;
	float direction[3];
	float speed;
	int life;
};
#endif /* snowBall_h */
