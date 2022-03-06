//
// Created by vince on 2022/3/2.
//

#ifndef CS2303FINALHOMEWORK_LINKEDLIST_H
#define CS2303FINALHOMEWORK_LINKEDLIST_H


class LinkedList {
public:
    LinkedList(int, LinkedList*,LinkedList*);
    virtual ~LinkedList();
    bool ifInclude(int); // check if given value is in this linked list
    LinkedList* next;
    LinkedList* previous;
    int value;
};


#endif //CS2303FINALHOMEWORK_LINKEDLIST_H
