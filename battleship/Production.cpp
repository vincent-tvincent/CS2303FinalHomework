/*
 * Production.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include <ctime>
#include "Production.h"

Production::Production() {
    HumanFirst = true;
    sea = new Seas();
    srand(time(0));
}

Production::~Production() {
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
	if(argc < 2) //no interesting information
	{
		puts("Usage: Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
    {
        printf("Found %d interesting arguments.\n", argc - 1);
        fflush(stdout);
        for (int i = 1; i < argc; i++) //don't want to read argv[0]
        {//argv[i] is a string
            //in this program our arguments are NR, NC, gens, filename, print and pause
            //because pause is optional, argc cou ld be 6 or 7
            //because print is optional (if print is not present, neither is pause) argc could be 5
            switch (i) {
                case 1:
                    //this is

                    if (strlen(argv[i]) > 1) {
                        puts("string is too long.");
                        fflush(stdout);
                        answer = false;
                    } else {
                        HumanFirst = (bool) strtol(argv[i], NULL, 10);
                        printf("result of who goes first was was player %d.\n", HumanFirst);
                        fflush(stdout);
                    }
                    break;


                default:
                    puts("Unexpected argument count.");
                    fflush(stdout);
                    answer = false;
                    break;
            }//end of switch
        }//end of for loop on argument count
        puts("after reading arguments");
        fflush(stdout);

        //get the ships placed, both human and computer
        bool humanPlacing = getYesNo("Do you want to place your own ships");
        if (humanPlacing) {
            getHumanSetup(sea);
        } else {
            doAutoPlacing(sea, false);
        }
        //display before each turn
        std::cout << "Game is ready for start" << std::endl;
        runGame();
        sea->displaySeas(false);
        //commence taking turns -- sounds like a while loop, because thi game is guaranteed to end

    }
	return HumanFirst;

}

void Production:: runGame(){
    bool done = false;
    while(!done) //take turns
    {
        if(HumanFirst) //human?
        {
            Pair* pP = new Pair();
            //ask the user for coordinates
            //scanf
            //double check they are reasonable
            pP->row = 0;//whatever the user said
            pP->col = 0;//whatever the user said
            //tell the seas about the coordinates
            //sea->takeCoordinates(pP);
            //Pair* newP = sea->getCoordinates();
            //find out whether any ship was sunk
            //find out whether the computer has now lost
            //if so, done
            //did we become done?
            done= true;
        }
        else
        {
            //did we become done?
            //randomly generate coordinates (will be reasonable)
            //tell the seas about the coordinates
            //find out whether any ship was sunk
            //find out whether the human has now lost
            //if so, done
            done=true;
        }
        HumanFirst = !HumanFirst;

    }//now done


    //print who won when done


}//end of else we have good arguments


bool Production::getYesNo(char const* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}
Type Production:: toType(char input) {
    Type result = EMPTY;
    switch (input) {
        case 'A':
            result = CARRIER;
            break;
        case 'S':
            result = SUBMARINE;
            break;
        case 'B':
            result = BATTLESHIP;
            break;
        case 'C':
            result = CRUISER;
            break;
        case 'D':
            result = DESTROYER;
            break;
        default:
            std::cout << "not a ship type" << std::endl;
            break;
    }
    return result;
}
int Production:: getCompartment(Type type){
    switch (type){
        case CARRIER:
            return 5;
        case 'S':
            return 2;
        case 'B':
            return 4;
        case 'C':
            return 3;
        case 'D':
            return 3;
        default:
            std::cout << "not a ship type" << std::endl;
            break;
    }
}
Type Production:: randShipType(){
    int choose = rand()%6;
    switch(choose){
        case 0:
            return CARRIER;
        case 1:
            return SUBMARINE;
        case 2:
            return BATTLESHIP;
        case 3:
            return CRUISER;
        case 4:
            return DESTROYER;
    }
}
void Production::getHumanSetup(Seas* Cs)
{
	//get from the human, where they want to place their ships
	Pair* coordinate = new Pair();
	coordinate->col = -1;
	coordinate->row = -1;
	char shipInput = ' ';
	Cs->displaySeas(true);
	puts("We're placing the battleship now, which kind of ship do you want to place: ");
	fflush(stdin);
	scanf("%c",&shipInput);
	Type shipType = toType(shipInput);
	bool horizontal = getYesNo("Is this ship horizontal?");

	if(horizontal)
	{
	    bool keep = true;
	    while(keep){
            puts("Give the westernmost column (from 0 to 8 inclusive)");
            scanf("%d", coordinate->col);
            puts("Give the row");
            scanf("%d", coordinate->row);
            if(sea->isEmpty(coordinate,1,horizontal,getCompartment(shipType))){
                sea->placeShip(1,horizontal,shipType,coordinate);
                keep = false;
            }else{
                std::cout << "area is not enough" <<std::endl;
            }
	    }

	}
	else
	{
	    bool keep = true;
	    while(keep){
            puts("Give the northernmost row (from 0 to 8 inclusive)");
            scanf("%d", coordinate->row);
            puts("Give the column");
            scanf("%d", coordinate->col);
            if(sea->isEmpty(coordinate,1,horizontal,getCompartment(shipType))){
                sea->placeShip(1,horizontal,shipType,coordinate);
                keep = false;
            }else{
                std::cout << "area is not enough" <<std::endl;
            }
	    }
	}
	Cs->displaySeas(true);
	Cs->displayInfo();
}

//TODO doPlacingForHuman
void Production::doAutoPlacing(Seas* Cs,bool player)
{
    srand(time(0));
    int shipAmount = rand()%6;
    for(int i = 0; i < shipAmount; i++){
        bool keep = true;
        while(keep){
            Pair* randCoordinate = new Pair;
            randCoordinate->row = rand()%10;
            randCoordinate->col = rand()%10;
            bool ifHorizontal = rand()%2;
            Type shipType = randShipType();
            if(sea->isEmpty(randCoordinate,player,ifHorizontal,getCompartment(shipType))){
                sea->placeShip(player,ifHorizontal,shipType,randCoordinate);
                keep = false;
            }
        }
    }
    if(!player){
        Cs->displaySeas(true);
        Cs->displayInfo();
    }else{
        Cs->displaySeas(false);
        Cs->displayInfo();
    }
}
