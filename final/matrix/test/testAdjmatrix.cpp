//
// Created by vince on 2022/3/2.
//

#include "testAdjmatrix.h"
testAdjmatrix:: testAdjmatrix(){
}
bool testAdjmatrix:: test(){
    bool ok = false;
    puts("start test adjmatrix, since the superclass matrix have already been tested, \nthe function in this class will not be test");
    ok = testConnect() && testGetPath();
}

bool testAdjmatrix:: testConnect(){
    puts("\nstart test connect()");
    bool ok = false;
    adjmatrix* testObject = new adjmatrix(10);
    testObject->connect(0,9);
    ok = testObject->getPointer(0,9) && testObject->getPointer(9,0);
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
    adjmatrix* testObject = new adjmatrix(10);
    for(int i = 0; i < 9; i++){
        testObject->connect(i,i+1);
    }
    singleLinkedList* result = testObject->getPath();
    int tracker = 0;
    bool keepTrack = true;
    while(result->next != nullptr && keepTrack){
        ok = result->value == tracker;
        if(!ok){
            keepTrack = false;
        }
        tracker++;
    }
    ok = tracker == 9;
    if(ok){
        puts("getPath() pass the test");
    }else{
        puts("getPath() does not pass the test");
    }
    return ok;
}