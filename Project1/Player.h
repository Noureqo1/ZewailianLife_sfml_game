#pragma once
#include"Game.h"
#include "Menu.h"



class Player
{
private:

	bool space;
	int timer, animationTimer;
	sf::Clock clock;
	
	sf::Texture boyTexture, girlTexture;
	int x, y;
	float movementSpeed;


	
	
	void initSprite();
	void initVariables();
	
	menu menu;

public:

	Player();
	virtual ~Player();

	Map map;

	//Functions

    void initTexture();

	sf::Sprite boyCharcter, girlCharacter;

	bool getSpace();


	void Space();
	void updateInput(sf::Sprite& sprite);
	void updateWindowBoundsCollision(sf::Sprite& sprite , const sf::RenderTarget* target);
	void updatePlayer(sf::Sprite& sprite,const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
	void UpdateAnimation(sf::Sprite& sprite);
	void setboyposition(sf::Vector2f pos);
	void setgirlposition(sf::Vector2f pos);
	sf::Vector2f getBoyPosition();
	sf::Vector2f getgirlPosition();
};