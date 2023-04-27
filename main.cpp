//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
// Date: 4/26/2023
// File: FinalProject
// Purpose: Automatically simulate a Cops and Robbers interaction within a 10X10 "city" grid
#include <iostream>
#include <cmath>
#include "city.h"
#include "police.h"
#include "robber.h"
#include "jewel.h"

using namespace std;




int main(){
    srand(85);
    //The reason our city has been named East St.Louis is because of high crime rate in that area please have fun with
    //joke and don't reduce points :)
    City eastStLouis;
    Jewel list[47];
    Robber<Jewel> r[4];



    int jewelNum = 0;

    //Jewel locator
    while (jewelNum < 47) {

        int x = rand() % 10;
        int y = rand() % 10;
        if (eastStLouis.getMap(x,y) == ' ') {
            eastStLouis.setMap(x,y,'J');
            Jewel loot(x,y,'J');
            list[jewelNum]= loot;
        }


            jewelNum++;
        }

    //Robbers locator
    int numRobbers = 0;
    while (numRobbers < 4) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (eastStLouis.getMap(x,y) == ' '){
            eastStLouis.setMap(x,y,'r') ;
            if(numRobbers <2){
                Robber<Jewel> robberInfo(false,numRobbers+1,x,y);
                r[numRobbers]=robberInfo;
            }else{
                Robber<Jewel> robberInfo(true,numRobbers+1,x,y);
                r[numRobbers]=robberInfo;
            }
            numRobbers++;
        }

    }
    //Police Locator
    int numCops = 0;
    while (numCops < 1) {

        int x = rand() % 10;
        int y = rand() % 10;
        if (eastStLouis.getMap(x,y) == ' ') {
            eastStLouis.setMap(x,y,'p');
            Police police(x,y,numCops+1);
            numCops++;
        }


        jewelNum++;
    }


    eastStLouis.printGrid();
    cout<<"Game Starts from here"<<endl<<endl<<endl;


    int turn = 0;

    while (turn <= 30) {
        for (int i = 0; i < 4; i++) {
            int oldX = r[i].getXcor();
            int oldY = r[i].getYcor();
            eastStLouis.setMap(oldX, oldY, ' ');

            r[i].move();
            int x = r[i].getXcor();
            int y = r[i].getYcor();
            eastStLouis.setMap(x, y, 'r');
        }
        for (int i = 0; i <4 ;i++){
            for(int j = 0;j<4;j++){
                if (j != i){
                    if (r[i].getYcor() == r[j].getYcor() && r[i].getXcor()==r[j].getXcor()&&r[i].getStatus()
                    &r[j].getStatus()){
                        int x = r[i].getXcor();
                        int y = r[i].getYcor();
                        eastStLouis.setMap(x, y, 'R');
                        if(r[i].getGreed()){
                            int val = r[i].getLoot()/2;
                            if(val%2 != 0) {
                                r[i].setLoot(floor(val));
                            }else{
                                r[i].setLoot(val);

                            }
                        }else if(r[j].getGreed()){
                            int val = r[j].getLoot()/2;
                            if(val%2 != 0) {
                                r[j].setLoot(floor(val));
                            }else{
                                r[j].setLoot(val);
                            }
                        }
                    }
                }
            }
        }
        eastStLouis.printGrid();
        turn++;
        cout << "new round" << endl << endl;
    }
    for(int j = 0; j < 4; j++){

    }
    return 0;
}