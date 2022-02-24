//
// Created by Vincent on 2022/2/22.
//

#ifndef CS2303FINALHOMEWORK_LINKEDLIST_H
#define CS2303FINALHOMEWORK_LINKEDLIST_H

template<typename T>
class linkedList {
public:
    linkedList(T* Value, linkedList* Previous, linkedList* Next);
    linkedList();
    virtual ~linkedList();
    linkedList* previous;
    linkedList* next;
    T* value;
    bool unchecked;
};

#endif //CS2303FINALHOMEWORK_LINKEDLIST_H
