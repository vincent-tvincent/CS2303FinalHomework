/*
 * Battleship.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#include "Battleship.h"
Battleship::Battleship(Type Type) {
   switch(Type) {
       Location();
       type = Type;
       case CARRIER:
           compartments = 5;
           symbol = 'A';
           break;
       case SUBMARINE:
           compartments = 2;
           symbol = 'S';
           break;
       case BATTLESHIP:
           symbol = 'B';
           compartments = 4;
           break;
       case CRUISER:
           compartments = 3;
           symbol = 'C';
           break;
       case DESTROYER:
           compartments = 3;
           symbol = 'D';
           break;
       default:
           compartments = 1;
           symbol = '~';
           break;
   }
   shipBody = new linkedList<Battleship>();
   start = shipBody;
   unchecked = true;
}
Battleship:: Battleship(Type type, linkedList<Battleship> start){

}
Battleship::~Battleship() {
}

bool Battleship:: ifSink(){
    bool Sink = hasBeenShot;//check
    shipBody->unchecked = false; //marked as checked;
    linkedList<Battleship>* nextBody = shipBody->next;
    linkedList<Battleship>* previousBody = shipBody->previous;

    //check forward
    if(nextBody != nullptr && nextBody->unchecked){
        Sink = Sink && nextBody->value->ifSink();
    }

    //check backward
    if(previousBody != nullptr && previousBody->unchecked){
        Sink = Sink && previousBody->value->ifSink();
    }
    unchecked = true;  //recover to unchecked for next time
    return Sink;
}













