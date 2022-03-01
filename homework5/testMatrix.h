#ifndef TM
#define TM
#include"matrix.h"
class testMatrix {
public:
	testMatrix();
	virtual ~testMatrix();
	bool test();
	bool testPrintBoard();
private:
	char* testOutputName;
	int testRow;
	int testCol;
	int testLength;
	bool scanBoard(int*,int);
	bool testGetPointer();
	bool testSet();
};
#endif