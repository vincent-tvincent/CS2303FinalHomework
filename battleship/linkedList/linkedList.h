//
// Created by Vincent on 2022/2/22.
//

#ifndef CS2303FINALHOMEWORK_LINKEDLIST_H
#define CS2303FINALHOMEWORK_LINKEDLIST_H
template<class T>
class linkedList {
public:
    linkedList(T Value, linkedList Previous, linkedList Next);
    T getValue();
    linkedList* previous;
    linkedList* next;
    T* value;
};

#endif //CS2303FINALHOMEWORK_LINKEDLIST_H
