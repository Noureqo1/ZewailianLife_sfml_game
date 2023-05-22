#include"Game.h"

void NPC::initTeaxture()
{
	if (!this->npc1Texture.loadFromFile("pic/npc1.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->npc2Texture.loadFromFile("pic/npc2.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->npc3Texture.loadFromFile("pic/npc3.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->npc4Texture.loadFromFile("pic/npc4.png"))
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

	this->npc2.setTexture(this->npc2Texture);
	this->npc2.setTextureRect(sf::IntRect(0, 0, 16, 17));
	this->npc2.scale(4.0f, 4.0f);
	this->npc2.setPosition(680, 432);

	this->npc3.setTexture(this->npc3Texture);
	this->npc3.setTextureRect(sf::IntRect(0, 0, 16, 17));
	this->npc3.scale(4.0f, 4.0f);
	this->npc3.setPosition(180, 132);

	this->npc4.setTexture(this->npc4Texture);
	this->npc4.setTextureRect(sf::IntRect(0, 0, 16, 17));
	this->npc4.scale(4.0f, 4.0f);
	this->npc4.setPosition(700, 152);

	this->gui.setTexture(this->guiTexture);
	this->gui.setPosition(npc1.getPosition().x, npc1.getPosition().y + 50);
	this->gui.setScale(3, 3);

}



NPC::NPC()
{
	I = false;
	this->initTeaxture();
	this->initSprites();
}

bool NPC::getI()
{
	return I;
}


void NPC::render(sf::RenderTarget& target)
{
	target.draw(npc1);
}

void NPC::rendernpc(sf::RenderTarget& target)
{
	target.draw(npc2);
	target.draw(npc3);
	target.draw(npc4);
}

void NPC::initchat(sf::Sprite sprite, sf::RenderTarget& target)
{
	Iispressed();

	if (npc1.getPosition().x - sprite.getPosition().x < 150 && npc1.getPosition().x - sprite.getPosition().x > -150 && I)
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
