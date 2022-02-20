/*
 * LinkedList.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: theresesmith
 */
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	begin1 = makeEmptyLinkedList();
	begin2 = makeEmptyLinkedList2();

}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

bool LinkedList::isEmpty()
{
	bool ans = false;
	if(begin1->payP == (Payload*)0)
	{
		ans = true;
	}
	return ans;
}
bool LinkedList::isEmpty2()
{
	bool ans = false;
	if(begin2->payP == (Payload2*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* LinkedList::makeEmptyLinkedList()
{
	LLNode* nbg = (LLNode*) malloc(sizeof(LLNode));
	nbg->next = (struct LLNode*)0;
	nbg->prev = (struct LLNode*)0;
	nbg->payP = (Payload*)0;

	return nbg;
}
LLNode2* LinkedList::makeEmptyLinkedList2()
{
	LLNode2* nbg = (LLNode2*) malloc(sizeof(LLNode2));
	nbg->next = (struct LLNode2*)0;
	nbg->prev = (struct LLNode2*)0;
	nbg->payP = (Payload2*)0;

	return nbg;
}
void LinkedList::savePayload(Payload* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty())
	{
		begin1->payP = mp;
	}
	else
	{
		LLNode* temp = begin1;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();  //<- this now sets begin1, which it should not
		newList->payP = mp;
		temp->next = (struct LLNode*)newList;
		newList->prev = (struct LLNode*) temp;
	}
}
void LinkedList::savePayload2(Payload2* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty2())
	{
		begin2->payP = mp;
	}
	else
	{
		LLNode2* temp = begin2;
		while(temp->next)
		{
			temp=(LLNode2*)temp->next;
			puts("traversing 2");fflush(stdout);
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode2* newList = makeEmptyLinkedList2();
		newList->payP = mp;
		temp->next = (struct LLNode2*) newList;
		newList->prev = (struct LLNode2*) temp;
	}
}

Payload* LinkedList::dequeueLIFO()
{
	Payload* payP = (Payload*)0;
	if(isEmpty())
	{
		puts("Trying to dequeue from empty.");
	}
	else
	{

		LLNode* temp = begin1;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element


		payP = temp->payP;
		temp->payP = (Payload*)0;//removing what is being dequeued
		int pRoomNumber = payP->getNodeNumber();
		//printf("Room being returned is %d\n", pRoomNumber); fflush(stdout);
		//remove the last, now empty, element
		if(temp->prev)
		{
			temp=(LLNode*)temp->prev;
			//free(temp->next);
			int tRoomNumber = payP->getNodeNumber();
			//printf("end of queue is room %d\n", tRoomNumber);fflush(stdout);
			temp->next = (struct LLNode*)0;
		}
		else
		{
			puts("Queue is now empty");
		}
		//puts("returning from dequeue");fflush(stdout);
	}

	return payP;
}

backFromDQFIFO* LinkedList::dequeueFIFO()
{
	backFromDQFIFO* fp = (backFromDQFIFO*) malloc(sizeof(backFromDQFIFO));
	if(begin1->next == (struct LLNode*)0)
	{
		//list of length 1 or 0
		fp->newQHead= begin1;
	}
	else
	{
		fp->newQHead= (LLNode*) begin1->next;
	}
	fp->mp= begin1->payP;//all return values are set
	if(begin1->next != (struct LLNode*)0)
	{
		//length list is >1

	}

	return fp;
}
void LinkedList::printHistory()
{
	puts("Printing history");
	if(begin2->payP ==(Payload2*)0)
	{
		puts("Empty list");
	}
	else
	{
		//traverse the list, printing as we go
		float treasureSubtotal = 0.0;
		int room = -1;
		LLNode2* temp = begin2;
		while(temp->next)
		{
			room =temp->payP->roomNumber;
			treasureSubtotal+= temp->payP->treasure;
			printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
			temp=(LLNode2*)temp->next;

		}
		room =temp->payP->roomNumber;
		treasureSubtotal+= temp->payP->treasure;
		printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
	}
}
LLNode* LinkedList::removeFromList(Payload* pP)
{
	LLNode* retHead = begin1;//only changes if first element gets removed
	//find the payload
	//use the structure of a list, namely, list is empty or element followed by list
	if(isEmpty())
	{
		//nothing to do
	}
	else
	{
		//puts("list is not empty");fflush(stdout);
		LLNode* altHead = (LLNode*)begin1->next;
		//find the item, if it is there
		LLNode* temp = begin1;
		bool done = false;
		while((!done) && temp->next)
		{
			//are we there yet?
			if(temp->payP == pP)
			{
				done=true;
				//puts("found it 1");fflush(stdout);
			}
			else
			{
				temp=(LLNode*)temp->next;
			}
		}
		//either we are pointing to the correct element, or we are at the end, or both
		if((temp->payP) == pP)
		{
			//puts("found it 2");fflush(stdout);
			//found it, remove it
			//are we at the beginning?
			if(temp == begin1)
			{  //found it at the first element
				//puts("found it at first element");fflush(stdout);
				//is the list of length 1?
				if(!(temp->next))
				{//if there is no next
					//remove payload, return empty list
					begin1->payP = (Payload*)0;
				}
				else //not of length 1
				{ //not freeing the Payload, but freeing the first list element
					//puts("found it at first element of list with length > 1");fflush(stdout);
					//free(hP);
					retHead = altHead;
				}
			}
			else //not found at first location in list
			{
				//puts("found it not at first element");fflush(stdout);
				//save the linkages
				//found element has a next
				//found element has a prev
				//participant before has a next
				//participant after has a prev
				LLNode* prevPart = (LLNode*) temp->prev;//non-zero because not at first element
				LLNode* nextPart = (LLNode*) temp->next;//could be zero, if found at last element
				prevPart->next = (struct LLNode*) nextPart;//RHS is 0 if at end
				//puts("after setting the next of the previous");fflush(stdout);
				// printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
				if((bool)nextPart)//don't need guarded block if element found at end of list
				{
					//puts("before setting the previous of the next");fflush(stdout);
					nextPart->prev = (struct LLNode*) prevPart;

				}
				//puts("after handling the  previous of the next");fflush(stdout);
			}//end of not found at first location
		}//end of found it
		else
		{
			//didn't find it
			//puts("did not find it");fflush(stdout);
			//nothing to do
		}//end did not find it
	}
	//printf("Returning %p\n", retHead); fflush(stdout);
	return retHead;
}
LLNode* LinkedList::getBegin1()
{
	return begin1;
}
LLNode2* LinkedList::getBegin2()
{
	return begin2;
}

void LinkedList::printHistory1()
{
	puts("Printing history 1");
	if(begin1->payP ==(Payload*)0)
	{
		puts("Empty list");
	}
	else
	{
		//traverse the list, printing as we go

		int room = -1;
		LLNode* temp = begin1;
		while(temp->next)
		{
			room =temp->payP->getNodeNumber();

			printf("The node was %d, .\n", room);
			temp=(LLNode*)temp->next;

		}
		room =temp->payP->getNodeNumber();

		printf("The room was %d.\n", room);
	}
}
void LinkedList::setBegin1(LLNode* p)
{
	begin1 = p;
}
void LinkedList::setBegin2(LLNode2* p)
{
	begin2 = p;
}
