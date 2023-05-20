#include "Game.h"

void CutSene::initTeaxture()
{
	if (!this->tuxture.loadFromFile("pic/Bus.png"))
	{
		std::cout << "ERROR::CutSene::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void CutSene::initSprite()
{
	bus.setTexture(tuxture);
	bus.setPosition(960, 264);
	this->bus.scale(0.4f, 0.4f);
}

void CutSene::initVariables()
{
	cutSene = false;
	this->value = 350;
	this->enter = false;
	this->x = 960;
}

CutSene::CutSene()
{
	this->initVariables();
	this->initTeaxture();
	this->initSprite();
}

CutSene::~CutSene()
{
}

void CutSene::render(sf::RenderTarget& target)
{
	target.draw(this->bus);
}

void CutSene::BusSene()
{
	if (!enter)
	{
		if (bus.getPosition().x > value)
		{

			bus.setPosition(x, 264);

			x = x - 5;
		}
	}
}

bool CutSene::cutSeneIsOver()
{
	if (bus.getPosition().x < -326)
	{
		cutSene = true;
	}
	return cutSene;
}

void CutSene::Space()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->value = -326;
}

void CutSene::updateInput()
{
	this->Space();
}
