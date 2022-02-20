/*
 * Seas.h
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#ifndef SEAS_H_
#define SEAS_H_

#include "Location.h"
#include <stdlib.h>
#include <stdio.h>

class Seas {
public:
	Seas();
	virtual ~Seas();
	int getSize();
	void setSize(int);
	void displaySeas();
	void takeCoordinates(Pair* pP);

private:
	int size;
	Location** seasP;
};

#endif /* SEAS_H_ */
