/*
 * Location.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef LOCATION_H_
#define LOCATION_H_
#include "Fleets.h"
#include "string.h"
#include "GlobalTypes.h"
class Location {
public:
	Location(Pair* coordinate);
	virtual ~Location();
    char getSymbol();
    char getActualSymbol();
    void setSymbol(char s);
    void getShot();
    bool isWater();
    Type getType();
    Pair* getCoordinate();
private:
	Pair* coordinate;
protected:
    bool waterOrNot;
    char actualSymbol;
    bool hasBeenShot;
    char symbol;
    Type type;
};

#endif /* LOCATION_H_ */
