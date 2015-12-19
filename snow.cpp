//
//  snow.cpp
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#include <stdio.h>
#include "snow.h"

Snow::Snow(){
    HP = 1; //defalut hp is 1
    speed = 1;
    //others are defined in snowman or snowball itself because they will have different defalut value
}


//function needs to be overridden in child classes
void Snow::draw(){}
