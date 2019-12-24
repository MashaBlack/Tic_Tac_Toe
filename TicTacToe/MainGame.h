#ifndef MGAME
#define MGAME
#include <SFML/Graphics.hpp>
#include "MySprite.h"
#include "board.h"

class MainGame
{
public:
	//страшно
	int scrX;
	int scrY;
	MySprite BackGround;
	MySprite lose;
	MySprite won;
	MySprite tie;
	MySprite back;
	MySprite X;
	MySprite O;
	Board board;
	sf::Clock clock;
	float time;

	MainGame() {};
	void set_setting(int scrX, int scrY);
	void start_game();
	void set_sprites();
	virtual void set_xo() = 0;
	virtual void set_move(int x) = 0;
	virtual void who_turn() = 0;
	virtual void get_menu() = 0;
};

#endif
