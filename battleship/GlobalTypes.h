//
// Created by Vincent on 2022/2/24.
//

#ifndef CS2303FINALHOMEWORK_GLOBALTYPES_H
#define CS2303FINALHOMEWORK_GLOBALTYPES_H
typedef struct{
    int row;
    int col;
}Pair;

typedef enum
{
    EMPTY,
    CARRIER,
    SUBMARINE,
    BATTLESHIP,
    CRUISER,
    DESTROYER
}Type;

#endif //CS2303FINALHOMEWORK_GLOBALTYPES_H
