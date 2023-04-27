//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#include "police.h"
#include <iostream>

using namespace std;
Police::Police() {}
Police::Police(int x, int y,int num) {
    xCor = x;
    yCor = y;
    id = num;
    totalConfisicatedVal = 0;
    caughtRobbers = 0;

}

