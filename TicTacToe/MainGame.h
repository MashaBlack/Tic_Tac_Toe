#ifndef MGAME
#define MGAME
#include <SFML/Graphics.hpp>
#include "TemplateSprite.h"
#include "board.h"

class MainGame
{
public:
	//страшно
	int scrX;
	int scrY;
	TemplateSprite BackGround;
	TemplateSprite lose;
	TemplateSprite won;
	TemplateSprite tie;
	TemplateSprite back;
	TemplateSprite X;
	TemplateSprite O;
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
