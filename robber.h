//Programmers: Parsa Divanbeigi(pdcbc) and Rapheal Seymour(rns2p2) Section: 101

#ifndef ROBBER_H
#define ROBBER_H

#include "police.h"
#include "jewel.h"
#include "city.h"






#include <iostream>

using namespace std;


template <class T>
class Robber {

public:
    //Description:  Initializes the robber.
    //Pre: none
    //Post: Initializes the robber (mostly used for lists).
    Robber();
    //Description: explicitly Initializes the robber.
    //Pre; whether the robber is greedy or not, id , and coordinates
    //Post: Initializes the robber to its starting values and position.
    Robber(bool isGreedy,int numRobbers, int x, int y);
    //Description: moves the robber.
    //Pre: none
    //Post: updated cordinates
    void move();
    //getter function for Xcor
    int getXcor();
    //setter function for ycor
    int getYcor();

    //getter function for greedy ness
    bool getGreed();
    //getter function for loot
    int getLoot();
    //setter function for loot
    void setLoot(int val);
    //getter function for active
    bool getStatus();

    int pickUpLoot(Jewel loot);
private:
    int id ;
    int Xcor;
    int Ycor;
    T bag[17];

    int numLoot = 0;//amount of looted jewwelery
    bool active = true;
    bool greedy;

};
#include "robber.hpp"
#endif //ROBBER_H