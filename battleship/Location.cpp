/*
 * Location.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Location.h"
Location::Location(Pair* Coordinate) {
    coordinate = Coordinate;
    waterOrNot = true;
    type = EMPTY;
    hasBeenShot = false;
    symbol = '~';
    actualSymbol = 'X';
}

Location::~Location() {
}

char Location::getSymbol()
{
	return symbol;
}
char Location:: getActualSymbol(){
    return actualSymbol;
}
void Location::setSymbol(char s)
{
	symbol = s;
}

Type Location:: getType(){
    return type;
}

Pair* Location:: getCoordinate(){
    return coordinate;
}
void Location:: getShot(){
    hasBeenShot = true;
    symbol = actualSymbol;
    if(isWater()){
        puts("\n-----------\n| miss :( |\n-----------\n");
    }else{
        puts("\n-----------------\n| hit target :) |\n-----------------\n");
    }
}

bool Location:: isWater(){
    return waterOrNot;
}