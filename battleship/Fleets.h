/*
 * Fleets.h
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#ifndef FLEETS_H_
#define FLEETS_H_

#include <stdio.h>
#include <stdlib.h>
#include"GlobalTypes.h"

class Fleets {
public:
	Fleets();
	virtual ~Fleets();
	int getHowManyShips(bool player,Type shipType);
	void addShip(bool player,Type shipType);
	void sinkShip(bool player,Type shipType);
	bool playerLost(bool player);
	void displayInfo();
private:
    int* player0ShipNum;
    int* player1ShipNum;


};

#endif /* FLEETS_H_ */
