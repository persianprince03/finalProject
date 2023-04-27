//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101
#include "city.h"
#include "robber.h"
#include "police.h"
#include "jewel.h"
#include <iostream>

using namespace std;









City::City() {

    int jewelNum = 0;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            cityGrid[x][y] = ' ';
        }
    }


}

void City::printGrid(){
    for(int i = 0; i < 10; i++){
        cout << " _ _ _ _ _ _ _ _ _ _ " << endl;
        for(int j = 0; j < 10; j++){
            cout << '|' << cityGrid[i][j];
        }
        cout << '|' << endl;
    }
}

char City::getMap(int x, int y) {

    return cityGrid[x][y];
}
void City::setMap(int x, int y, char c) {
    cityGrid[x][y]=c;
}
//jewel City::getJewel(int x, int y)
//{
//    int coordinate = (x * 10) + y;
//    return City::mainList[coordinate];
//}