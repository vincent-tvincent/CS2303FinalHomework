//
// Created by vince on 2022/3/1.
//

#include "adjmatrix.h"
adjMatrix:: adjMatrix(int size): matrix(size,size){
    adjMatrix::size = size;
    int row = 0;
    int col = 0;
    while(col < size){
        set(row,col,0);
        row++;
        if(row == size){
            row = 0;
            col++;
        }
    }
}

void adjMatrix:: connect(int from, int to){
    set(from,to,1);
}

bool adjMatrix:: ifConnect(int from, int to){
    return getPointer(from,to);
}

singleLinkedList* adjMatrix:: getPath(int start){
    queue* visited = new queue();
    visited->enqueue(start);
    singleLinkedList* path;
    int nextRoom = visited->dequeue();
    while(nextRoom > -1){
        for(int node = 0; node < size; node++){
            if(ifConnect(nextRoom,node) && !visited->ifInclude(node)){
                visited->enqueue(node);
            }
                nextRoom = visited->dequeue();
        }
    }
    return path;
}