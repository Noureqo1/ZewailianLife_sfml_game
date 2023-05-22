#include "game.h"

void Chat::initFont()
{
	this->font.loadFromFile("assets/fonts/Barlock.otf");
}

void Chat::initText()
{
	this->chatText[0].setFont(font);
	this->chatText[0].setFillColor(Color::Yellow);
	this->chatText[0].setString("hi my name is abdalrehem");
	this->chatText[0].setCharacterSize(50);
	this->chatText[0].setPosition(Vector2f(400, 640 / (10)));
}

Chat::Chat()
{
	this->initFont();
	this->initText();
}

void Chat::displaychat(sf::RenderWindow& window)
{
	window.draw(this->chatText[0]);
}

