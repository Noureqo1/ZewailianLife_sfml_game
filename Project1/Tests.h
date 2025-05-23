#pragma once
#include "Game.h"

class Tests
{
private:

	sf::Texture loadingTexture;
	sf::Sprite loadingSprite;

	int timer;
	int loadingTimer;
	bool TimerOver;

	void initSprites();

public:

	Tests();

	void TestWindoewTransation(sf::RenderTarget& target);

};

