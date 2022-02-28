/*
 * Fleets.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: theresesmith
 */

#include <cstdlib>
#include "Fleets.h"
Fleets::Fleets() {
    player0ShipNum = (int*) malloc(5*sizeof(int*));
	player1ShipNum = (int*) malloc(5*sizeof(int*));
	for(int i = 0; i < 5; i++){
	    *(player0ShipNum + i) = 0;
	    *(player1ShipNum + i) = 0;
	}
}

Fleets::~Fleets() {
}

int Fleets::getHowManyShips(bool player,Type shipType)
{
    int index = shipType - 1;
	int answer = 0;
	if(!player)
	{
		answer = *(player0ShipNum + index);
	}
	else
	{
		answer = *(player1ShipNum + index);
	}
	return answer;
}

void Fleets:: addShip(bool player, Type shipType){
    int index = shipType - 1;
    if(!player)
    {
        *(player0ShipNum + index) += 1;
    }
    else
    {
        *(player1ShipNum + index) += 1;
    }
}

void Fleets:: sinkShip(bool player, Type shipType){
    int index = shipType - 1;
    if(!player)
    {
        *(player0ShipNum + index) -= 1;
    }
    else
    {
        *(player1ShipNum + index) -= 1;
    }
}

bool Fleets:: playerLost(bool player){
    int* target = nullptr;
    if(!player){
        target = player0ShipNum;
    }else{
        target = player1ShipNum;
    }
    for(int i = 0; i < 5; i++){
        if(*(target + i)){
            return false;
        }
    }
    return true;
}

void Fleets:: displayInfo(){
    printf("\nPlayer0    A:%d S:%d B:%d C:%d D:%d\n",*(player0ShipNum),*(player0ShipNum+1),*(player0ShipNum+2),*(player0ShipNum+3),*(player0ShipNum+4),*(player0ShipNum+5));
    printf("Player1    A:%d S:%d B:%d C:%d D:%d\n",*(player1ShipNum),*(player1ShipNum+1),*(player1ShipNum+2),*(player1ShipNum+3),*(player1ShipNum+4),*(player1ShipNum+5));
}