//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#ifndef JEWEL_H
#define JEWEL_H

#include "const.h"
#include <iostream>






using namespace std;
class Jewel{
    public:

    Jewel();
    //Desc: This function initializes the class Jewel
    //Pre: coordinates
    //Post: initialized Jewel
    Jewel(int x, int y, int val);

//        int getVal();
    private:
        int val = 0;
        int Xcor;
        int Ycor{};
};

#endif
