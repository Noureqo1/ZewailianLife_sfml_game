#include"Game.h"
void Map::initTeaxture()
{
	if (!this->t1.loadFromFile("pic/Street.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Map::initBackground()
{
	b1.setTexture(t1);
	b1.setPosition(0, 0);

}

Map::Map()
{
	this->initTeaxture();
	this->initBackground();
}

Map::~Map()
{

}


void Map::render(sf::RenderTarget& target)
{
	target.draw(this->b1);
}

void Map::updateBackgrowndBoundsCollision(sf::Sprite &sprite)
{
	if (sprite.getGlobalBounds().top <= 150.f)
			sprite.setPosition(sprite.getGlobalBounds().left, 150.f);
}

