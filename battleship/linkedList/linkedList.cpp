//
// Created by Vincent on 2022/2/22.
//

#include <cwchar>
#include "linkedList.h"
template<class T>
linkedList<T>:: linkedList(T Value, linkedList Previous, linkedList Next){
    *previous = Previous;
    *next = Next;
    *value = Value;
}


