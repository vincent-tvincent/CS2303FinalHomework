//
// Created by vince on 2022/2/26.
//

#ifndef CS2303FINALHOMEWORK_TESTFLEET_H
#define CS2303FINALHOMEWORK_TESTFLEET_H
#include "Fleets.h"

class testFleet {
public:
    testFleet();
    virtual ~testFleet();
    bool test();
    bool testGetHowManyShips();
    bool testAddShip();
    bool testSinkShip();
    bool testPlayerLost();
    bool testDisplayInfo();
private:
    Type testType0;
    Type testType1;
    Type testType2;
    Type testType3;
    Type testType4;
};

#endif //CS2303FINALHOMEWORK_TESTFLEET_H
