#pragma once
#include "Game.h"
class buttons
{
private:

    Texture buttonTexture;
    Sprite button;

    void initTeaxture();
    void initSprites();


public:

    buttons();

    void renderItems(sf::RenderTarget& target);
};

