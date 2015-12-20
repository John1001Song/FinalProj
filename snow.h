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

enum SnowType{
    man,
    ball
};

class Snow{
public:
    Snow(); // constructor
    
    SnowType snowType;
    
    virtual ~Snow();
    
    void setType(SnowType t);
    SnowType getType();
    
    int getHP() const;
    void setHP(int hp);
    
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
    float speed;
    float pos[3];
    float dir[3];
    float acc[3]; // acceleration
};
#endif /* snow_h */
