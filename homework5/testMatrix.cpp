#include "testMatrix.h"
#pragma warning(disable: 4996)
testMatrix::testMatrix() {
	testOutputName = "testOutput.txt";
	testRow = 5;
	testCol = 5l;
	testLength = testRow * testCol;
}
testMatrix::~testMatrix() {
}

bool testMatrix::test() {
	cout << "\nstart test Matrix" <<endl;
	bool ok = testGetPointer() && testSet() && testPrintBoard();
	if (ok) {
		cout << "Matrix pass the test" << endl;
	}
	else {
		cout << "Matrix doesn't pass the test" << endl;
	}
	return ok; 
}

bool testMatrix::testGetPointer() {
	cout << "start testing getPointer()" << endl;
	matrix* testObject = new matrix(testRow, testCol);
	bool ok = false;
	int row = rand() % testRow;
	printf("	test row is: %d\n", row);
	int col = rand() % testCol;
	printf("	test col is: %d\n", col);
	int expect = row + col * testRow;
	testObject->initForTest();
	testObject->onlyPrintBoard();
	ok = *(testObject->getPointer(row, col)) == expect;
	printf("value: %d expect£º%d \n", *(testObject->getPointer(row,col)),expect);
	if (ok) {
		cout << "getPointer() pass the test" << endl;
	}
	else {
		cout << "getPointer() doesn't pass the test" << endl;
	}
	return ok;
}

bool testMatrix::testSet() {
	cout << "start test set()" << endl;	
	matrix* testObject = new matrix(testRow, testCol);
	bool ok = false;
	for (int col = 0; col < testCol; col++) {
		for (int row = 0; row < testRow; row++) {
			testObject->set(row,col,1);
		}
	}
	testObject->onlyPrintBoard();
	int* thisBoard = testObject->getBoard();
	ok = scanBoard(thisBoard,1);

	if(ok){
		cout << "set() pass the test" << endl;
	}
	else {
		cout << "set() doesn't pass the test" << endl;
	}
	return ok;
}

bool testMatrix::scanBoard(int* board,int testValue) {
	bool ok = true;
	bool done = false;
	for (int i = 0; i < testLength && !done; i++) {
		if (*board != testValue) {
			ok = !ok;
			done = true;
		}
	}
	return ok;
}

bool testMatrix:: testPrintBoard() {
	cout << "start testing printBoard()" << endl;
	matrix* testObject = new matrix(testRow, testCol);
	testObject->initForTest();
	bool ok = false;
	testObject->printBoard(testOutputName);
	int* reference = testObject->getBoard();
	FILE* readBackFile = fopen(testOutputName,"r");
	int readBack = -1;
	bool done = false;
	for (int i = 0; i < testLength && !done;  i++) {
		fscanf(readBackFile,"%d",&readBack);
		printf("read back value: %d \n", readBack);
		ok = readBack == *(reference + i);
		if (!ok) { done = true; }
	}
	fclose(readBackFile);
	if (ok) {
		cout << "printBoard() pass the test\n" << endl;
	}
	else {
		cout << "printBoard() doesn't pass the test\n" << endl;
	}

	return ok;
}

