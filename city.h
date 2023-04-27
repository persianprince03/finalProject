//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#ifndef CITY_H
#define CITY_H

#include "const.h"
#include "jewel.h"
#include <iostream>

using namespace std;





class City{
    public:
    //Desc: Default constructor: creates the map
    //Pre: none
    //Post: Generated map with item positions
        City();


        //Desc:This function recives the map
        //pre:none
        //post: an array of char related to the city
        char getMap(int i, int j);

        //Desc:This function recives the map
        //pre:none
        //post: an array of char related to the city
        void setMap(int i, int j, char c);


        //Description: Prints the map when the function is called.
        //Pre: None
        //Post: Prints the map in its current state.
        void printGrid();

    private:
    char cityGrid[10][10];
    int jewelCount = 0;


    

};












#endif