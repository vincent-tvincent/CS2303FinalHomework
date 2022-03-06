//
// Created by vince on 2022/3/2.
//
#include <iostream>
#include "LinkedList.h"
LinkedList::LinkedList(int Value,LinkedList* Previous, LinkedList* Next){
    previous = Previous;
    next = Next;
    value = Value;
}

LinkedList::~LinkedList(){}

bool LinkedList::ifInclude(int value){
    bool result = LinkedList::value == value;
    if(next != nullptr){
        result = result || next->ifInclude(value);
    }
    return result;
}