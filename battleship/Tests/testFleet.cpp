//
// Created by vince on 2022/2/26.
//

#include "testFleet.h"
testFleet:: testFleet(){
    testType0 = CARRIER;
    testType1 = SUBMARINE;
    testType2 = BATTLESHIP;
    testType3 = CRUISER;
    testType4 = DESTROYER;
}


testFleet:: ~testFleet(){
}

bool testFleet:: test(){
    puts("\nprivate functions and accessor will not be tested");
    puts("start testing Fleets");
    bool ok = testGetHowManyShips() && testAddShip() && testSinkShip() && testPlayerLost() && testDisplayInfo();
    ;
    if(ok){
        puts("Fleets pass the test");
    }else{
        puts("Fleets does not pass the test");
    }
    return ok;
}

bool testFleet:: testGetHowManyShips(){
    puts("start test getHowManyShips()");
    bool ok = false;
    Fleets* testObject = new Fleets();
    ok =       !testObject->getHowManyShips(0,testType0)
            && !testObject->getHowManyShips(0,testType1)
            && !testObject->getHowManyShips(0,testType2)
            && !testObject->getHowManyShips(0,testType3)
            && !testObject->getHowManyShips(0,testType4)
            && !testObject->getHowManyShips(1,testType0)
            && !testObject->getHowManyShips(1,testType1)
            && !testObject->getHowManyShips(1,testType2)
            && !testObject->getHowManyShips(1,testType3)
            && !testObject->getHowManyShips(1,testType4);
    if(ok){
        puts("getHowManyShip() pass the test");
    }else{
        puts("getHowManyShip() does not pass the test");
    }
    return ok;
}

bool testFleet:: testAddShip(){
    puts("start testing addShip()");
    bool ok = false;
    Fleets* testObject0 = new Fleets();
    Fleets* testObject1 = new Fleets();
    testObject0->addShip(0,testType0);
    testObject1->addShip(1,testType1);
    ok = testObject0->getHowManyShips(0,testType0) && testObject1->getHowManyShips(1,testType1);

    if(ok){
        puts("addShip() pass the test");
    }else{
        puts("addShip() does not pass the test");
    }
    return ok;
}
bool testFleet:: testSinkShip(){
    puts("strat testing sinkShip()");
    bool ok = false;
    Fleets* testObject0 = new Fleets();
    Fleets* testObject1 = new Fleets();
    testObject0->addShip(0,testType0);
    testObject1->addShip(1,testType1);
    testObject0->sinkShip(0,testType0);
    testObject1->sinkShip(1,testType1);
    ok = !testObject0->getHowManyShips(0,testType0) && !testObject1->getHowManyShips(1,testType1);
    if(ok){
        puts("sinkShip() pass the test");
    }else{
        puts("sinkShip() does not pass the test");
    }
    return ok;
}

bool testFleet:: testPlayerLost(){
    puts("start testing playerLost()");
    bool ok = false;
    Fleets* testObject = new Fleets();
    ok = testObject->playerLost(0) && testObject->playerLost(1);
    if(ok){
        puts("playerLost() pass the test");
    }else{
        puts("playerLost() does not pass the test");
    }
    return ok;
}

bool testFleet:: testDisplayInfo(){
    puts("start testing playerLost()");
    bool ok = false;
    Fleets* testObject = new Fleets();
    testObject->addShip(0,testType0);
    testObject->addShip(1,testType4);
    testObject->addShip(0,testType2);
    testObject->displayInfo();
    puts("if display as expected? (y for yes): ");
    fflush(stdin);
    char answer;
    scanf("%c", &answer);
    if(answer == 'y'){
        ok = true;
    }else{
        ok = false;
    }
    if(ok){
        puts("displayInfo() pass the test");
    }else{
        puts("displayInfo() does not pass the test");
    }
    return ok;
}