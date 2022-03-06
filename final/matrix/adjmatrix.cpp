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
adjMatrix:: ~adjMatrix(){}

void adjMatrix:: connect(int from, int to){
    set(from,to,1);
}

bool adjMatrix:: ifConnect(int from, int to){
    return *getPointer(from,to);
}

queue* adjMatrix:: getPath(int start){
    queue* path = new queue();
    int* visited = (int*) malloc(size*sizeof(int));
    stack* unvisited = new stack();
    for(int i = 0;i < size ;i++) *(visited+i) = 0;//initial every node as unvisited
    unvisited->push(start);
    while(unvisited->size > 0){
        int currentNode = unvisited->pop();
        path->enqueue(currentNode);//add to path
        *(visited+currentNode) = 1;//mark current node as visited
        for(int targetNode = 0; targetNode < size;targetNode++){//check connection
            if(ifConnect(currentNode,targetNode) && !*(visited+targetNode)){//while find a new node
                unvisited->push(targetNode);
            }
        }
    }
    return path;
}