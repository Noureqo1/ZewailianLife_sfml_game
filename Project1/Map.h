#pragma once
#include"Game.h"
class Map
{
private:

	sf::Sprite b1;
	sf::Texture t1;


	void initTeaxture();
	void initBackground();

public:
	Map();
	~Map();

	void render(sf::RenderTarget& target);
	void updateBackgrowndBoundsCollision(sf::Sprite &sprite);
	
};

