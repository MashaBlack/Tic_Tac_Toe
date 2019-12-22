#ifndef BOARD_H
#define BOARD_H


class Board
{
    int board[9];
public:
    Board();

    void new_board();
    int winner();
    void set_move(int point, int pl);
    bool check_move(int point);
    int get_item(int id);
    void copy_board(Board* br);
    bool board_full();
};

#endif // BOARD_H
