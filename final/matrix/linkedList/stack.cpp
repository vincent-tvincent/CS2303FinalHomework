//
// Created by Vincent on 2022/3/3.
//
#include"../../io.h"
#include "stack.h"
stack::stack(){
    start = nullptr;
    end = start;
    size = 0;
}
stack:: ~stack(){}
void stack::push(int value){
    if(start == nullptr){
        start = new LinkedList(value,nullptr,nullptr);
        end = start;
    }else{
        end->next = new LinkedList(value,end,nullptr);
        end = end->next;
    }
    size++;
}

int stack::pop(){
    int output;
    if(size == 0){
        output = -1;
    }else if(size == 1){
        output = end->value;
        start = nullptr;
        end = start;
        size--;
    }else{
        output = end->value;
        end = end->previous;
        end->next = nullptr;
        size--;
    }
    return output;
}