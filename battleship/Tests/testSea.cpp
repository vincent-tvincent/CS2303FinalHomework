//
// Created by Vincent on 2022/2/25.
//

#include "testSea.h"
testSea:: testSea(){
}
testSea:: ~testSea(){
}

bool testSea:: testPlaceShip(){
    std::cout <<"start test placeShip()" <<std::endl;
    bool ok = false;
    Seas* testObject = new Seas();
    Pair* testPair = new Pair;
    Type testType = CARRIER;
    testPair->row = 2;
    testPair->col = 3;
    testObject->placeShip(0,true,testType,testPair);
    ok = testObject->getPointer(testPair,0)->getSymbol() == 'A';
    if(ok){
        std::cout<< "placeShip() pass the test" <<std::endl;
    }else{
        std::cout<<"placeShip() does not pass the test" << std::endl;
    }
    return ok;
}