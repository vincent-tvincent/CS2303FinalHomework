//
// Created by vince on 2022/2/25.
//

#include "testBattleship.h"
testBattleship:: testBattleship(){
    testPair = new Pair;
    testType = CARRIER;
}

testBattleship:: ~testBattleship(){

}

bool testBattleship:: test(){
    bool ok = false;
    puts("\nprivate function and accessor will not be test, since battleship is the derived class from Location,\n so the functions in Location are also tested here");
    puts("start testing battleship");
    ok = testGetShot() && testIfSink();
    if(ok){
        puts("battleship pass the test");
    }else{
        puts("battleship does not pass the test");
    }
    return ok;
}

bool testBattleship::testGetShot(){
    bool ok = false;
    puts("start testing getShot()");
    Battleship* testObject = new Battleship(testType,testPair);
    testObject->getShot();
    ok = testObject->getSymbol() == testObject->getActualSymbol();
    if(ok){
        puts("get Shot() pass the test");
    }else{
        puts("getShot() does not pass the test");
    }
    return ok;
}

bool testBattleship:: testIfSink(){
    bool ok = false;
    puts("start testing ifSink()");
    Battleship* testObject0 = new Battleship(testType,testPair);
    Battleship* testObject1 = new Battleship(testType,testPair);
    Battleship* testObject2 = new Battleship(testType,testPair);
    testObject0->next=testObject1;
    testObject1->previous=testObject0;
    testObject1->next=testObject2;
    testObject2->previous=testObject1;
    bool notSink = testObject1->ifSink();
    testObject0->getShot();
    testObject1->getShot();
    testObject2->getShot();
    bool isSink = testObject1->ifSink();

    ok = !notSink && isSink;
    if(ok){
        puts("ifSink() pass the test");
    }else{
        puts("ifSink does not pass the test");
    }
    return ok;
}