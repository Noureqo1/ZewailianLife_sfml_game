#pragma once
#include "Game.h"
class indoorsMap
{
private:

	sf::Sprite indoors;
	sf::Texture indoorsTexture;


	void initTeaxture();
	void initBackground();

public:
	indoorsMap();
	~indoorsMap();

	void render(sf::RenderTarget& target);
	void updateBackgrowndBoundsCollision(sf::Sprite& sprite);
};

