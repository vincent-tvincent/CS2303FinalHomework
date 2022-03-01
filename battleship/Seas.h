/*
 * Seas.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef SEAS_H_
#define SEAS_H_
#include "GlobalTypes.h"
#include "Battleship.h"
#include "Fleets.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class Seas {
public:
	Seas();
	virtual ~Seas();
	int getSize();
	void displaySeas(bool cheat);
	void displayInfo();
	//void takeCoordinates(Pair* pP);
    void placeShip(int Player, bool ifHorizontal, Type shipType, Pair *coordinate);
    void shotTo(int player,Pair* coordinate);
    bool isEmpty(Pair* start,bool player,bool isHorizontal,int length);
    Location** getPointer(bool player, Pair* coordinate);
    bool player0Win();
    bool player1Win();
private:
    Fleets* fleet;
    int size;
    Location** seasP;
    int actualLocation(int player, Pair* coordinate);
};

#endif /* SEAS_H_ */
