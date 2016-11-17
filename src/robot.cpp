//
//  robot.cpp
//  Robot_Game_2
//
//  Created by Matteo Ciocca on 18/03/14.
//  Copyright (c) 2014 Matteo Ciocca. All rights reserved.
//

#include "robot.h"
#include "enemy.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstring>


using namespace std;


void robot::display(){

    cout<<"x posi: "<<pos_x<<endl;
    cout<<"y posi: "<<pos_y<<endl;
    cout<<"ori   : "<<ori<<endl;
    
}

// Used for the child class enemy!
int robot::get_x(){
    return pos_x;
}
int robot::get_y(){
    return pos_y;
}
void robot::set_ori(char new_ori){
    ori = new_ori;
}


int robot::place(int row,int col,char**map,char who){
    
    if(row<0 || col<0 || row>=ROWS || col>=COLUMNS)return 0;
    if( *(map[row]+col) == EMP){
        pos_x = row;
        pos_y = col;
        sym   = who;
        ori   = 'n';
        *(map[row]+col)=who;
        return 1;
    }
    return 0;
}

int robot::direction(char dir,char**m){
    int i=0;
    switch(dir){
        case('f'):
            i=move(1,&m[0]);  // it will effectively move
            break;
        case('b'):
            i=move(-1,&m[0]); // it will effectively move
            break;
        case('l'):
            i=change_dir(ori,-1); // it will turn left
            break;
        case('r'):
            i=change_dir(ori,1); // it will turn right
            break;
    }
    
    return i;
}

int robot::move(int num,char**m){
    
    char magic[]="nesw";
    int i;
    int num_x[]={ -num,   0, num,    0};
    int num_y[]={    0, num,   0, -num};
    i=0;
    while(magic[i]!=ori)i++;
    
//      -1 0 1
//  -1   . . .  -1
//   0   . X .   0
//   1   . . .   1
    
    //            If I go further than the map, just delete myself and win!
    if((pos_x+num_x[i]<0 || pos_y+num_y[i]<0 || pos_x+num_x[i]>=ROWS || pos_y+num_y[i]>=COLUMNS)){
        if(sym==X){
        *(m[pos_x]+pos_y)=EMP;
            return 1;
        }// enemies remains in the grid
        else return 1;
    }
    // so enemies do not eat each others and you can not go where there is an enemy
    // returning 1 you actually do not move! ->good
    if(*(m[pos_x+num_x[i]]+pos_y+num_y[i])==H || *(m[pos_x+num_x[i]]+pos_y+num_y[i])==L)
        return 1;
    
    *(m[pos_x]+pos_y)=EMP;
    
    if(sym==H && *(m[pos_x+num_x[i]]+pos_y+num_y[i])==X){
        *(m[pos_x+num_x[i]]+pos_y+num_y[i])=L;
    }else
        *(m[pos_x+num_x[i]]+pos_y+num_y[i])=sym;
    
    pos_x = pos_x+num_x[i];
    pos_y = pos_y+num_y[i];
    
    return 1;
}

int robot::change_dir(char dir,int verse){
    
    char magic[]="wneswn";
    int i;
    i=1;
    while(magic[i]!=dir)i++;
    ori = magic[i+verse];
    return 1;
    
}
