//
// Created by vincent on 2022/3/3.
//

#include "queue.h"
queue:: queue(){
    start = nullptr;
    end = start;
}

void queue:: enqueue(int value){
    end->next = new singleLinkedList(value,nullptr);
    end = end->next;
    if(start == nullptr){
        start = new singleLinkedList(value,end);
    }
}

int queue:: dequeue(){
    int output;
    if(start == nullptr) {
        output = -1;
    }
    else{
        output = start->value;
        start = start->next;
    }
    return output;
}

bool queue:: ifInclude(int target){
    bool result = false;
    singleLinkedList* tracker;
    *tracker = *start;
    while(tracker != nullptr && !result){
        result = tracker->value == target;
        tracker = tracker->next;
    }
    return result;
}



