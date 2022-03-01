//
// Created by Vincent on 2022/2/25.
//

#include "testSea.h"
testSea:: testSea(){
}
testSea:: ~testSea(){
}
bool testSea:: test(){
    puts("\nprivate functions and accessors will not be tested, DisplayInfo() is directly calling the DisplayInfo for Fleet object, wich is tested elsewhere, thus it will not be test either");
    puts("start test Seas");
    bool ok = false;
    ok = testPlaceShip() && testShot() && testIsEmpty() && testDisplaySeas();
    if(ok){
        puts("Seas pass the test");
    }else{
        puts("Seas doesn't pass the test");
    };
    return ok;

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
    Battleship* testShip = (Battleship*) *(testObject->getPointer(0,testPair));
    printf("testShip Pair: %d, %d\n",testShip->getCoordinate()->row,testShip->getCoordinate()->col);
    int counter = 1;
    printf("compartment: %d\n", testShip->getCompartments());
    while(testShip->next != nullptr){
        printf("have next?: %d\n",testShip->next != nullptr);
        printf("have previous? %d\n",testShip->previous != nullptr);
        ok = !testShip->isWater() && testShip->getActualSymbol() == 'A';
        char actualSymbol = testShip->getActualSymbol();
        printf("the actual symbol is: %c\n",actualSymbol);
        testShip = testShip->next;
        printf("have next?: %d\n",testShip->next != nullptr);
        counter++;
    }
    printf("counter: %d\n",counter);
    ok = ok && counter == 5;
    if(ok){
        std::cout<< "placeShip() pass the test" <<std::endl;
    }else{
        std::cout<<"placeShip() does not pass the test" << std::endl;
    }
    return ok;
}

bool testSea:: testShot(){
    puts("start testing shot()");
    bool ok = false;
    Seas* testObject = new Seas();
    Pair* testPair = new Pair;
    testPair->row = 0;
    testPair->col = 0;
    testObject->shot(0,testPair);
    Location* testLocation = *(testObject->getPointer(0,testPair));
    ok = testLocation->getSymbol() == testLocation->getActualSymbol();
    if(ok){
        puts("shot() pass the test");
    }else{
        puts("shot() does not pass the test");
    }
    return ok;
}

bool testSea:: testIsEmpty(){
    puts("start testing isEmpty()");
    bool ok = false;
    Seas* testObject = new Seas();
    Type testType = CARRIER;
    Pair* testPair0 = new Pair;
    testPair0->row = 1;
    testPair0->col = 0;
    Pair* testPair1 = new Pair;
    testPair1->row = 0;
    testPair1->col = 0;
    testObject->placeShip(0,false,testType,testPair0);
    ok = !testObject->isEmpty(testPair1,0,true,2) && testObject->isEmpty(testPair1,0,false,2);
    if(ok){
        puts("isEmpty() pass the test");
    }else{
        puts("isEmpty() does not pass the test");
    }
    return ok;
}
bool testSea:: testDisplaySeas(){
    puts("start testing displaySeas()");
    bool ok = false;
    Seas* testObject = new Seas();
    Pair* testPair = new Pair;
    Type testType = CARRIER;
    testPair->row = 2;
    testPair->col = 3;
    testObject->placeShip(0,true,testType,testPair);
    testObject->placeShip(1,false,testType,testPair);
    testObject->displaySeas(false);
    puts("\ncheat on: \n");
    testObject->displaySeas(true);
    fflush(stdin);
    char answer = ' ';
    std::cout<<"is it displayed as expected? (y for Yes): " << scanf("%c",&answer) <<std::endl;
    ok = answer == 'y';
    if(ok){
        puts("displaySeas() pass the test");
    }else{
        puts("displaySeas() does not pass the test");
    }
    return ok;
}
