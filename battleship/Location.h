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
    void getShot();
private:
	bool waterOrNot;
protected:
    bool hasBeenShot;
    char symbol;
    Type type;
};

#endif /* LOCATION_H_ */
