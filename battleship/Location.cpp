/*
 * Location.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Location.h"
Location::Location() {
	waterOrNot = true;
    type = EMPTY;
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

void Location:: getShot(){
    hasBeenShot = true;
    if(symbol == '~'){
        symbol = 'X';
    }
}