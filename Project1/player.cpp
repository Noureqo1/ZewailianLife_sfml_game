#include"Game.h"


void Player::initTexture()
{
	if (!this->boyTexture.loadFromFile("pic/Character1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->girlTexture.loadFromFile("pic/Character2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::UpdateAnimation(sf::Sprite& sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		timer += 1;
		if (timer >= animationTimer)
		{
			sprite.setTextureRect(sf::IntRect(16, y*17, 16, 17));
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

sf::Vector2f Player::getBoyPosition()
{
	return boyCharcter.getPosition();
}

sf::Vector2f Player::getgirlPosition()
{
	return girlCharacter.getPosition();
}


void Player::initSprite()
{
	this->boyCharcter.setTexture(this->boyTexture);
	this->boyCharcter.setTextureRect(sf::IntRect(0, 0, 16, 17));

	//Resize the sprite

	this->boyCharcter.scale(4.0f, 4.0f);
	this->boyCharcter.setPosition(435, 264);



	this->girlCharacter.setTexture(this->girlTexture);
	this->girlCharacter.setTextureRect(sf::IntRect(0, 0, 16, 17));
	this->girlCharacter.setPosition(435, 364);
	//Resize the sprite

	this->girlCharacter.scale(4.0f, 4.0f);
}


void Player::initVariables()
{
	timer = 0;
	animationTimer = 4;
	this->space = false;
	this->y = 0;
	this->x = 0;
	this->movementSpeed = 3.f;
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Player::~Player()
{

}

//Accessors




//Functions



bool Player::getSpace()
{
	return space;
}

void Player::Space()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->space = true;
}

void Player::updateInput(sf::Sprite& sprite)
{
	this->Space();
	//Keyboard input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(sf::Sprite& sprite,const sf::RenderTarget* target)
{
	//Left
	if (sprite.getGlobalBounds().left <= 0.f)
		sprite.setPosition(0.f, sprite.getGlobalBounds().top);
	//Right
	if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= target->getSize().x)
		sprite.setPosition(target->getSize().x - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
	//Top
	if (sprite.getGlobalBounds().top <= 0.f)
		sprite.setPosition(sprite.getGlobalBounds().left, 0.f);
	//Bottom
	if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= target->getSize().y)
		sprite.setPosition(sprite.getGlobalBounds().left, target->getSize().y - sprite.getGlobalBounds().height);
}

void Player::updatePlayer(sf::Sprite& sprite,const sf::RenderTarget* target)
{
	this->updateInput(sprite);

	/*this->UpdateBackgrownd();*/

	this->UpdateAnimation(sprite);

	//Window bounds collision
	map.updateBackgrowndBoundsCollision(sprite);

	this->updateWindowBoundsCollision(sprite ,target);
}
void Player::update(const sf::RenderTarget* target)
{

	if (menu.getSpriteSlected())
	{
		updatePlayer(boyCharcter,target);
	}
	
}

void Player::render(sf::RenderTarget& target)
{
}
