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
#include "Seas.h"
#include "Fleets.h"
#include "GlobalTypes.h"
#include <stdio.h>
#define FILENAMELENGTHALLOWANCE (50)
class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool getYesNo(char const* query);
	void placing(Fleets*,bool isPlayer,bool isHorizontal,char type,int row,int col);
	void getHumanSetup(Seas* Cs);
	void doAutoPlacing(Seas* Cs,bool player);
    void runGame();
private:
    Type toType(char input);
    int getCompartment(Type type);
    Type randShipType();
    void showMax();
	void showShipAmount();
    Seas* sea;
    bool HumanFirst;
};

#endif /* PRODUCTION_H_ */
