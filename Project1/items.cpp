#include"Game.h"

void items::initTeaxture()
{
    if (!this->idTexture.loadFromFile("assets/Itemes/id.png"))
    {
        std::cout << "ERROR::NPC::INITTEXTURE::Could not load texture file." << "\n";
    }
}

void items::initSprites()
{
    id.setTexture(idTexture);
    this->id.scale(2.0f, 2.0f);
    this->id.setPosition(190, 500);
}

items::items()
{
    this->drawId = true;

    this->initSprites();
    this->initTeaxture();
}

items::~items()
{
}

void items::renderItems(sf::Sprite sprite, RenderTarget& target)
{
    if (sprite.getGlobalBounds().intersects(this->id.getGlobalBounds()))
    {
        drawId = false;
    }

    if (drawId == true)
        target.draw(id);
    
}
