/*
 * Seas.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Seas.h"

Seas::Seas() {
	size = 10;
	seasP = (Location**) malloc (2*size*size*sizeof(Location*));//2 players, square board
	Location** seasP0 = seasP;  //for player 0
	Location** seasP1 = seasP+100; //for player 1
	for(int player = 0; player<2; player++)
	{
		for(int row= 0; row<size; row++)
		{
			for(int col = 0; col<size; col++)
			{
				if (player == 1)
				{
					seasP0 = seasP1;
				}
				Location** where = seasP0 + row*size+col;
				Location* x = (Location*) malloc(sizeof(Location));
				*where = x;
				x->setSymbol('~');
			}
		}

	}

}

Seas::~Seas() {
}

int Seas::getSize()
{
	int answer = -1;
	answer = size;
	return answer;
}
void Seas::setSize(int s)
{
	size = s;
}
void Seas::displaySeas()
{
	Location** seasP0 = seasP;  //for player 0
	Location** seasP1 = seasP+100; //for player 1
	for(int player = 0; player<2; player++)
	{
		for(int row= 0; row<size; row++)
		{
			for(int col = 0; col<size; col++)
			{
				if (player == 1)
				{
					seasP0 = seasP1;
				}
				Location** where = seasP0 + row*size+col;
				Location* x = *where; //take the location pointer from the address we calculated
				char symbol = x->getSymbol();
				printf("|%c", symbol);
			}
			printf("|\n");
		}
		printf("Finished player %d.\n", player); fflush(stdout);
	}

}
//TODO takeCoodrdinates
void Seas::takeCoordinates(Pair* pP)
{

}
