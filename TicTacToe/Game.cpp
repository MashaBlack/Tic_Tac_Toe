#include "Game.h"


Game::Game(int tr)
{
    turn = tr;
}

void Game::set_move(int x)
{
    if (board.check_move(x))
    {
        board.set_move(x, 1);
        if (board.winner() == 0) comp.make_move(&board);
    }
}

void Game::who_turn()
{
    if (turn == 2) comp.make_move(&board);
}

void Game::set_xo()
{
    if (turn == 2)
    {
        X.create_sprite("image/o.png", scrX);
        O.create_sprite("image/x.png", scrX);
    }
    else
    {
        X.create_sprite("image/x.png", scrX);
        O.create_sprite("image/o.png", scrX);
    }
    lose.create_sprite("image/youlose.png", scrX, scrX / 3 - 150, scrY / 2 - 150);
    won.create_sprite("image/youwon.png", scrX, scrX / 3 - 150, scrY / 2 - 150);
}

void Game::get_menu()
{
    Menu menu;
    return;
}