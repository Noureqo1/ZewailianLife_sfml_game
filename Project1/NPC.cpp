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
	if (!this->gui2Texture.loadFromFile("assets/GUI/GUI2.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->gui3Texture.loadFromFile("assets/GUI/GUI3.png"))
	{
		std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->gui4Texture.loadFromFile("assets/GUI/GUI4.png"))
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

	this->gui2.setTexture(this->gui2Texture);
	this->gui2.setPosition(npc2.getPosition().x, npc2.getPosition().y + 50);
	this->gui2.setScale(3, 3);

	this->gui3.setTexture(this->gui3Texture);
	this->gui3.setPosition(npc3.getPosition().x, npc3.getPosition().y + 50);
	this->gui3.setScale(3, 3);

	this->gui4.setTexture(this->gui4Texture);
	this->gui4.setPosition(npc4.getPosition().x, npc4.getPosition().y + 50);
	this->gui4.setScale(3, 3);
}



NPC::NPC()
{
	I = false;
	startGUI2 = false;
	startGUI3 = false;
	startGUI4 = false;
	this->initTeaxture();
	this->initSprites();
}

bool NPC::getI()
{
	return I;
}

bool NPC::getstartGUI2()
{
	return startGUI2;
}


bool NPC::getstartGUI3()
{
	return startGUI3;
}

bool NPC::getstartGUI4()
{
	return startGUI4;
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


void NPC::initGUI2(sf::Sprite sprite, sf::RenderTarget& target)
{
	IofGUI2ispressed(sprite);

	if (startGUI2)
	{
		target.draw(gui2);
	}

}

void NPC::initGUI3(sf::Sprite sprite, sf::RenderTarget& target)
{
	IofGUI3ispressed(sprite);

	if (startGUI3)
	{
		target.draw(gui3);
	}
}

void NPC::initGUI4(sf::Sprite sprite, sf::RenderTarget& target)
{
	IofGUI4ispressed(sprite);

	if (startGUI4)
	{
		target.draw(gui4);
	}
}

void NPC::initchat(sf::Sprite sprite, sf::RenderTarget& target)
{
	Iispressed(sprite);

	if (npc1.getPosition().x - sprite.getPosition().x < 150 && npc1.getPosition().x - sprite.getPosition().x > -150 && I )
	{
		target.draw(gui);
	}


}



void NPC::Iispressed(sf::Sprite sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		I = true;
	}
}

void NPC::IofGUI2ispressed(sf::Sprite sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && npc2.getPosition().x - sprite.getPosition().x < 150 && npc2.getPosition().x - sprite.getPosition().x > -150)
	{
		startGUI2 = true;
	}
}

void NPC::IofGUI3ispressed(sf::Sprite sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && npc3.getPosition().x - sprite.getPosition().x < 150 && npc3.getPosition().x - sprite.getPosition().x > -150)
	{
		startGUI3 = true;
	}
}

void NPC::IofGUI4ispressed(sf::Sprite sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && npc4.getPosition().x - sprite.getPosition().x < 150 && npc4.getPosition().x - sprite.getPosition().x > -150)
	{
		startGUI4 = true;
	}
}

void NPC::handleCollision(sf::Sprite& sprite1)
{

	// Check if the global bounds of the sprites intersect
	if (sprite1.getGlobalBounds().intersects(npc1.getGlobalBounds()))
	{
		// Move the sprites away from each other
		if (sprite1.getGlobalBounds().left < npc1.getGlobalBounds().left)
		{
			sprite1.setPosition(npc1.getGlobalBounds().left - sprite1.getGlobalBounds().width, sprite1.getPosition().y);

		}
		else
		{
			sprite1.setPosition(npc1.getGlobalBounds().left + npc1.getGlobalBounds().width, sprite1.getPosition().y);
		}

		if (sprite1.getGlobalBounds().top < npc1.getGlobalBounds().top)
		{
			sprite1.setPosition(sprite1.getPosition().x, npc1.getGlobalBounds().top - sprite1.getGlobalBounds().height);
		}
		else
		{
			sprite1.setPosition(sprite1.getPosition().x, npc1.getGlobalBounds().top + npc1.getGlobalBounds().height);
		}
	}

}

void NPC::handleindoorCollision(sf::Sprite& sprite1)
{
	// Check if the global bounds of the sprites intersect
	if (sprite1.getGlobalBounds().intersects(npc2.getGlobalBounds()))
	{
		// Move the sprites away from each other
		if (sprite1.getGlobalBounds().left < npc2.getGlobalBounds().left)
		{
			sprite1.setPosition(npc2.getGlobalBounds().left - sprite1.getGlobalBounds().width, sprite1.getPosition().y);

		}
		else
		{
			sprite1.setPosition(npc2.getGlobalBounds().left + npc2.getGlobalBounds().width, sprite1.getPosition().y);
		}

		if (sprite1.getGlobalBounds().top < npc2.getGlobalBounds().top)
		{
			sprite1.setPosition(sprite1.getPosition().x, npc2.getGlobalBounds().top - sprite1.getGlobalBounds().height);
		}
		else
		{
			sprite1.setPosition(sprite1.getPosition().x, npc2.getGlobalBounds().top + npc2.getGlobalBounds().height);
		}
	}

	// Check if the global bounds of the sprites intersect
	if (sprite1.getGlobalBounds().intersects(npc3.getGlobalBounds()))
	{
		// Move the sprites away from each other
		if (sprite1.getGlobalBounds().left < npc3.getGlobalBounds().left)
		{
			sprite1.setPosition(npc3.getGlobalBounds().left - sprite1.getGlobalBounds().width, sprite1.getPosition().y);

		}
		else
		{
			sprite1.setPosition(npc3.getGlobalBounds().left + npc3.getGlobalBounds().width, sprite1.getPosition().y);
		}

		if (sprite1.getGlobalBounds().top < npc3.getGlobalBounds().top)
		{
			sprite1.setPosition(sprite1.getPosition().x, npc3.getGlobalBounds().top - sprite1.getGlobalBounds().height);
		}
		else
		{
			sprite1.setPosition(sprite1.getPosition().x, npc3.getGlobalBounds().top + npc3.getGlobalBounds().height);
		}
	}

	// Check if the global bounds of the sprites intersect
	if (sprite1.getGlobalBounds().intersects(npc4.getGlobalBounds()))
	{
		// Move the sprites away from each other
		if (sprite1.getGlobalBounds().left < npc4.getGlobalBounds().left)
		{
			sprite1.setPosition(npc4.getGlobalBounds().left - sprite1.getGlobalBounds().width, sprite1.getPosition().y);

		}
		else
		{
			sprite1.setPosition(npc4.getGlobalBounds().left + npc4.getGlobalBounds().width, sprite1.getPosition().y);
		}

		if (sprite1.getGlobalBounds().top < npc4.getGlobalBounds().top)
		{
			sprite1.setPosition(sprite1.getPosition().x, npc4.getGlobalBounds().top - sprite1.getGlobalBounds().height);
		}
		else
		{
			sprite1.setPosition(sprite1.getPosition().x, npc4.getGlobalBounds().top + npc4.getGlobalBounds().height);
		}
	}
}


