//
// Created by vincent on 2022/2/20.
//

#include "battleshipMain.h"
#include "Battleship.h"
#include "Tests/testSea.h"
#include "GlobalTypes.h"
int main(int argc, char* argv[]){
    testSea* test = new testSea();
    test->test();
    return 0;

}