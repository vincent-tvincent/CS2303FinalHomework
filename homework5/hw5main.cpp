#include "hw5main.h"
#include "test.h"
#pragma warning(disable: 4996)
int main(int argc, char* argv[]) {
	/*
	bool vaild = test();
	if (vaild) {
		readMatrix* demo = new readMatrix(argv[1],argv[2]);
		demo->printMatrix();
	}
	*/
	readMatrix* demo = new readMatrix(argv[1],argv[2]);
	demo->printMatrix();
}