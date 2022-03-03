//
// Created by vince on 2022/3/2.
//

#include "Robot.h"
Robot:: Robot(const char* inputFile){
    FILE* input = fopen(inputFile,"r");
    int size;
    fscanf(input,"%d", &size);
    map = new adjMatrix(size);

    int startRoom = 0;
    bool isSeparator = false;
    char end = '\n';
    int endRoom = -1;
    char actualSeparator = ' ';
    while(startRoom < size){
        if(isSeparator){//read value once, then read separator once
            fscanf(input,"%d",&endRoom);
            //if reading room, build connection between recent room and read value
            map->connect(startRoom,endRoom);
        }else{
            fscanf(input,"%c",&actualSeparator);
            if(actualSeparator == end) {
                startRoom ++;
                isSeparator = !isSeparator;
            };//if finish on current room
        }
        isSeparator = !isSeparator;
    }
    fclose(input);
}

void Robot:: outputPath(const char* outputFile){
    FILE* output = fopen(outputFile,"w");
    singleLinkedList* path = map->getPath();
    int counter = 1;
    while(path->next != nullptr){
        fprintf(output," that's the path of the robot: \n");
        fprintf(output,"room%d --> ",path->value);
        if(counter == 5 ){
            counter = 0;
            fprintf(output,"\n");
        }
        counter ++;
    }
    fclose(output);
}