/*
 * Production.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Production.h"

Production::Production() {
    HumanFirst = true;
    sea = new Seas();
    fleet = new Fleets();
}

Production::~Production() {
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
	if(argc <=1) //no interesting information
	{
		puts("Usage: Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc cou ld be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch(i)
			{
			case 1:
				//this is

				if(strlen(argv[i])>1)
				{
					puts("string is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					HumanFirst = (bool)strtol(argv[i], NULL, 10);
					printf("result of who goes first was was player %d.\n", HumanFirst);
					fflush(stdout);
				}
				break;


			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);

		//get the ships placed, both human and computer
		bool humanPlacing = getYesNo("Do you want to place your own ships");
		if(humanPlacing)
		{
			getHumanSetup(sea, fleet);
		}
		else
		{
            doAutoPlacing(sea,false ,fleet);
		}
		//display before each turn
		sea->displaySeas();
		//commence taking turns -- sounds like a while loop, because thi game is guaranteed to end
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
				sea->takeCoordinates(pP);
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

	return HumanFirst;
}

bool Production::getYesNo(char* query)
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
void Production::getHumanSetup(Seas* Cs, Fleets* fleets)
{
	//get from the human, where they want to place their ships
	int col = -1;
	int row = -1;
	puts("We're placing the battleship now.");
	bool horizontal = getYesNo("Is this ship horizontal?");
	if(horizontal)
	{
		puts("Give the westernmost column (from 0 to 8 inclusive)");
		scanf("%d", &col);
		puts("Give the row");
		scanf("%d", &row);
		//TODO set as many columns eastward for the size of a battleship
	}
	else
	{
		puts("Give the northernmost row (from 0 to 8 inclusive)");
		scanf("%d", &row);
		puts("Give the column");
		scanf("%d", &col);
		//TODO set as many rows southward for the size of a battleship
	}
	Cs->displaySeas();

}
//TODO doPlacingForHuman
void Production::doAutoPlacing(Seas* Cs,bool isPlayer, Fleets* fleets)
{

}
