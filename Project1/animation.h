#pragma once
#include "Game.h"

class animation
{
private:

   int x;
   int y;
   int timer ;
   int animationTimer ;

public:
    animation();

    void UpdateAnimation(sf::Sprite& sprite);
};

