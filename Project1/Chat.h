#pragma once
#include"game.h"

class Chat
{
private:

	Font font;
	Text chatText[7];

	void initFont();

public:

	Chat();

	void displaychat(sf::RenderWindow & window);
};
