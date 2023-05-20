#pragma once
#include "Game.h"
class CutSene
{
private:
	sf::Sprite bus;
	sf::Texture tuxture;



	int x , value;
	bool enter , cutSene;

	void initTeaxture();
	void initSprite();
	void initVariables();


public:
	CutSene();
	~CutSene();


	void render(sf::RenderTarget& target);
	void BusSene();
	bool cutSeneIsOver();
	void Space();
	void updateInput();
};

