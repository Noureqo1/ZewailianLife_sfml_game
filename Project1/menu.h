#pragma once
#include "Game.h"

using namespace sf;
using namespace std;
class menu
{
private:


	Sprite bg;
	Texture menuBackground;

	int selected, recselected;
	Font font;
	int page = 100;
	sf::Clock clock;
	sf::Time delay;
	bool inputEnabled;

	bool cracterSelected;

	std::vector<sf::RectangleShape> rectangles;

	float rectWidth;
	float rectHeight;

	Text SelectCharacterText;

	int timer, animationTimer;


	sf::Sprite boyCharcter,girlCharacter;
	sf::Texture boyTexture, girlTexture;

	bool spriteSlected ;


	Text controlstext[7];
	Event event;

	sf::Vector2f mouseposition;

	int y;

	void initTexture();
	void initSprite();


public:
	
	Text mainmenu[4];

	menu();
	~menu();


	void renderCarcterSlection(sf::RenderTarget& target);

	void mainMenu();
	void characterSelctionPage();

	void UpdateAnimation();

	int getPage();
	void initVariables();
	void setDelay();
	void updateMenu();
	void playername(RenderWindow& window, string& name);
	void draw(RenderWindow& window);
	void moveup();


	void controls(RenderWindow& window);


	sf::Vector2f getmousepos(RenderWindow& window);

	void drawBackground(RenderWindow& window);

	void initBackground();

	void movedown();

	void set_selected(int n);

	bool getSpriteSlected();



	int pressed() 
	{
		return selected;
	}
};