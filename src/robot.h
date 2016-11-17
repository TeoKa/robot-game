//
//  robot.h
//  Robot_Game_2
//
//  Created by Matteo Ciocca on 18/03/14.
//  Copyright (c) 2014 Matteo Ciocca. All rights reserved.
//

#ifndef __Robot_Game_2__robot__
#define __Robot_Game_2__robot__

#include <iostream>

#define EMP '.'
#define ROWS 14
#define COLUMNS 22
#define L 'L'
#define X 'X'
#define H 'H'

using namespace std;

class robot {
public:
    int place(int row,int col,char **map,char who);
    int direction(char dir,char**m);
    int move(int num,char**m);
    int change_dir(char dir,int verse);
    void display();    
    
//    In order to access from enemy.h the private members of robot!!
    int get_x();
    int get_y();
    void set_ori(char new_ori);
//    protected -> access from children
private:
    int pos_x;
    int pos_y;
    char ori;
    char sym;

};
#endif /* defined(__Robot_Game_2__robot__) */
