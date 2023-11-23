#ifndef UNTITLED_MESFONCTIONS_H

#include "stdio.h"
#define NUM_BLOCKS 18
enum BlockType {
    EMPTY = 0,
    BREAKABLE = 1,
    PUSHABLE = 2,
    TRAPPED = 3,
    INVINCIBLE = 4,
    DISAPPEAR_APPEAR = 5,
    CONVEYOR_BELT = 6,
    BALL = 7,
    SNOOPY = 8,
    BIRD = 9
};

struct Element {
    int x; // element's row
    int y; // element's Column

    char    uni;
    enum BlockType type;
};




#define UNTITLED_MESFONCTIONS_H
#endif //UNTITLED_MESFONCTIONS_H

