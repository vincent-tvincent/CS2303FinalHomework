/*
 * Seas.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: theresesmith
 */

#include "Seas.h"
Seas::Seas() {
    fleet = new Fleets();
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

int Seas:: actualLocation(int Player,Pair* coordinate){

    int movement = coordinate->row + coordinate->col*10;
    if(Player == 1){
        movement += 100;
    }
    return movement;
}

Location** Seas:: getPointer(Pair* coordinate,bool player){
    int movement = coordinate->row + coordinate->col*coordinate->row;
    if(player){
        movement += 100;
    }
    return seasP + movement;
}

void Seas:: placeShip(int player, bool ifHorizontal, Type shipType, Pair* coordinate){
    Battleship* newShip = new Battleship(shipType, coordinate);
    *(seasP + actualLocation(player,newShip->getCoordinate())) = newShip;
    int restLength = newShip->getCompartments() - 1;
    Pair* nextCoordinate = coordinate;
    for(int i = 0; i < restLength; i++){
        if(ifHorizontal){
            nextCoordinate->row += 1;
        }else{
            nextCoordinate->col += 1;
        }
        newShip->next = new Battleship(shipType,nextCoordinate);
        newShip->next->previous = newShip;
        newShip = newShip->next;
        Location** target = getPointer(coordinate,player);
        *target = newShip;
        fleet->addShip(player,shipType);
        std::cout << "ship placed" << std::endl;
    }
}

void Seas:: shot(int player, Pair* coordinate){
    Location* target = *(seasP + actualLocation(player,coordinate));
    target->getShot();
    bool sink = false;
    if(!target->isWater()){
        sink = ((Battleship*) target)->ifSink();
    }
    if(sink){
        fleet->sinkShip(player,target->getType());
    }
}

bool Seas:: isEmpty(Pair* start,bool player,bool isHorizontal,int length){
    for(int i = 0; i < length; i++){
        if(isHorizontal){
            start->row += i;
        }else{
            start->col += i;
        }
        Location* check = *getPointer(start,player);
        if(!check->isWater()){
            return false;
        }
    }
    return true;
}

void Seas::displaySeas(bool cheat)
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
				char symbol;
				if(cheat && row*size+col > 99){
				    symbol = x->getActualSymbol();
				}else{
                    symbol = x->getSymbol();
				}
				printf("|%c", symbol);
			}
			printf("|\n");
		}
		printf("Finished player %d.\n", player); fflush(stdout);
	}
}

void Seas::displayInfo(){
    fleet->displayInfo();
}
