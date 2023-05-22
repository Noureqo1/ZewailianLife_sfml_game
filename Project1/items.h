#pragma once
#include"Game.h"

class items
{
private:

    Texture idTexture;
    Sprite id;

    bool drawId;

    void initTeaxture();
    void initSprites();

public:

    items();
    ~items();

    void renderItems(sf::Sprite sprite , sf::RenderTarget& target);
};

