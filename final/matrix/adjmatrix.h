//
// Created by vince on 2022/3/1.
//

#ifndef CS2303FINALHOMEWORK_ADJMATRIX_H
#define CS2303FINALHOMEWORK_ADJMATRIX_H
#include "matrix.h"
#include "linkedList/queue.h"
class adjMatrix: public matrix{
public:
    adjMatrix(int);
    void connect(int,int); //add a single connection on matrix
    singleLinkedList* getPath(int start); //return the longest path can go from given start node
private:
    int size;
    bool ifConnect(int,int); // check if the given two node have connection
};


#endif //CS2303FINALHOMEWORK_ADJMATRIX_H
