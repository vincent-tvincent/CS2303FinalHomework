//
// Created by Vincent on 2022/2/22.
//

#include "linkedList.h"
template<class T>
linkedList<T>:: linkedList(){
    value = nullptr;
    previous = nullptr;
    next = nullptr;
}
template<class T>
linkedList<T>:: linkedList(T* Value, linkedList* Previous, linkedList* Next){
    value = Value;
    previous = Previous;
    next = Next;
    unchecked = true;
}
template<class T>
linkedList<T>:: ~linkedList(){}

