#pragma once
#include "Game.h"

class NPC
{
private:

	sf::Sprite npc1 , gui;
	sf::Texture npc1Texture, guiTexture;


	void initTeaxture();
	void initSprites();

public:

	NPC();

	void render(sf::RenderTarget& target);
	void initchat(sf::Sprite sprite , sf::RenderTarget& target);
};

