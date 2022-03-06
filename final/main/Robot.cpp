//
// Created by vince on 2022/3/2.
//

#include "Robot.h"
Robot:: Robot(const char* inputFile){
    printf("input file: %s\n",inputFile);
    FILE* input = fopen(inputFile,"r");
    int size = -1;
    fscanf(input,"%d", &size);
    printf(" node amount: %d\n",size);
    map = new adjMatrix(size);
    int startRoom = 0;
    bool isNumber= true;
    char end = '\n';
    int endRoom = -1;
    char actualSeparator = ' ';
    while(startRoom < size){
        if(isNumber){//read value once, then read separator once
            fscanf(input,"%d",&endRoom);
            //if reading room, build connection between recent room and read value
            map->connect(startRoom,endRoom);
        }else{
            fscanf(input,"%c",&actualSeparator);
            if(actualSeparator == end) {
                startRoom ++;
            };//if finish on current room
        }
        isNumber = !isNumber;
    }
    fclose(input);
}
Robot:: ~Robot(){}

void Robot:: outputPath(const char* outputFile){
    printf("output file: %s\n", outputFile);
    FILE* output = fopen(outputFile,"w");
    queue* path = map->getPath(0);
    int counter = 1;
    int currentRoom = path->dequeue();
    fprintf(output," these are the rooms cleaned by robot in order: \n");
    while(currentRoom > -1){
        fprintf(output,"room vacuumed %d --> ",currentRoom);
        if(counter == 5 ){
            fprintf(output,"\n");
            counter = 0;
        }
        currentRoom = path->dequeue();
        counter++;
    }
    fclose(output);
}