//Programmers: Parsa Divanbeigi(pdcbc) and Raphael Seymour(rns2p2) Section: 101

#include "robber.h"
#include <iostream>


template <class T>

Robber<T>::Robber(bool isGreedy,int numRobbers, int x, int y){

    id = numRobbers;
    Xcor = x;
    Ycor = y;
    greedy = isGreedy;
    numRobbers++;

}
template<class T>
Robber<T>::Robber() {}


template<class T>
void Robber<T>::move() {
    int robber_direction = random() % 7;
    cout << "Generated Robber #: " << robber_direction << endl;
    if (robber_direction == 0) {
        bool status = Xcor-1 < 11 && Ycor-1<11;

        cout<<"NW called" << endl;
        if ((Xcor + Ycor) < 20 && Xcor-1 > 0 && Ycor-1 > 0) {
            Xcor--;
            Ycor--;
        }
    } else if (robber_direction == 1) {
        bool status = Ycor-1<11;
        cout<<"North called" << endl;
        if (Ycor-1 < 11 && Ycor-1 > 0) {
            Ycor--;
        }
    } else if (robber_direction == 2) {
        bool status = Xcor+1 < 11 && Ycor-1<11;
        cout<<"NE called" << endl;
        if (Xcor+1 < 11 && Ycor-1<11 && Xcor-1 > 0 && Ycor-1 > 0) {
            Xcor++;
            Ycor--;
        }
    } else if (robber_direction == 3) {
        bool status = Xcor-1 < 11 ;
        cout<<"West called" << endl;
        if (Xcor-1 < 11 && Xcor-1 > 0) {
            Xcor--;
        }
    } else if (robber_direction == 4) {
        bool status = Xcor+1 < 11 ;
        cout<<"East called" << endl;
        if (Xcor+1 < 11 && Xcor-1 > 0) {
            Xcor++;
        }
    } else if (robber_direction == 5) {
        bool status = Xcor-1 < 11 && Ycor+1<11;
        cout<<"SW called" << endl;
        cout << "\nXcor before: " << Xcor;
        cout << "\nYcor before: " << Ycor;
        if (Xcor-1 < 11  && Ycor+1<11 && Xcor-1 > 0) {
            Xcor--;
            Ycor++;
            cout << "\nAfter: " << Xcor;
            cout << "\nAfter: " << Ycor;
        }
    } else if (robber_direction == 6) {
        bool status = Ycor+1<11;
        cout<<"South called" << endl;
        if (Ycor+1 < 11) {
            Ycor++;
        }
    } else {
        bool status = Xcor+1 < 11 && Ycor+1<11;
        cout<<"SE called" << endl;
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

template<class T>
int Robber<T>::pickUpLoot(Jewel loot){
    bag[numLoot]=loot;

}

