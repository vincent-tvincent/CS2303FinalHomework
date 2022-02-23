/*
 * Production.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
//#include "AdjMat.h"
//#include "Room.h"
//#include "../linkedList/Terminal.h"
//#include "../linkedList/LinkedList.h"
#include "Seas.h"
#include "Fleets.h"

#include <stdio.h>
#define FILENAMELENGTHALLOWANCE (50)

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);

	bool getYesNo(char* query);
	void placing(Fleets*,bool isPlayer,bool isHorizontal,char type,int row,int col);
	void getHumanSetup(Seas* Cs, Fleets* fleets);
	void doAutoPlacing(Seas* Cs,bool isPlayer, Fleets* fleets);


private:
	void showMax();
    Fleets* fleet;
    Seas* sea;
    bool HumanFirst;
};

#endif /* PRODUCTION_H_ */
