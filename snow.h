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

using namespace std;

//based on the type, snow could be snowball or snowman
enum SnowType{
    man,
    ball
};

class Snow{
public:
    Snow(); // constructor
    
    SnowType snowType;
    
    virtual ~Snow();//deconstructor
    
    void setType(SnowType t);
    SnowType getType();
    
    //for snowball, it has HP = 2000, which is 2000 seconds; for snowman, it has HP = 3, which means if it is hit, HP-- 
    int getHP() const;
    void setHP(int hp);
    
    float getSize() const;
    void setSize(float size);
    
    float getSpeed() const;
    void setSpeed(float speed);
    
    float* getPos();
    void setPos(float* position);
    
    void setDir(float* direction);
    float* getDir();
    
    void setAcc(float* direction);
    float* getAcc();
    
    virtual void draw();
    
private:
    SnowType type;
    int HP;
    float size;
    float speed;
    float pos[3];
    float dir[3];
    float acc[3]; // acceleration
};
#endif /* snow_h */
