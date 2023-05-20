#pragma once
#include"Game.h"

class Chat
{
private:

	Font font;
	Text chatText[7];

	void initFont();
	void initText();

public:

	Chat();

	void displaychat(sf::RenderWindow &window);
};

