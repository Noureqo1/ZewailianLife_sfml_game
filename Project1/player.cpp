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



void Player::setboyposition(sf::Vector2f pos)
{
	boyCharcter.setPosition(pos);
}

void Player::setgirlposition(sf::Vector2f pos)
{
	girlCharacter.setPosition(pos);
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

	this->space = false;
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

	//Window bounds collision

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
