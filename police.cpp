// Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#include "police.h"
#include <iostream>

using namespace std;
Police::Police() {}
Police::Police(int x, int y, int num) {
  xCor = x;
  yCor = y;
  id = num;
  totalConfisicatedVal = 0;
  caughtRobbers = 0;
}

int Police::getXcor() { return xCor; }

int Police::getYcor() { return yCor; }

void Police::Pmove() {
  int police_direction = random() % 7;
  cout << "Generated Cop #: " << police_direction << endl;
  if (police_direction == 0) {
    bool status = xCor - 1 < 10 && yCor - 1 < 10 && xCor-1 > 0 && yCor-1 > 0;
    cout << "NW called. status: " << status << endl;
    if (xCor - 1 < 10 && yCor - 1 < 10) {
      xCor--;
      yCor--;
    }
  } else if (police_direction == 1) {
    bool status = yCor - 1 < 11;
    cout << "North called. status: " << status << endl;
    if (yCor - 1 < 11) {
      yCor--;
    }
  } else if (police_direction == 2) {
    bool status = xCor + 1 < 10 && yCor - 1 < 10;
    cout << "NE called. status: " << status << endl;
    if (xCor + 1 < 11 && yCor - 1 < 11) {
      xCor++;
      yCor--;
    }
  } else if (police_direction == 3) {
    bool status = xCor - 1 < 10;
    cout << "West Called. status: " << status << endl;
    if (xCor - 1 < 11) {
      xCor--;
    }
  } else if (police_direction == 4) {
    bool status = xCor + 1 < 10;
    cout << "East Called. status: " << status << endl;
    if (xCor + 1 < 11) {
      xCor++;
    }
  } else if (police_direction == 5) {
    bool status = xCor - 1 < 10 && yCor + 1 < 11;
    cout << "SW Called. status: " << status << endl;
    if (xCor - 1 < 11 && yCor + 1 < 11) {
      xCor--;
      yCor++;
    }
  } else if (police_direction == 6) {
    bool status = yCor + 1 < 10;
    cout << "South Called. status: " << status << endl;
    if (yCor + 1 < 11) {
      yCor++;
    }
  } else {
    bool status = xCor + 1 < 11 && yCor + 1 < 11;
    cout << "SE Called. status: " << status << endl;
    if (xCor + 1 < 10 && yCor + 1 < 10) {
      xCor++;
      yCor++;
    }
  }
}
//void Police::Pmove() {
//    int move = random()%7;
//    cout << "Generated Cop #: " << move << endl;
//    if (xCor+1 <= 10 && xCor-1 >= 0 && yCor +1 <= 10&& yCor -1 >= 0){
//        switch (move) {
//           case 0:
//               if(xCor + yCor < 19){
//                   xCor++;
//                   yCor++;
//               }
//            case 1:
//                yCor--;
//            case 2:
//                xCor++;
//                yCor--;
//            case 3:
//                xCor--;
//            case 4:
//                xCor++;
//            case 5:
//                xCor--;
//                yCor++;
//            case 6:
//                yCor++;
//            case 7:
//                xCor++;
//                yCor++;
//
//        }
//    }
//}