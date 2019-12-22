#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Computer.h"

Computer::Computer()
{

}

int Computer::make_move(Board* board)
{
    Board bord_temp;
    bord_temp.copy_board(board);
    for (int i = 0; i < 9; i++)
    {
        if (bord_temp.check_move(i))
        {
            bord_temp.set_move(i, 2);
            if (bord_temp.winner() == 2)
            {
                board->set_move(i, 2);
                return i;
            }
            bord_temp.set_move(i, 0);
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (bord_temp.check_move(i))
        {
            bord_temp.set_move(i, 1);
            if (bord_temp.winner() == 1)
            {
                board->set_move(i, 2);
                return i;
            }
            bord_temp.set_move(i, 0);
        }
    }

    if (board->get_item(4) == 0)
    {
        board->set_move(4, 2);
        return 4;
    }

    srand(time(NULL));

    int best_way1[4] = { 0, 2, 6, 8 };
    int best_way2[4] = { 1, 3, 5, 7 };

    if (((board->get_item(2) == board->get_item(6)) & (board->get_item(2) == 1)) ||
        (board->get_item(0) == board->get_item(8)) & (board->get_item(0) == 1))
    {
        for (int i = 0; i < 4; i++)
        {
            std::swap(best_way1[i], best_way2[i]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        std::swap(best_way1[i], best_way1[rand() % 4]);
        std::swap(best_way2[i], best_way2[rand() % 4]);
    }

    for (int i = 0; i < 4; i++)
    {
        if (bord_temp.get_item(best_way1[i]) == 0)
        {
            board->set_move(best_way1[i], 2);
            return best_way1[i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (bord_temp.get_item(best_way2[i]) == 0)
        {
            board->set_move(best_way2[i], 2);
            return best_way2[i];
        }
    }

    return 4;
}