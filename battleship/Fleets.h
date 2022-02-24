/*
 * Fleets.h
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#ifndef FLEETS_H_`
#define FLEETS_H_

#include <stdio.h>

typedef enum
{
    EMPTY,
	CARRIER,
	SUBMARINE,
	BATTLESHIP,
	CRUISER,
	DESTROYER
}Type;

class Fleets {
public:
	Fleets();
	virtual ~Fleets();
	int getHowManyCarriers(bool player);
	void sink(bool player, Type s);


private:
	int howManyCarriersA;//player a or player 0
	int howManyCarriersB;//player b or player 1
	int howManySubmarinesA;
	int howManySubmarinesB;
	int howManyBattleshipsA;
	int howManyBattleshipsB;
	int howManyCruisersA;
	int howManyCruisersB;
	int howManyDestroyersA;
	int howManyDestroyersB;

};

#endif /* FLEETS_H_ */
