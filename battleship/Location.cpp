/*
 * Location.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Location.h"

Location::Location() {
	waterOrNot = true;
    x = EMPTY;  //NULL if water
    hasBeenShot = false;
   symbol = '~';
}

Location::~Location() {
}

char Location::getSymbol()
{
	return symbol;
}
void Location::setSymbol(char s)
{
	symbol = s;
}
