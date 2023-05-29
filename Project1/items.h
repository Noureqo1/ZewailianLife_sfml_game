#pragma once
#include"Game.h"

class items
{
private:

    Texture idTexture;
    Sprite id;

    bool itemIspicked;

    void initTeaxture();
    void initSprites();


public:

    items();
    ~items();

    void updateItiem(sf::Sprite sprite);

    bool getitemidpicked();

    void renderItems(sf::RenderTarget& target);
};

