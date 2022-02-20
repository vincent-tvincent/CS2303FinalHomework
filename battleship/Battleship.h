/*
 * Battleship.h
 *
 *  Created on: Feb 16, 2022
 *      Author: theresesmith
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_
#include "Location.h"
class Battleship{
public:
	Battleship();
	virtual ~Battleship();

private:
	char symbol;
	int compartments;
};
#endif /* BATTLESHIP_H_ */
