#pragma once
#include "Game.h"
class NPC
{
private:

	sf::Sprite npc1 , gui;
	sf::Texture npc1Texture, guiTexture;
	bool I;



	void initTeaxture();
	void initSprites();

public:

	NPC();
	bool getI();
	void render(sf::RenderTarget& target);
	void rendernpc(sf::RenderTarget& target);
	void initchat(sf::Sprite sprite, sf::RenderTarget& target);
	void Iispressed();
};

