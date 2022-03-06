//
// Created by vince on 2022/3/1.
//

#include "finalMain.h"
int main(int argc, char** argv){
    testStack* test0 = new testStack();
    testQueue* test1 = new testQueue();
    testAdjmatrix* test2 = new testAdjmatrix();
    if(test0->test() && test1->test() && test2->test()){
        Robot* demo = new Robot(argv[1]);
        demo->outputPath(argv[2]);
    }
}