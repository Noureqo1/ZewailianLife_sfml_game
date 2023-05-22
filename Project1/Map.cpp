#include"Game.h"
void Map::initTeaxture()
{
	if (!this->t1.loadFromFile("pic/intro.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->outdoorsTexture.loadFromFile("pic/outdoors.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Map::initBackground()
{
	b1.setTexture(t1);
	b1.setPosition(0, 0);

	outdoors.setTexture(this->outdoorsTexture);

}

Map::Map()
{
	this->initTeaxture();
	this->initBackground();
}

Map::~Map()
{

}



bool Map::gateposition(sf::Sprite& sprite)
{
	if (sprite.getPosition().x > 335 && sprite.getPosition().x < 435 && sprite.getGlobalBounds().top <= 150.f)
	{

		return true;
	}
	else
	{
		return false;
	}
}

bool Map::enteranceposition(sf::Sprite& sprite)
{
	if (sprite.getPosition().x > 435 && sprite.getPosition().x < 535 && sprite.getGlobalBounds().top <= 20.f)
	{

		return true;
	}
	else
	{
		return false;
	}
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(this->b1);
}

void Map::renderoutdoors(sf::RenderTarget& target)
{
	target.draw(this->outdoors);
}

void Map::updateBackgrowndBoundsCollision(sf::Sprite &sprite)
{
	if (sprite.getGlobalBounds().top <= 150.f)
			sprite.setPosition(sprite.getGlobalBounds().left, 150.f);
}

