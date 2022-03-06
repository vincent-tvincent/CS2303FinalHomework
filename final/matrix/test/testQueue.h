//
// Created by Vincent on 2022/3/5.
//

#ifndef CS2303FINALHOMEWORK_TESTQUEUE_H
#define CS2303FINALHOMEWORK_TESTQUEUE_H
#include "../linkedList/queue.h"
#include <iostream>
class testQueue {
public:
    testQueue();
    virtual ~testQueue();
    bool test();
    bool testEnqueue();
    bool testDequeue();
};


#endif //CS2303FINALHOMEWORK_TESTQUEUE_H
