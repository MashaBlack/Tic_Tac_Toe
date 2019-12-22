#include "Menu.h"

const int scrX = 900;
const int scrY = 900;
int turn = 0;

Menu::Menu()
{
    sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Tic Tac toe!");
    MySprite BackGround("image/background.jpg");
    BackGround.full_screen(scrX, scrY);
    BackGround.set_color(255, 255, 255, 126);
    MySprite StartGame("image/startgame.png", int((scrX / 2)) - 320, int((scrY / 2)) - 100);
    MyText GameName("Tic Toc Tae", 120);
    MyText ByWho("by Maria and Tatyana", 45);
    GameName.set_pos(int(scrX * 0.18), int(scrY * 0.1));
    ByWho.set_pos(int(scrX * 0.25), int(scrY * 0.92));
    MySprite X("image/x.png");
    MySprite O("image/o.png");
    X.sprite.setScale(0.7, 0.7);
    O.sprite.setScale(0.7, 0.7);
    X.set_pos(StartGame.sprite.getPosition().x, StartGame.sprite.getPosition().y + 270);
    O.set_pos(StartGame.sprite.getPosition().x + 525, StartGame.sprite.getPosition().y + 270);

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
                        Game new_game(scrX, scrY, turn);
                        return;
                    }
                    if (X.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        turn = 1;
                        X.set_color(126, 126, 126, 255);
                        O.set_color(255, 255, 255, 255);
                    }
                    if (O.sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        turn = 2;
                        O.set_color(126, 126, 126, 255);
                        X.set_color(255, 255, 255, 255);
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
        window.display();
    }
}