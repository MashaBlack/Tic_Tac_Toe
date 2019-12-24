#ifndef PL
#define PL

#include "MainGame.h"
#include "Menu.h"

class Players : public MainGame
{
	bool Whoturn;
public:
	Players();
	void set_move(int x);
	void who_turn();
	void set_xo();
	void get_menu();
};

#endif
