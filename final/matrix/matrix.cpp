#include "matrix.h"
#pragma warning(disable: 4996)
matrix::matrix(int row, int col) {
	board = (int*) malloc(row*col*sizeof(int));
	rowLength = row;
	colLength = col;
}

matrix::~matrix() {}

void matrix::initForTest() {
	printf("row: %d col: %d \n", rowLength, colLength);
	for (int i = 0; i < rowLength * colLength; i++) {
		*(board + i) = i;
	}
	cout << "test board created: " << endl;
	onlyPrintBoard(); 
}

void matrix::set(int row, int col,int value) {
	int* target = getPointer(row,col);
	*target = value;
}

int* matrix::getPointer(int row, int col) {
	int* target = board + row + col * rowLength;
	return target;
}

void matrix::printBoard(char* fileName) {
	int endPoint = rowLength * colLength;
	int* tracker = board;
	FILE* output = fopen(fileName,"w");
	for (int i = 0; i < endPoint; i++) {
		printf("%d ", *tracker);
		fprintf(output,"%d ", *tracker);
		if ((i+1) % colLength == 0) { 
			puts("\n"); 
			fprintf(output,"\n");
		}
		tracker++;
	}
	fclose(output);
} 

void matrix::onlyPrintBoard() {
	cout << "start Print" << endl;
	int* tracker = board;
	int endPoint = rowLength * colLength;
	for (int i = 0; i < endPoint; i++) {   
		printf("%d ", *tracker);
		if ((i+1) % colLength == 0) {
		puts("\n");
		}
		tracker++;
	}
}

int* matrix::getBoard() {
	return board;
}
