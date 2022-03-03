//
// Created by vincent on 2022/3/3.
//

#ifndef CS2303FINALHOMEWORK_QUEUE_H
#define CS2303FINALHOMEWORK_QUEUE_H
#include "singleLinkedList.h"
class queue {
public:
    queue();
    void enqueue(int);
    int dequeue(); //dequeue value and return the value dequeued
    bool ifInclude(int); //check if include certain value
private:
    singleLinkedList* start;
    singleLinkedList* end;
};

#endif //CS2303FINALHOMEWORK_QUEUE_H
