//
// Created by Vincent on 2022/3/3.
//

#ifndef CS2303FINALHOMEWORK_STACK_H
#define CS2303FINALHOMEWORK_STACK_H
#include "LinkedList.h"

class stack{
public:
    stack();
    virtual ~stack();
    void push(int); // push node to stack
    int pop(); // pop node from stack
    int size;
    LinkedList* start;
    LinkedList* end;
};


#endif //CS2303FINALHOMEWORK_STACK_H
