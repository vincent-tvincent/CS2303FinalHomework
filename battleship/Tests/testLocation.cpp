//
// Created by Vincent on 2022/2/25.
//

#include "testLocation.h"
testLocation::testLocation(){

}

testLocation::~testLocation(){

}

bool testLocation::test(){
    bool ok = false;
    puts("the test cases will not include private methods and accessors");
    puts("start testing Location");
    ok = testGetShot();
}