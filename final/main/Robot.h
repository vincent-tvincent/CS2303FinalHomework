//
// Created by vince on 2022/3/2.
//

#ifndef CS2303FINALHOMEWORK_ROBOT_H
#define CS2303FINALHOMEWORK_ROBOT_H
#include "../matrix/adjmatrix.h"
#include "../io.h"
class Robot {
public:
    Robot(const char*);
    virtual ~Robot();
    void outputPath(const char*); //form the path and write it to given output file;
private:
    adjMatrix* map;
};


#endif //CS2303FINALHOMEWORK_ROBOT_H
