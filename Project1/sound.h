#include"Game.h"
#include"menu.h"

class sound {

public:

    sound();

    void volume(RenderWindow& window);

private:

    Font font;

    Text volumeText[3];

    menu menu;

    Music music;

};
