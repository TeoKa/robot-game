//
//  main.cpp
//  Robot_Game_2
//
//  Created by Matteo Ciocca on 18/03/14.
//  Copyright (c) 2014 Matteo Ciocca. All rights reserved.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "robot.h"
#include "enemy.h"

#define EMP '.'
#define ROWS 14
#define COLUMNS 22
#define NUM_ENE 100

using namespace std;

// Code //
void display(char**m){
    int i,j;
    
    cout<<endl;
    cout<<"  ";
    for(i=0;i < 2*COLUMNS ;i++)
        cout<<"-";
    cout<<endl;
 
        
    for(i=0;i<ROWS;i++){
        cout << "| ";
        for(j=0;j<COLUMNS;j++){
            cout<<*(m[i]+j);
            cout<<" ";
        }
        cout << " |" << std::endl;
    }
    cout<<"  ";
    for(i=0;i < 2*COLUMNS ;i++)
        cout<<"-";
    cout<<endl;
}

int find(char who,char**m){
    int i,j;
    // says if "who" is still in game
        for(i=0;i<ROWS;i++){
            for(j=0;j<COLUMNS;j++)
                if(*(m[i]+j)==who)return 1;
            
        }
    return 0;
}


void initializ(robot* me,enemy* ene,char**pnt,long int** enemies){

    int row,col,i;
    srand(time(NULL));
    row=rand() % ROWS;
    col=rand() % COLUMNS;
    //    Me     //////////////////////
    while(!me->place(row,col,&pnt[0],X)){
    row=rand() % ROWS;
    col=rand() % COLUMNS;
    }
    cout<<"Me done"<<endl;

    
    while(**enemies==0 || **enemies>(ROWS*COLUMNS-1)){
        cout<<"Number of enemies (1-10): "<<endl;
        cin>>**enemies;
    }
    
    //   Enemies //////////////////////O
    for(i=0;i<**enemies;i++){
        while(!ene[i].place(row,col,&pnt[0],H)){
            row=rand() % ROWS;
            col=rand() % COLUMNS;
        }
    }

    return;
}

int main(int argc, const char * argv[])
{
    int i,j;
    long int enemies;
    char dir;
    char map[ROWS][COLUMNS];
    long int* pnt_num_ene = &enemies;

//    Generating the map
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++)
            map[i][j]=EMP;
    }
// Array of pointers in order to point the whole matrix (Map) -BOOM- ///
    char** pnt = new char*[ROWS];
    for(i=0;i<ROWS;i++)
        pnt[i] = &map[i][0];
    cout<<endl;
//  ////////////////////////////////////////////////////////////////////
    
    robot me;
    enemy ene[NUM_ENE];
    robot * pnt_me  = &me;
    enemy * pnt_ene_class = &ene[0];

//    No use of double pointers for classes
    initializ(pnt_me,&pnt_ene_class[0],&pnt[0],&pnt_num_ene);
    
    
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    display(&pnt[0]);
    
    while(1){
        
        //          Condition: victory
        if(!find(L,&pnt[0]) && !find(X,&pnt[0])){
            cout<<"You Won\n\n\n";
            break;
        }
        //          Condition: lose
        if(find(L,&pnt[0])){
            cout<<"You Lost\n\n";
            break;
        }
        //        My Turn
        cout<<"your definition"<<endl;
        me.display();
        cout<<"\nMake your move ('turn left' and 'turn right', change only direction)\n\nmove forward  = f\nmove backward = b\nturn right    = r\nturn left     = l\n: ";
        cin>>dir;
        
        if(!me.direction(dir,&pnt[0])){
            cout<<"\n\n\n\n\n\nError\n\n\n\n\n\n"<<endl;
            break;
        }
//        Computer move
        for(i=0;i<enemies;i++){
//           change the orientation of the enemy
            ene[i].target(&pnt[0],pnt_me);
//            move foward to the
            ene[i].direction('f',&pnt[0]);
        }
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        display(&pnt[0]);
    }
    
//    Delete the double pointer created before !
    delete[] pnt;
    
    return 0;
}

