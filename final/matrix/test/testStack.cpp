//
// Created by Vincent on 2022/3/4.
//

#include "testStack.h"
testStack:: testStack(){
}

testStack::~testStack(){}

bool testStack:: test(){
    puts("start testing stack");
    bool ok = false;
    ok = testPush() && testPop();
    if(ok){
        puts("stack pass the test");
    }else{
        puts("stack does not pass the test");
    }
    return ok;
}

bool testStack:: testPush(){
    puts("\nstart testing push()");
    bool ok = false;
    stack* testObject = new stack();
    testObject->push(1);
    ok = testObject->start->value == 1;
    testObject->push(2);
    ok = testObject->end->value == 2;
    if(ok){
        puts("push() pass the test ");
    }else{
        puts("push() does not pass the test");
    }
    return ok;
}

bool testStack:: testPop(){
    puts("\nstart testing pop()");
    bool ok = false;
    stack* testObject = new stack();

    for(int i = 0; i < 3; i++) testObject->push(i);
    bool keepTest = true;
    for(int i = 2; i > -2 && keepTest; i--){
        printf("expected value: %d \n",i);
        ok = testObject->pop() == i;
        keepTest = ok;
    }
    ok = ok && testObject->size == 0;
    if(ok){
        puts("pop() pass the test");
    }else{
        puts("pop() does not pass  the test");
    }
    return ok;
}
