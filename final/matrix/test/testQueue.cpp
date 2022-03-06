//
// Created by Vincent on 2022/3/5.
//

#include "testQueue.h"
testQueue:: testQueue(){}
testQueue:: ~testQueue(){}
bool testQueue:: test(){
    puts("start testing queue");
    bool ok = false;
    ok = testEnqueue() && testDequeue();
    if(ok){
        puts("queue pass the test");
    }else{
        puts("queue does not pass the test");
    }
    return ok;
}

bool testQueue:: testEnqueue(){
    puts("start testing enqueue()");
    bool ok = false;
    queue* testObject = new queue();
    testObject->enqueue(1);
    testObject->enqueue(2);
    ok = testObject->start->value ==1 && testObject->start->next->value == 2;
    if(ok){
        puts("enqueue() pass the test");
    }else{
        puts("enqueue() does not pass the test");
    }
    return ok;
}

bool testQueue:: testDequeue(){
    puts("start testing dequeue()");
    bool ok = false;
    queue* testObject = new queue();
    bool keepCheck = true;
    for(int i = 0; i < 3; i++){
        testObject->enqueue(i);
    }
    for(int i = 0;i < 3 && keepCheck; i++){
        ok = testObject->dequeue() == i;
        keepCheck = ok;
    };
    ok = ok && testObject->size == 0;
    if(ok){
        puts("dequeue() pass the test");
    }else{
        puts("dequeue() does not pass the test");
    }
    return ok;
}