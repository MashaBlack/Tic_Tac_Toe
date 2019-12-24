#include "Menu.h"

int scrX = sf::VideoMode::getDesktopMode().height; //Screen sizes (changes to fit your screen, you need to test)
int scrY;
int turn = 0;

Menu::Menu()
{
    if (scrX > 900) scrX = 900;
    scrY = scrX;
    sf::RenderWindow window(sf::VideoMode(scrX, scrX), "Tic Tac toe!");
    MySprite BackGround("image/background.jpg");
    BackGround.full_screen(scrX, scrX);
    BackGround.set_color(255, 255, 255, 126);
    MySprite StartGame("image/startgame.png", scrX, int((scrX / 2)) - 320, int((scrX / 2)) - 100);
    MyText GameName("Tic tac toe", 120);
    MyText ByWho("by Maria and Tatyana", 45);
    GameName.set_pos(int(scrX * 0.18), int(scrX * 0.1));
    ByWho.set_pos(int(scrX * 0.25), int(scrY * 0.92));
    MySprite X("image/x.png", scrX);
    MySprite O("image/o.png", scrX);
    MySprite pvp("image/pvp.png", scrX);
    X.sprite.setScale(0.7, 0.7);
    O.sprite.setScale(0.7, 0.7);
    X.set_pos(StartGame.sprite.getPosition().x, StartGame.sprite.getPosition().y + 270);
    O.set_pos(StartGame.sprite.getPosition().x + 525, StartGame.sprite.getPosition().y + 270);
    pvp.set_pos(scrX / 2.0 - 80, X.get_sprite().getPosition().y);
    pvp.sprite.setScale(2, 2);

    while (window.isOpen())
    {
        sf::Event event;

        sf::Vector2i pos = sf::Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    if ((StartGame.sprite.getGlobalBounds().contains(pos.x, pos.y)) && turn != 0)
                    {
                        window.close();
                        if (turn <= 2)
                        {
                            Game new_game(turn);
                            new_game.set_setting(scrX, scrY);
                            new_game.start_game();
                        }
                        else
                        {
                            Players new_game;
                            new_game.set_setting(scrX, scrY);
                            new_game.start_game();
                        }
                        //return;
                    }
                    if (X.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        turn = 1;
                        X.set_color(126, 126, 126, 255);
                        O.set_color(255, 255, 255, 255);
                        pvp.set_color(255, 255, 255, 255);
                    }
                    if (O.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        turn = 2;
                        O.set_color(126, 126, 126, 255);
                        X.set_color(255, 255, 255, 255);
                        pvp.set_color(255, 255, 255, 255);
                    }
                    if (pvp.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        turn = 3;
                        pvp.set_color(126, 126, 126, 255);
                        X.set_color(255, 255, 255, 255);
                        O.set_color(255, 255, 255, 255);
                    }
                }
            }
        }

        window.clear();
        window.draw(BackGround.sprite);
        window.draw(StartGame.sprite);
        window.draw(GameName.get_text());
        window.draw(ByWho.get_text());
        window.draw(X.sprite);
        window.draw(O.sprite);
        window.draw(pvp.sprite);
        window.display();
    }
}