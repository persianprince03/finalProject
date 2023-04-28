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
  Police p[1];


  int jewelNum = 0;
  //Jewel locator
  while (jewelNum < 47) {

      int x = rand() % 10;
      int y = rand() % 10;
      if (eastStLouis.getMap(x,y) == ' ') {
          eastStLouis.setMap(x,y,'J');
          Jewel loot(x,y,x+y);
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
          if(numRobbers < 2){
              Robber<Jewel> robberInfo(false,numRobbers,x,y);
              eastStLouis.setMap(x,y,'r');
              r[numRobbers]=robberInfo;
          }else{
              Robber<Jewel> robberInfo(true,numRobbers,x,y);
              eastStLouis.setMap(x,y,'r');
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
          Police policeInfo(x,y,numCops+1);
        
          p[numCops] = policeInfo;
        
          numCops++;
      }


      jewelNum++;
  }


  eastStLouis.printGrid();
  cout<<"The grid above this message is the initial city grid."<<endl;


  int turn = 0;

  while (turn <= 29) {
    turn++;
    cout << "\nRound " << turn << endl;

    //robber movement
    for (int i = 0; i < 5; i++) {
      if(i == 0){
        cout << "\nRobber 1 Movements: ";
        int oldX = r[i].getXcor();
        int oldY = r[i].getYcor();
        eastStLouis.setMap(oldX, oldY, ' ');
        r[i].move();
        int x = r[i].getXcor();
        int y = r[i].getYcor();
        if(eastStLouis.getMap(x,y) == 'J'){

        }
        eastStLouis.setMap(x, y, '1');
      }else if(i == 1){
        cout << "\nRobber 2 Movements: ";
        int oldX = r[i].getXcor();
        int oldY = r[i].getYcor();
        eastStLouis.setMap(oldX, oldY, ' ');

        r[i].move();
        int x = r[i].getXcor();
        int y = r[i].getYcor();


        for (int j =0; j<47; j++){
            if (list[j].getXocr() == x && list[j].getYcor()==y){
                r[i].pickUpLoot(list[j]);
                cout<<"Loot has been picked up Yeeepeee"<<endl;
}
        }
        eastStLouis.setMap(x, y, '2');
      }else if(i == 2){
        cout << "\nRobber 3 Movements: ";
        int oldX = r[i].getXcor();
        int oldY = r[i].getYcor();
        eastStLouis.setMap(oldX, oldY, ' ');

        r[i].move();
        int x = r[i].getXcor();
        int y = r[i].getYcor();
        if(eastStLouis.getMap(x,y) == 'J'){
          //code for jewel calculation
          //code for jewel calculation
        }
        eastStLouis.setMap(x, y, '3');
      }else if(i == 3){
        cout << "\nRobber 4 Movements: ";
        int oldX = r[i].getXcor();
        int oldY = r[i].getYcor();
        eastStLouis.setMap(oldX, oldY, ' ');

        r[i].move();
        int x = r[i].getXcor();
        int y = r[i].getYcor();
        if(eastStLouis.getMap(x,y) == 'J'){
          //code for jewel calculation
          //code for jewel calculation
        }
        eastStLouis.setMap(x, y, '4');

      }else if(i == 4){// police movement
      for(int i = 0; i < 1; i++){
        int oldX = p[i].getXcor();
        int oldY = p[i].getYcor();
        eastStLouis.setMap(oldX,oldY,' ');


        //how to prevent p from moving out the screen
        
        p[i].Pmove();
        int x = p[i].getXcor();
        int y = p[i].getYcor();


          //code for jewel calculation
          //code for jewel calculation
          eastStLouis.setMap(x,y,'p');
        }
      }
    }
    //police movement

    
  

    //Checks for Robber grouping
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

  }
  for(int j = 0; j < 4; j++){

  }
  return 0;
}