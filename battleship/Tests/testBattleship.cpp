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
    bool notSink0 = testObject0->ifSink();
    puts("notSink0 finish");
    bool notSink1 = testObject1->ifSink();
    puts("notSink1 finish");
    bool notSink2 = testObject2->ifSink();
    puts("notSink2 finish");
    testObject0->getShot();
    testObject1->getShot();
    testObject2->getShot();
    bool isSink0 = testObject0->ifSink();
    puts("isSink0 finish");
    bool isSink1 = testObject1->ifSink();
    puts("isSink1 finish");
    bool isSink2 = testObject2->ifSink();
    puts("isSink2 finish");
    ok = !notSink0 && !notSink1 && !notSink2 && isSink0 && isSink1 && isSink2;
    if(ok){
        puts("ifSink() pass the test");
    }else{
        puts("ifSink does not pass the test");
    }
    return ok;
}