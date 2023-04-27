//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101

#include "robber.h"
#include <iostream>








template <class T>

Robber<T>::Robber(bool isGreedy,int num, int x, int y){

    id = 0;
    Xcor = x;
    Ycor = y;
    greedy = isGreedy;
    id++;

}
template<class T>
Robber<T>::Robber() {}


template<class T>
void Robber<T>::move() {
    int direction = random() % 7;
    cout<<"debug: luck:  "<<direction<<endl;
    if (direction == 0) {
        bool status = Xcor-1 < 11 && Ycor-1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor-1 < 11 && Ycor-1<11) {
            Xcor --;
            Ycor--;
        }
    } else if (direction == 1) {
        bool status = Ycor-1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Ycor-1 < 11 ) {
            Ycor--;
        }
    } else if (direction == 2) {
        bool status = Xcor+1 < 11 && Ycor-1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor+1 < 11 && Ycor-1<11) {
            Xcor++;
            Ycor--;
        }
    } else if (direction == 3) {
        bool status = Xcor-1 < 11 ;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor-1 < 11 ) {
            Xcor--;
        }
    } else if (direction == 4) {
        bool status = Xcor+1 < 11 ;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor+1 < 11 ) {
            Xcor++;
        }
    } else if (direction == 5) {
        bool status = Xcor-1 < 11 && Ycor+1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor-1 < 11  && Ycor +1<11) {
            Xcor--;
            Ycor++;
        }
    } else if (direction == 6) {
        bool status = Ycor+1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Ycor+1 < 11 ) {
            Ycor++;
        }
    } else {
        bool status = Xcor+1 < 11 && Ycor+1<11;
        cout<<"Debug: status: "<<status<<endl;
        if (Xcor+1 < 11 && Ycor +1 <11) {
            Xcor++;
            Ycor++;
        }
    }

}



template<class T>
int Robber<T>::getXcor() {
    return Xcor;
}
template<class T>
int Robber<T>::getYcor() {
    return Ycor;
}

template<class T>
bool Robber<T>::getGreed() {
    return greedy;
}

template<class T>
void Robber<T>::setLoot(int val) {
    numLoot = val;
}

template<class T>
int Robber<T>::getLoot() {
    return numLoot;
}

template<class T>
bool Robber<T>::getStatus() {
    return active;
}