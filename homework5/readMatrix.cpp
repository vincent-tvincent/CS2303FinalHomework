#include "readMatrix.h"
#pragma warning(disable: 4996)
readMatrix::readMatrix(char* input, char*output) {
	inputName = input;
	outputName = output;
	endLength = -1;
}

readMatrix:: ~readMatrix() {}

void readMatrix::fillMatrix() {
	FILE* target = fopen(inputName,"r");
	//set the end of the loop
	fscanf(target,"%d",&endLength);
	Matrix = new matrix(endLength,endLength);
	//initialize loop elements
	int maxRead = 0;
	int counter = 0; 
	int readValue = -1; 
	while (maxRead < endLength) {
		if (counter < maxRead) {//judge if go to next column
			fscanf(target, "%d", &readValue);
			Matrix->set(counter, maxRead, readValue);
			counter++;//not go to next column
		}
		else {//go to next column
			counter = 0;
			maxRead++;
		} 
	} 
	fclose(target);
}

void readMatrix::fixMatrix() {
	//initialize the loop
	int row = 0;
	int col = 0;
	//start the loop 
	while (col < endLength) {//judge if go to next column 
		if (row <= col) { //not go to next column 
			// set adjenceny relationship	
			if (row == col) {
				Matrix->set(col,row,0);
			}
			else {
				Matrix->set(col, row, *(Matrix->getPointer(row, col)));
			}
			row++;
		}
		else {//go to next column 
			row = 0;
			col++;
		}
	}
}

void readMatrix::printMatrix() {
	fillMatrix();
	fixMatrix();
	Matrix->printBoard(outputName);
}

matrix readMatrix::getMatrix() {
	return *Matrix;
}
