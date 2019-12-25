#include <SFML/Graphics.hpp>
#include <string>
#include "TemplateSprite.h"

TemplateSprite::TemplateSprite(const std::string& path, int scrX, int px, int py)
{
	create_sprite(path, scrX, px, py);
}

void TemplateSprite::set_pos(int x, int y)
{
	sprite.setPosition(x, y);
}
//set image full screen
void TemplateSprite::full_screen(int scrX, int scrY)
{
	sprite.setScale( //увеличиваем изображение на весь экран
		scrX / sprite.getLocalBounds().width,
		scrY / sprite.getLocalBounds().height);
}

void TemplateSprite::set_color(int r, int g, int b, int t)
{
	sf::Color col = sf::Color(r, g, b, t);
	sprite.setColor(col);
}

sf::Sprite TemplateSprite::get_sprite()
{
	return sprite;
}

void TemplateSprite::create_sprite(const std::string& path, int scrX, int px, int py)
{
	if (path == "") return;
	x = px;
	y = py;
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(px, py);
}