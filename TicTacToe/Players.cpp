#include "Players.h"
bool turn = true;

Players::Players()
{
    
}

void Players::set_move(int x)
{
    if (board.check_move(x))
    {
        if (Whoturn)
        {
            Whoturn = false;
            board.set_move(x, 1);
        }
        else
        {
            Whoturn = true;
            board.set_move(x, 2);
        }
    }
}

void Players::who_turn()
{
    Whoturn = true;
}

void Players::set_xo()
{
    X.create_sprite("image/x.png");
    O.create_sprite("image/o.png");
    lose.create_sprite("image/Owon.png", scrX, scrX / 3 - 150, scrY / 2 - 150);
    won.create_sprite("image/Xwon.png", scrX, scrX / 3 - 150, scrY / 2 - 150);
}

void Players::get_menu()
{
    Menu menu;
    return;
}

