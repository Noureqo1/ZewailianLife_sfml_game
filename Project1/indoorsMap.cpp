#include "Game.h"

void indoorsMap::initTeaxture()
{
	if (!this->indoorsTexture.loadFromFile("pic/indoors.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void indoorsMap::initBackground()
{
	this->indoors.setTexture(indoorsTexture);
}

indoorsMap::indoorsMap()
{
	this->initTeaxture();
	this->initBackground();
}

indoorsMap::~indoorsMap()
{

}

void indoorsMap::render(sf::RenderTarget& target)
{
	target.draw(this->indoors);
}

