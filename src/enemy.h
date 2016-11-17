//
//  enemy.h
//  Robot_Game_2
//
//  Created by Matteo Ciocca on 18/03/14.
//  Copyright (c) 2014 Matteo Ciocca. All rights reserved.
//

#ifndef __Robot_Game_2__enemy__
#define __Robot_Game_2__enemy__
#include "robot.h"
#include <iostream>

#define EMP '.'
#define ROWS 14
#define COLUMNS 22

using namespace std;
//class [CHILD_CLASS_NAME] : [ACCESS_SPECIFIER] [PARENT_CLASS_NAME]

//Enemy is a Robot
class enemy : public robot {

public:
    void target(char**m,robot *pnt_me);
};

#endif /* defined(__Robot_Game_2__enemy__) */
