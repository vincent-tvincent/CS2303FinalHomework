//
// Created by vince on 2022/3/2.
//

#include "singleLinkedList.h"
singleLinkedList::singleLinkedList(int value,singleLinkedList* next){
    singleLinkedList::value = value;
    singleLinkedList::next = next;
}

bool singleLinkedList::ifInclude(int value){
    bool result = singleLinkedList::value == value;
    if(next != nullptr){
        result = result || next->ifInclude(value);
    }
    return result;
}