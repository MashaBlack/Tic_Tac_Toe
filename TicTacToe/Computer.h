#ifndef COMPUTER_H
#define COMPUTER_H
#include "board.h"

class Computer
{
public:
    Computer();

    int make_move(Board* board);
};

#endif // COMPUTER_H
