#include"Game.h"

void NPC::initTeaxture()
{
	if (!this->npc1Texture.loadFromFile("pic/npc1.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->guiTexture.loadFromFile("assets/GUI/GUI.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}

}

void NPC::initSprites()
{
	this->npc1.setTexture(this->npc1Texture);
	this->npc1.setTextureRect(sf::IntRect(0, 0, 16, 17));
	this->npc1.scale(4.0f, 4.0f);
	this->npc1.setPosition(235, 420);

	this->gui.setTexture(this->guiTexture);
	this->gui.setPosition(npc1.getPosition().x, npc1.getPosition().y + 50);
	this->gui.setScale(3,3);
}

NPC::NPC()
{
	I = false;
	this->initTeaxture();
	this->initSprites();
}


void NPC::render(sf::RenderTarget& target)
{
	target.draw(npc1);
}

void NPC::initchat(sf::Sprite sprite, sf::RenderTarget& target)
{
	Iispressed();

	if (npc1.getPosition().x - sprite.getPosition().x < 50 && npc1.getPosition().x - sprite.getPosition().x > -50 && I )
	{
		target.draw(gui);
	}


}

void NPC::Iispressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		I = true;
	}
}
