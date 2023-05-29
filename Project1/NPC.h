#pragma once
#include "Game.h"
class NPC
{
private:

	sf::Sprite npc1, npc2, npc3, npc4, gui, gui2,gui3,gui4;

	sf::Texture npc1Texture, npc2Texture, npc3Texture, npc4Texture, guiTexture, gui2Texture, gui3Texture, gui4Texture;

	bool I;

	bool startGUI2;
	bool startGUI3;
	bool startGUI4;


	void initTeaxture();

	void initSprites();

public:

	NPC();
	bool getI();
	bool getstartGUI2();
	bool getstartGUI3();
	bool getstartGUI4();
	void render(sf::RenderTarget& target);
	void rendernpc(sf::RenderTarget& target);
	void initGUI2(sf::Sprite sprite, sf::RenderTarget& target);
	void initGUI3(sf::Sprite sprite, sf::RenderTarget& target);
	void initGUI4(sf::Sprite sprite, sf::RenderTarget& target);
	void initchat(sf::Sprite sprite, sf::RenderTarget& target);
	void Iispressed(sf::Sprite sprite);
	void IofGUI2ispressed(sf::Sprite sprite);
	void IofGUI3ispressed(sf::Sprite sprite);
	void IofGUI4ispressed(sf::Sprite sprite);

	void handleCollision(sf::Sprite& sprite1);
	void handleindoorCollision(sf::Sprite& sprite1);
	
};

