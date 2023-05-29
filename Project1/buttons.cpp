#include "game.h"

void buttons::initTeaxture()
{
	if (!this->buttonTexture.loadFromFile("assets/GUI/button.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void buttons::initSprites()
{
	button.setTexture(buttonTexture);
	this->button.scale(1.0f, 1.0f);
	this->button.setPosition(550, 16);
}

buttons::buttons()
{
	this->initSprites();
	this->initTeaxture();
}

void buttons::renderItems(sf::RenderTarget& target)
{
	target.draw(button);
}
