/*
 * Fleets.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#include "Fleets.h"

Fleets::Fleets() {
	howManyCarriersA =1;//player a or player 0
	howManyCarriersB=1;//player b or player 1
	howManySubmarinesA=1;
	howManySubmarinesB=1;
	howManyBattleshipsA=1;
	howManyBattleshipsB=1;
	howManyCruisersA=1;
	howManyCruisersB=1;
	howManyDestroyersA=1;
	howManyDestroyersB=1;

}

Fleets::~Fleets() {
}

int Fleets::getHowManyCarriers(bool player)
{
	int answer = 0;
	if(!player)
	{
		answer = howManyCarriersA;
	}
	else
	{
		answer = howManyCarriersB;
	}
	return answer;
}
void Fleets::sink(bool player, ShipType s)
{
	if(!player)
	{
		//sink that ship of player 0
		switch(s) {
            case CARRIER:
                howManyCarriersA--;
                break;
            case DESTROYER:
                howManyDestroyersA--;
                break;
            case SUBMARINE:
                howManySubmarinesA--;
                break;
            case BATTLESHIP:
                howManyBattleshipsA--;
            default:
                puts("Unexpected ship type");
        }
	}
}
