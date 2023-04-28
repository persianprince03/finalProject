//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#ifndef POLICE_H
#define POLICE_H
#include "robber.h"
#include "jewel.h"

#include <iostream>
using namespace std;


class Police{
    private:
    int id = 1;
    int xCor, yCor;
    int totalConfisicatedVal;
    int caughtRobbers;
public:
    Police();
    Police(int x, int y ,int id);
    void Pmove();

    int getXcor();
    int getYcor();
    
    void arrest(int loot_value);

};



#endif