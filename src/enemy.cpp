//
//  enemy.cpp
//  Robot_Game_2
//
//  Created by Matteo Ciocca on 18/03/14.
//  Copyright (c) 2014 Matteo Ciocca. All rights reserved.
//

#include "enemy.h"
#include "robot.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>

using namespace std;


//void diagonal(int up,int left)


void enemy::target(char**m,robot* pnt_me){
    
    
//    must change direction of ENEMY !
    char magic[]="nesw";
    int diff_x,diff_y;
    bool up,left;
    
    diff_x = pnt_me->get_x() - get_x();
    diff_y = pnt_me->get_y() - get_y();
    
    up    = diff_x<0;
    left  = diff_y<0;
    
    //     1  2  3
    //  1  x  x  x
    //  2  x  H  x
    //  3  x  x  x
    

    if(up){ //it is up
        if(left){ // it is up and left
            if(diff_y==0 || abs(diff_x)>abs(diff_y))
                set_ori(magic[0]);//n
            else
                set_ori(magic[3]);//w
        }else{// it is up and right
            if(diff_y==0 || abs(diff_x)>abs(diff_y))
                set_ori(magic[0]);
            else
                set_ori(magic[1]);
        }
    }else{ // it is down/centre
        if(left){ // it is down/centre and left
            if(diff_x==0 || abs(diff_x)<abs(diff_y))
                set_ori(magic[3]);
            else
                set_ori(magic[2]);
        }else{// it is down/centre and right
            if(diff_x==0 || abs(diff_x)<abs(diff_y))
                set_ori(magic[1]);
            else
                set_ori(magic[2]);
        }
    }
    return;
    
}
