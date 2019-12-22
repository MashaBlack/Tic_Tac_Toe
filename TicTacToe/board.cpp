#include "board.h"

Board::Board()
{

}

void Board::new_board()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = 0;
    }
}

int Board::winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2] && board[i * 3] != 0)
            return board[i * 3];
        if ((board[i] == board[i + 3]) & (board[i] == board[i + 6]) & (board[i] != 0))
            return board[i];
    }
    if ((board[4] != 0) && ((board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[2] == board[6])))
        return board[4];
    return 0;
}

void Board::set_move(int point, int pl)
{
    board[point] = pl;
}

bool Board::check_move(int point)
{
    return  board[point] == 0;
}

int Board::get_item(int id)
{
    return board[id];
}

void Board::copy_board(Board* br)
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = br->get_item(i);
    }
}

bool Board::board_full()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0) return false;
    }
    return true;
}
