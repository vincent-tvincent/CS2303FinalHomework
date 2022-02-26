//
// Created by vincent on 2022/2/20.
//

#include "battleshipMain.h"
#include"Tests/testSea.h"
int main(int argc, char* argv[]){
    testSea* test = new testSea();
    test->testPlaceShip();
    return 0;
}