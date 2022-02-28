/*
 * Battleship.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#include "Battleship.h"
Battleship::Battleship( Type type, Pair* coordinate) : Location(coordinate) {
    setType(type);
    waterOrNot = false;
    unchecked = true;
    previous = nullptr;
    next = nullptr;
}

Battleship::~Battleship() {
}

void Battleship::setType(Type t){
    type = t;
    switch(type) {
        case CARRIER:
            actualSymbol = 'A';
            compartments = 5;
            break;
        case SUBMARINE:
            actualSymbol = 'S';
            compartments = 2;
            break;
        case BATTLESHIP:
            actualSymbol = 'B';
            compartments = 4;
            break;
        case CRUISER:
            actualSymbol = 'C';
            compartments = 3;
            break;
        case DESTROYER:
            actualSymbol = 'D';
            compartments = 3;
            break;
        default:
            std::cout << "not a ship type" <<std::endl;
            break;
    }
}

int Battleship:: getCompartments(){
    return compartments;
}

bool Battleship:: ifSink(){
    bool Sink = hasBeenShot;//check
    unchecked = false; //marked as checked;

    //check forward
    if(next != nullptr && next->unchecked){
        Sink = Sink && previous->ifSink();
    }
    if(previous != nullptr && previous->unchecked){
        //check backward
        Sink = Sink && previous->ifSink();
    }
    unchecked = true;  //recover to unchecked for next time
    return Sink;
}














