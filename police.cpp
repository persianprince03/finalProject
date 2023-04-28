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
    bool status = xCor - 1 < 11 && yCor - 1 < 11 && xCor-1 > 0 && yCor-1 > 0;
    cout << "NW called. status: " << status << endl;
    if (status == true) {
      xCor--;
      yCor--;
    }
  } else if (police_direction == 1) {
    bool status = yCor - 1 < 11 && yCor - 1 > 0;
    cout << "North called. status: " << status << endl;
    if (status == true) {
      yCor--;
    }
  } else if (police_direction == 2) {
    bool status = xCor + 1 < 11 && yCor - 1 < 11 && yCor-1 > 0;
    cout << "NE called. status: " << status << endl;
    if (status == true) {
      xCor++;
      yCor--;
    }
  } else if (police_direction == 3) {
    bool status = xCor - 1 < 11 && xCor - 1 > 0;
    cout << "West Called. status: " << status << endl;
    if (status == true) {
      xCor--;
    }
  } else if (police_direction == 4) {
    bool status = xCor + 1 < 11;
    cout << "East Called. status: " << status << endl;
    if (status == true) {
      xCor++;
    }
  } else if (police_direction == 5) {
    bool status = xCor - 1 < 11 && yCor + 1 < 11 && xCor - 1 > 0;
    cout << "SW Called. status: " << status << endl;
    if (status == true) {
      xCor--;
      yCor++;
    }
  } else if (police_direction == 6) {
    bool status = yCor + 1 < 11;
    cout << "South Called. status: " << status << endl;
    if (status == true) {
      yCor++;
    }
  } else {
    bool status = xCor + 1 < 11 && yCor + 1 < 11;
    cout << "SE Called. status: " << status << endl;
    if (status == true) {
      xCor++;
      yCor++;
    }
  }
}
