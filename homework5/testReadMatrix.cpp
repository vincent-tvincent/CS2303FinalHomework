#include "testReadMatrix.h"

/*as the printMatrix() function only simply call the function fillMatrix(), fixMatrix() and PrintBoard(),
  which will be test seperately, so there will be no test apply to printMatrix()*/
testReadMatrix::testReadMatrix() {
	inputFile = "test.txt";
	outputFile = "testout.txt";
	testLength = 5;
}

bool testReadMatrix:: test() {
	cout << "\nstart test readMatrix " << endl;
	bool ok = false;
	ok = testFillMatrix() && testFixMatrix();
	if (ok) {
		cout << "readMatrix pass the test" << endl;
	}
	else {
		cout << "readMatrix does not pass the test" << endl;
	}
	return ok; 
}


bool testReadMatrix:: testFillMatrix() {
	int testMatrix[5][5] = {2,2,2,2,2,
							1,2,2,2,2,
							0,1,2,2,2,
							1,0,1,2,2,
							0,1,0,1,2 };
	cout << "start testing fillMatrix()" << endl;
	bool ok = false;
	readMatrix* testObject = new readMatrix(inputFile,outputFile);
	testObject->fillMatrix();
	matrix* result = &(testObject->getMatrix());
	result->onlyPrintBoard();
	int row = 0;
	int col = 0;
	bool complete = true;
	while (col < testLength && complete){
		if (row < col) {
			int actualValue = *(result->getPointer(row, col));
			complete = actualValue == testMatrix[col][row];
			ok = complete;
			printf("at (%d,%d), ",row,col);
			printf("expected value: %d \n actural value: %d\n\n", testMatrix[col][row],actualValue);
			row++;
		}
		else {
			row = 0;
			col++;
		}
	} 
	
	if (ok) {
		cout << "fillMatrix() pass the test" << endl;
	}
	else {
		cout << "fillMatrix() doesn't pass the test" << endl;
	}
	return ok;
}

bool testReadMatrix::testFixMatrix() {
	cout << "start testing fixMatrix()" << endl;
	bool ok = false;
	// fillMatrix() and fixMatrix() will be automatically call during constructing.
	readMatrix* testObject = new readMatrix(inputFile,outputFile);
	testObject->fillMatrix();
	testObject->fixMatrix();
	matrix* result = &(testObject->getMatrix());
	result->onlyPrintBoard();
	int row = 0; 
	int col = 0;
	bool complete = true;
	while (col < testLength && complete) {
		if (row <= col) {
			complete = *(result->getPointer(row,col)) == *(result->getPointer(col,row));
			ok = complete;
			row++;
		}
		else {
			row = 0;
			col++;
		}
	}
	

	if (ok) {
		cout << "fixMatrix() pass the test\n" << endl;
	}
	else {
		cout << "fixMatrix() doesn't pass the test\n" << endl;
	}
	return ok;
}
