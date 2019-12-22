#include "Game.h"


Game::Game(int scrX, int scrY, int turn)
{
    sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Tic Tac Toe");
    MySprite X("image/x.png");
    MySprite O("image/o.png");
    if (turn == 2)
    {
        O = MySprite("image/x.png");
        X = MySprite("image/o.png");
    } 
    MySprite BackGround("image/board.jpg");
    BackGround.full_screen(scrX, scrY);
    BackGround.set_color(255, 255, 255, 126);
    MySprite lose("image/youlose.png", scrX / 3 - 150, scrY / 2 - 150);
    MySprite won("image/youwon.png", scrX / 3 - 150, scrY / 2 - 150);
    MySprite tie("image/tie.png", scrX / 3 - 150, scrY / 2 - 150);
    MySprite back("image/back.png");

    Board board;
    board.new_board();
    Computer comp;
    
    if (turn == 2) comp.make_move(&board);

    sf::Clock clock;
    float time = 0;
    while (window.isOpen())
    {
        sf::Event event;

        sf::Vector2i pos = sf::Mouse::getPosition(window);

        time = clock.getElapsedTime().asSeconds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    int x = int(pos.x) / 300 + 3 * (int(pos.y) / 300);
                    if (board.check_move(x))
                    {
                        board.set_move(x, 1);
                        comp.make_move(&board);
                    }

                    if (back.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        window.close();
                        Menu menu;
                        return;
                    }
                }
            }
        }

        window.clear();
        window.draw(BackGround.sprite);
        for (int i = 0; i < 9; i++)
        {
            if (!board.check_move(i))
            {
                int posX = (i % 3) * 300 + 50;
                int posY = (i / 3) * 300 + 50;
                if (board.get_item(i) == 1)
                {
                    MySprite temp_X = X;
                    temp_X.set_pos(posX, posY);
                    window.draw(temp_X.sprite);
                }
                else
                {
                    MySprite temp_O = O;
                    temp_O.set_pos(posX, posY);
                    window.draw(temp_O.sprite);
                }
            }
        }

        if (board.board_full() || board.winner() != 0)
        {
            clock.restart();
            time = clock.getElapsedTime().asSeconds();
            MySprite temp("");
            if (board.winner() == 1)
            {
                temp = won;
            }
            else if (board.winner() == 2)
            {
                temp = lose;
            }
            else
            {
                temp = tie;
            }
            window.draw(temp.sprite);
            window.display();
            while (time <= 1.5)
            {
                time = clock.getElapsedTime().asSeconds();
            }
            board.new_board();
            if (turn == 2) comp.make_move(&board);
        }

        window.draw(back.sprite);
        window.display();
    }
}
