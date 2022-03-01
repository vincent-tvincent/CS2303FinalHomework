#pragma once
#ifndef MA
#define MA
#include "../io.h"

class matrix
{
public:
	matrix(int,int);
	virtual ~matrix();
	void initForTest();
	void set(int, int, int);
	void printBoard(char*);
	int* getPointer(int, int);
	int* getBoard();
	void onlyPrintBoard();
private:
	char* addSpace(int);
	int* board;
	int rowLength;
	int colLength;
};
#endif

