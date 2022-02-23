/*
 * Location.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef LOCATION_H_
#define LOCATION_H_
#include "Fleets.h"

typedef struct
{
	int row;
	int col;
}Pair;

class Location {
public:
	Location();
	virtual ~Location();
    char getSymbol();
    void setSymbol(char s);
    void getShort();
private:
	bool waterOrNot;
	ShipType x;  //NULL if water
	bool hasBeenShot;
	char symbol;
};

#endif /* LOCATION_H_ */
