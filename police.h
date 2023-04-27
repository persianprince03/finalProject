//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#ifndef POLICE_H
#define POLICE_H
#include "robber.h"
#include "jewel.h"
#include "const.h"

#include <iostream>
using namespace std;


class Police{
    private:
    int id;
    int xCor, yCor;
    int totalConfisicatedVal;
    int caughtRobbers
        ;
public:
    Police();
    Police(int x, int y ,int num);
    void move(char board[10][10]);
    void printSummary();
    void arrest(int loot_value);
    int getRow();
    int getColumn();

};



#endif