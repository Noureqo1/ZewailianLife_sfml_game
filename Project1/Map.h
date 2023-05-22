#pragma once
#include"Game.h"

class Map
{
private:

	sf::Sprite b1,outdoors;
	sf::Texture t1,outdoorsTexture;


	void initTeaxture();
	void initBackground();

public:
	Map();
	~Map();


	bool gateposition(sf::Sprite& sprite);
	bool enteranceposition(sf::Sprite& sprite);
	void render(sf::RenderTarget& target);
	void renderoutdoors(sf::RenderTarget& target);
	void updateBackgrowndBoundsCollision(sf::Sprite &sprite);
	
};

