#pragma once
#include "Game.h"
class NPC
{
private:

	sf::Sprite npc1, npc2, npc3, npc4, gui, gui2,gui3,gui4;

	sf::Texture npc1Texture, npc2Texture, npc3Texture, npc4Texture, guiTexture, gui2Texture, gui3Texture, gui4Texture;

	bool I;



	void initTeaxture();

	void initSprites();

public:

	NPC();
	bool getI();
	void render(sf::RenderTarget& target);
	void rendernpc(sf::RenderTarget& target);
	void initchat(sf::Sprite sprite, sf::RenderTarget& target);
	void initIndooorschat(sf::Sprite sprite, sf::RenderTarget& target);
	void Iispressed();
};

