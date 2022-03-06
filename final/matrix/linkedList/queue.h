//
// Created by vincent on 2022/3/3.
//

#ifndef CS2303FINALHOMEWORK_QUEUE_H
#define CS2303FINALHOMEWORK_QUEUE_H
#include "LinkedList.h"
#include<iostream>
class queue {
public:
    queue();
    virtual ~queue();
    void enqueue(int);
    int dequeue(); //dequeue value and return the value dequeued
    int size;
    LinkedList* start;
    LinkedList* end;
};

#endif //CS2303FINALHOMEWORK_QUEUE_H
