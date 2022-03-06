//
// Created by vincent on 2022/3/3.
//

#include "queue.h"
queue:: queue(){
    start = nullptr;
    end = start;
    size = 0;
}
queue:: ~queue(){}

void queue:: enqueue(int value){
    if(start == nullptr){
        start = new LinkedList(value,nullptr, nullptr);
        end = start;
    }else{
        end->next = new LinkedList(value, nullptr,nullptr);
        end = end->next;
    }
    size++;
}

int queue:: dequeue(){
    int output;
    if(size == 0) {
        output = -1;
    }else if(size == 1){
        output = start->value;
        end = nullptr;
        start = end;
        size--;
    }else{
        output = start->value;
        start = start->next;
        size--;
    }
    return output;
}




