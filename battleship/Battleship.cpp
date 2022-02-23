/*
 * Battleship.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#include "Battleship.h"

Battleship::Battleship(ShipType type) {
   switch(type) {
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
           compartments = NULL;
           symbol = NULL;
           break;
   }
   isSink = true;
}
Battleship::~Battleship() {
}



