#ifndef MENUTEXT
#define MENUTEXT
#include <SFML/Graphics.hpp>


class MenuText
{
	sf::Font font;
	sf::Text text;
public:
	MenuText(const std::string& str, int size);
	sf::Text get_text();
	void change_text(const std::string& std);
	void set_pos(int x, int y);
};

#endif