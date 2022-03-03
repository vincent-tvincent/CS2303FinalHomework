//
// Created by vince on 2022/3/2.
//

#ifndef CS2303FINALHOMEWORK_SINGLELINKEDLIST_H
#define CS2303FINALHOMEWORK_SINGLELINKEDLIST_H


class singleLinkedList {
public:
    singleLinkedList(int,singleLinkedList*);
    bool ifInclude(int); // check if given value is in this linked list
    singleLinkedList* next;
    int value;
};


#endif //CS2303FINALHOMEWORK_SINGLELINKEDLIST_H
