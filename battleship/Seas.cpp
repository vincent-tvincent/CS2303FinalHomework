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
    seasP = (Location**) malloc(2*size*size*sizeof(Location*));
	Location** seasP0 = seasP;  //for player 0
	Location** seasP1 = seasP+size*size; //for player 1
    Pair* coordinate = new Pair;
    coordinate->row = 0;
    coordinate->col = 0;
    for(int i = 0; i < size*size; i++){
        Location** P0 = seasP0 + i;
        Location** P1 = seasP1 + i;
        *P0 = new Location(coordinate);
        *P1 = new Location(coordinate);
        coordinate->row ++;
        if(coordinate->row == size){
            coordinate->row = 0;
            coordinate->col ++;
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

Location** Seas:: getPointer(bool player, Pair* coordinate){
    int movement = coordinate->row + coordinate->col*10;
    if(player){
        movement += 100;
    }
    return seasP + movement;
}

void Seas:: placeShip(int player, bool ifHorizontal, Type shipType, Pair* coordinate){
    Battleship* newShip = new Battleship(shipType, coordinate);
    *(seasP + actualLocation(player,newShip->getCoordinate())) = newShip;
    int restLength = newShip->getCompartments() - 1;
    Pair nextCoordinate = *coordinate;
    for(int i = 0; i < restLength; i++){
        printf("current ship coordinate: %d, %d\n", newShip->getCoordinate()->row,newShip->getCoordinate()->col);
        if(ifHorizontal){
            nextCoordinate.row += 1;
        }else{
            nextCoordinate.col += 1;
        }
        printf("expected next ship coordinate: %d, %d\n", nextCoordinate.row,nextCoordinate.col);
        Battleship* nextShip = new Battleship(shipType,&nextCoordinate);
        printf("next ship coordinate: %d, %d\n", nextShip->getCoordinate()->row, nextShip->getCoordinate()->col);
        newShip->next = nextShip;
        newShip->next->previous = newShip;
        newShip = newShip->next;
        Location** target = getPointer(player,newShip->getCoordinate());
        *target = newShip;
    }
    fleet->addShip(player,shipType);
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
    Pair trackerValue = *start;
    Pair* tracker = &trackerValue;
    for(int i = 0; i < length; i++){
        if(isHorizontal){
            tracker->row += i;
        }else{
            tracker->col += i;
        }
        printf("testing coordinate: %d, %d\n",tracker->row, tracker->col);
        Location* check = *getPointer(player,tracker);
        printf("is water? : %d\n", check->isWater());
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
