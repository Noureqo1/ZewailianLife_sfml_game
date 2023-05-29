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
    this->id.scale(5.0f, 5.0f);
    this->id.setPosition(190, 500);
}

items::items()
{    
    
    this->initSprites();
    this->initTeaxture();
    this->itemIspicked = false;


}

items::~items()
{
}



void items::renderItems(sf::RenderTarget& target)
{    
    target.draw(id);
}

void items::updateItiem(sf::Sprite sprite)
{
    if (sprite.getGlobalBounds().intersects(this->id.getGlobalBounds()))
    {
       itemIspicked = true;
    }
}

bool items::getitemidpicked()
{
    return itemIspicked;
}
