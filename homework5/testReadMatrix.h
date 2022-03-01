#pragma once
#ifndef TRM
#define TRM
#include "readMatrix.h"
class testReadMatrix
{
public: 
	testReadMatrix();
	bool test();
private:
	char* inputFile;
	char* outputFile;
	int* testMatrix;
	int testLength;
	bool testFillMatrix();
	bool testFixMatrix();
};
#endif

