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
#include "linkedList/linkedList.h"
class Battleship{
public:
	Battleship(ShipType type);
	virtual ~Battleship();
    void sinkShip();
private:
    ;
    char symbol;
    bool isSink;
	int compartments;
	linkedList<Location> shipBody;   
};
#endif /* BATTLESHIP_H_ */
