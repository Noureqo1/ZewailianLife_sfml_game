#include "Game.h"


Tests::Tests()
{
	this->initSprites();
	timer = 0;
	loadingTimer = 50;
	TimerOver = false;
}

void Tests::initSprites()
{
	if (!this->loadingTexture.loadFromFile("pic/white.jpeg"))
	{
		std::cout << "ERROR::TESTES::INITSPRITES::Could not load texture file." << "\n";
	}

	loadingSprite.setTexture(loadingTexture);
	loadingSprite.setPosition(0, 0);
	loadingSprite.setScale(5, 5);
}

void Tests::TestWindoewTransation(sf::RenderTarget& target)
{
	timer +=1;
	if (timer <= loadingTimer)
	{
		TimerOver = true;
	}

	if (!TimerOver)
	{
		target.draw(this->loadingSprite);
	}
}

