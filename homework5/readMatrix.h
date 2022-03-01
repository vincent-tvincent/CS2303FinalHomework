#pragma once
#ifndef RM
#define RM
#include <cstdio>
#include <string.h>
#include "matrix.h"
class readMatrix
{
public:
	readMatrix(char*,char*	);
	virtual ~readMatrix();
	void fillMatrix();
	void fixMatrix();
	void printMatrix();
	matrix getMatrix();
	private:
	char* inputName;
	char* outputName;
	int endLength;
	matrix* Matrix;
};
#endif 


