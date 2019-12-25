#include "MenuText.h"

MenuText::MenuText(const std::string& str, int size)
{
	font.loadFromFile("font/Alata-Regular.ttf");
	text.setFont(font);
	text.setString(str);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);
}

sf::Text MenuText::get_text()
{
	return text;
}

void MenuText::change_text(const std::string& str)
{
	text.setString(str);
}

void MenuText::set_pos(int x, int y)
{
	text.setPosition(x, y);
}