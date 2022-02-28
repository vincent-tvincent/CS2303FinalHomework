//
// Created by vince on 2022/2/25.
//

#ifndef CS2303FINALHOMEWORK_TESTBATTLESHIP_H
#define CS2303FINALHOMEWORK_TESTBATTLESHIP_H
#include <iostream>
#include "battleship.h"
class testBattleship {
public:
    testBattleship();
    virtual ~testBattleship();
    bool test();
    bool testLink();
    bool testGetShot();
    bool testIfSink();
private:
    Pair* testPair;
    Type testType;
};


#endif //CS2303FINALHOMEWORK_TESTBATTLESHIP_H
