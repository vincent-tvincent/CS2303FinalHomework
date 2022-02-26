/*
 * Battleship.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

#include "Location.h"
#include "Fleets.h"
#include "Seas.h"
#include <iostream>
class Battleship: public Location{
public:
	Battleship(Type type, Pair* coordinate);
	virtual ~Battleship();
    bool ifSink();
    bool unchecked;
    Battleship* next;
    Battleship* previous;
    int getCompartments();
private:
    void setType(Type t);
    int compartments;
};
#endif /* BATTLESHIP_H_ */
