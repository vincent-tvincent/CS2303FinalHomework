//
// Created by Vincent on 2022/2/25.
//

#ifndef CS2303FINALHOMEWORK_TESTSEA_H
#define CS2303FINALHOMEWORK_TESTSEA_H
#include"GlobalTypes.h"
#include"Seas.h"
#include"stdio.h"
#include"stdlib.h"
class testSea {
public:
    testSea();
    virtual ~testSea();
    bool test();
    bool testPlaceShip();
    bool testShot();
    bool testIsEmpty();
    bool testDisplaySeas();
    bool testDisplayInfo();

};


#endif //CS2303FINALHOMEWORK_TESTSEA_H
