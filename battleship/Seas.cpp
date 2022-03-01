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
    printf("\n    placing ship at: %d,%d if is horizontal: %d\n",coordinate->row,coordinate->col,ifHorizontal);
    Battleship* newShip = new Battleship(shipType, coordinate);
    *(seasP + actualLocation(player,newShip->getCoordinate())) = newShip;
    int restLength = newShip->getCompartments() - 1;
    Pair nextCoordinate = *coordinate;
    for(int i = 0; i < restLength; i++){
        if(ifHorizontal){
            nextCoordinate.row += 1;
        }else{
            nextCoordinate.col += 1;
        }
        Battleship* nextShip = new Battleship(shipType,&nextCoordinate);
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
    printf("    need Length: %d\n",length);
    for(int i = 0; i < length; i++){
        if(isHorizontal){
            tracker->row ++;
            puts("row add 1");
        }else{
            tracker->col ++;
            puts("col add 1");
        }
        printf("tracker: %d, %d \n",tracker->row,tracker->col);
        Location* check = new Location(tracker);
        if(tracker->row < 10 && tracker->col < 10){
            check = *getPointer(player,tracker);
        }else{
            printf("\n!!!!!!!!!!!!!!!!\nblock invalid: %d, %d\n!!!!!!!!!!!!!!!!\n",tracker->row,tracker->col);
            return false;
        }
        if(!check->isWater()){
            printf("\n!!!!!!!!!!!!!!!!\nblock invalid: %d, %d\n!!!!!!!!!!!!!!!!\n",tracker->row,tracker->col);
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
        printf("player %d.\n", player); fflush(stdout);
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
                bool notWater = !(x->isWater());
                if(cheat && player == 1 && notWater){
                    symbol = x->getActualSymbol();
                }else{
                    symbol = x->getSymbol();
                }
                printf("|%c", symbol);
            }
            printf("|\n");
        }
	}
}

void Seas::displayInfo(){
    fleet->displayInfo();
}
