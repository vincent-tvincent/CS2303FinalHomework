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
		puts("place provide command line argument");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
    {
        printf("command line argument received\n", argc - 1);
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
            doAutoPlacing(sea, 1);
        }
        puts("player0 placing");
        doAutoPlacing(sea,0);
        //display before each turn
        std::cout << "Game is ready for start" << std::endl;
        runGame();
        //commence taking turns -- sounds like a while loop, because thi game is guaranteed to end

    }
	return HumanFirst;

}

void Production:: runGame(){
    puts("game start");
    bool done = false;
    while(!done) //take turns
    {

        if(HumanFirst) //human?
        {
            puts("can display");
            sea->displaySeas(false);
            sea->displayInfo();
            puts("player1's turn\n");
            fflush(stdin);
            Pair* target = new Pair;
            puts("choose target to shot");
            bool keepRead = true;
            while(keepRead){
                std::cout<<"row: "<<scanf("%d",&target->row)<<std::endl;
                fflush(stdin);
                std::cout<<"col: "<<scanf("%d",&target->col)<<std::endl;
                fflush(stdin);
                if(target->row > 9 || target->col > 9){
                    puts("coordinate does not exist");
                }else{
                    puts("launched");
                    printf("target coordinate: %d, %d\n",target->row,target->col);
                    sea->shotTo(0,target);
                    keepRead = false;
                }
            }

        }
        else{
            puts("player0's turn\n");
            srand(time(0));
            Pair* target = new Pair;
            target->row = rand() % 10;
            target->col = rand() % 10;
            printf("target coordinate: %d, %d\n",target->row,target->col);
            sea->shotTo(1,target);
        }
        HumanFirst = !HumanFirst;
        if(sea->player0Win() || sea->player1Win()){
            done = true;
        }
    }
    //now done
    //print who won when done
    if(sea->player0Win()){
        puts("\n*********************\nplayer 0 win the game\n*********************\n");
    }else if(sea->player1Win()){
        puts("\n*********************\nplayer 1 win the game\n*********************\n");
    }
}


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
            puts("not a shipType");
            break;
    }
    return result;
}
int Production:: getCompartment(Type type){
    switch (type){
        case CARRIER:
            return 5;
        case SUBMARINE:
            return 2;
        case BATTLESHIP:
            return 4;
        case CRUISER:
            return 3;
        case DESTROYER:
            return 3;
        default:
            std::cout << "not a ship type" << std::endl;
            break;
    }
    return -1;
}
Type Production:: randShipType(){
    int choose = rand()%5;
    Type randType = EMPTY;
    switch(choose){
        case 0:
            randType = CARRIER;
            break;
        case 1:
            randType = SUBMARINE;
            break;
        case 2:
            randType = BATTLESHIP;
            break;
        case 3:
            randType = CRUISER;
            break;
        case 4:
            randType = DESTROYER;
            break;
    }
    return randType;
}
void Production::getHumanSetup(Seas* Cs) {
    //get from the human, where they want to place their ships
    Pair *coordinate = new Pair();
    coordinate->col = -1;
    coordinate->row = -1;
    char shipInput = ' ';
    bool keepPlacing = true;
    while (keepPlacing) {
        puts("We're placing the battleship now, which kind of ship do you want to place: ");
        fflush(stdin);
        bool keepGetType = true;
        Type shipType = EMPTY;
        while(keepGetType){
            std::cout << "A/Carrier S/Submarine B/Battleship C/Cruiser D/destroyer : " << scanf("%c", &shipInput)<< std::endl;
            fflush(stdin);
            shipType = toType(shipInput);
            Type empty = EMPTY;
            if(shipType != empty){
                keepGetType = false;
            }
        }
        bool horizontal = getYesNo("Is this ship horizontal?");
        bool keepInput = true;
        while (keepInput) {
            bool keepAsk = true;
            Cs->displaySeas(true);
            while(keepAsk){
                fflush(stdin);
                std::cout<<"please provide row: "<<scanf("%d",&coordinate->row)<<std::endl;
                std::cout<<"please provide column: "<<scanf("%d",&coordinate->col)<<std::endl;
                fflush(stdin);
                if(coordinate->row < 8 && coordinate->row > -1 && coordinate->col < 8 && coordinate->col > -1){
                    if(sea->isEmpty(coordinate,1,horizontal,getCompartment(shipType))){
                        sea->placeShip(1,horizontal,shipType,coordinate);
                        keepInput = false;
                    }else{
                        puts("place is not enough");
                    }
                    keepAsk = false;
                }else{
                    puts("battleship need at lest 2 blocks, please enter an valid coordinate");
                }
            }
        }
        Cs->displaySeas(true);
        Cs->displayInfo();
        Location* shipLocation = *sea->getPointer(1,coordinate);
        Pair* actualCoordinate = shipLocation->getCoordinate();
        printf("the ship is placed at %d, %d\n",actualCoordinate->row,actualCoordinate->col);
        keepPlacing = getYesNo("do you place another ship?");
    }
}
void Production::doAutoPlacing(Seas* Cs,bool player)
{
    printf("auto placing for player%d\n",player);
    srand(time(0));
    int shipAmount = rand()%5 + 1;
    for(int i = 0; i < shipAmount; i++){
        Pair* randCoordinate = new Pair;
        randCoordinate->row = rand()%8;
        randCoordinate->col = rand()%8;
        bool ifHorizontal = rand()%2;
        Type randType = randShipType();
        bool keepPlacing = true;
        while(keepPlacing){
            if(sea->isEmpty(randCoordinate,player,ifHorizontal,getCompartment(randType))){
                sea->placeShip(player,ifHorizontal,randType,randCoordinate);
                keepPlacing = false;
            }else{
                randCoordinate->row = rand()%8;
                randCoordinate->col = rand()%8;
                ifHorizontal = rand()%2;
            }
        }
    }
    Cs->displaySeas(true);
    Cs->displayInfo();
}
