//
// Created by vince on 2022/3/2.
//

#include "testAdjmatrix.h"
#include"../adjmatrix.h"
testAdjmatrix:: testAdjmatrix(){
}
testAdjmatrix:: ~testAdjmatrix(){}
bool testAdjmatrix:: test(){
    bool ok = false;
    puts("start test adjmatrix, since the superclass matrix have already been tested, \nthe function in this class will not be test");
    ok = testConnect() && testGetPath();
    if(ok){
        puts("adjMatrix pass the test");
    }else{
        puts("adjMatrix does not pass the test");
    }
    return ok;
}

bool testAdjmatrix:: testConnect(){
    puts("\nstart test connect()");
    bool ok = false;
    adjMatrix* testObject = new adjMatrix(10);
    testObject->connect(0,9);
    ok = *(testObject->getPointer(0,9)) && !*(testObject->getPointer(9,0)) ;
    testObject->onlyPrintBoard();
    if(ok){
        puts("test connect pass the test");
    }else{
        puts("test connect does not pass the test");
    }
    return ok;
}

bool testAdjmatrix:: testGetPath(){
    puts("\nstart test getPath()");
    bool ok = false;
    adjMatrix* testObject = new adjMatrix(10);
    testObject->connect(0,1);
    testObject->connect(1,0);
    testObject->connect(0,3);
    testObject->connect(3,0);
    testObject->connect(1,2);
    testObject->connect(2,1);
    testObject->onlyPrintBoard();
    queue* result = testObject->getPath(0);
    ok = result->dequeue() == 0 && result->dequeue() == 3 && result->dequeue() == 1 && result->dequeue() == 2;
    if(ok){
        puts("getPath() pass the test");
    }else{
        puts("getPath() does not pass the test");
    }
    return ok;
}