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
#include "Seas.h"
class Battleship: Location{
public:
	Battleship(Type type);
    Battleship(Type type, linkedList<Battleship> start);
	virtual ~Battleship();
    void placeShip(Seas sea);
    bool ifSink();
    bool unchecked;
private:
	int compartments;
    linkedList<Battleship>* start;
    linkedList<Battleship>* shipBody;

};
#endif /* BATTLESHIP_H_ */

