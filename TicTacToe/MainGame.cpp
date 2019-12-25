#include "MainGame.h"

void MainGame::start_game()
{
    sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Tic Tac Toe");

    set_sprites();
    set_xo();

    who_turn();
    
    time = 0;
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

                    set_move(x);

                    if (back.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        window.close();
                        get_menu();
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
                int posX = (i % 3) * (scrX / 3.0) + 50;
                int posY = (i / 3) * (scrX / 3.0) + 50;
                if (board.get_item(i) == 1)
                {
                    X.set_pos(posX, posY);
                    window.draw(X.sprite);
                }
                else
                {
                    O.set_pos(posX, posY);
                    window.draw(O.sprite);
                }
            }
        }

        if (board.board_full() || board.winner() != 0)
        {
            clock.restart();
            time = clock.getElapsedTime().asSeconds();
            TemplateSprite temp("");
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
            who_turn();
        }

        window.draw(back.sprite);
        window.display();
    }
}

void MainGame::set_sprites()
{
    BackGround.create_sprite("image/board.jpg");
    BackGround.full_screen(scrX, scrY);
    BackGround.set_color(255, 255, 255, 126);
    tie.create_sprite("image/tie.png", scrX, scrX / 3 - 150, scrY / 2 - 150);
    back.create_sprite("image/back.png");
    board.new_board();
}

void MainGame::set_setting(int x, int y)
{
    scrX = x;
    scrY = y;
}