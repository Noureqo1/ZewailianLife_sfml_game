#include "Game.h"

animation::animation()
{
	timer = 0;
	animationTimer = 4;
	this->y = 0;
	this->x = 0;
}

void animation::UpdateAnimation(sf::Sprite& sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		timer += 1;
		if (timer >= animationTimer)
		{
			sprite.setTextureRect(sf::IntRect(16, y * 17, 16, 17));
			y++;
			y = y % 3;
			timer = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		timer += 1;
		if (timer >= animationTimer)
		{

			sprite.setTextureRect(sf::IntRect(48, y * 17, 16, 17));
			y++;

			y = y % 3;

			timer = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		timer += 1;
		if (timer >= animationTimer)
		{

			sprite.setTextureRect(sf::IntRect(32, y * 17, 16, 17));
			y++;
			y = y % 3;
			timer = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		timer += 1;
		if (timer >= animationTimer)
		{

			sprite.setTextureRect(sf::IntRect(0, y * 17, 16, 17));
			y++;
			y = y % 3;
			timer = 0;
		}
	}
}