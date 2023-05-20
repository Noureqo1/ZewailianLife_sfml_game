#include "Game.h"

//page 100 = mainmenu window
//page 0 = enter your name window
//page 1 = volume window
//page 2 = controls window
//page 3 = exit program
//page 4 = select character window
//page 5 = cutscene window
//page 6 = outside the academic window
//page 7 = dr doaa office window
//page 8 = dr walid office window


void menu::initTexture()
{
	if (!this->boyTexture.loadFromFile("pic/Character1.png"))
	{
		std::cout << "ERROR::menu::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->girlTexture.loadFromFile("pic/Character2.png"))
	{
		std::cout << "ERROR::menu::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void menu::initSprite()
{
	this->boyCharcter.setTexture(this->boyTexture);
	this->boyCharcter.setTextureRect(sf::IntRect(0, 0, 16, 17));

	this->boyCharcter.scale(10.0f, 10.0f);
	this->boyCharcter.setPosition(300,200);



	this->girlCharacter.setTexture(this->girlTexture);
	this->girlCharacter.setTextureRect(sf::IntRect(0, 0, 16, 17));

	this->girlCharacter.scale(10.0f, 10.0f);
	this->girlCharacter.setPosition(600, 200);

}

menu::menu()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	initBackground();
}

menu::~menu() 
{

}

void menu::renderCarcterSlection(sf::RenderTarget& target)
{


	

	if (page == 4)
	{	
		target.clear();

		target.draw(this->bg);

		target.draw(this->boyCharcter);

		target.draw(this->girlCharacter);

		target.draw(SelectCharacterText);
	}


}

void menu::mainMenu()
{
	this->setDelay();

	if (page == 100)
	{

		if (inputEnabled && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moveup();
			inputEnabled = false;
			clock.restart();
		}
		if (inputEnabled && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movedown();
			inputEnabled = false;
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (pressed() == 0)
			{
				page = 0;
			}

			else if (pressed() == 1)
			{
				page = 1;
			}
			else if (pressed() == 2)
			{
				page = 2;
			}
			else if (pressed() == 3)
			{
				page = 3;
			}
		}
	}
}

void menu::characterSelctionPage()
{
	

	if (page == 4)
	{

		UpdateAnimation();
		
		SelectCharacterText.setFont(font);
		SelectCharacterText.setString("select your character");
		SelectCharacterText.setCharacterSize(70);
		SelectCharacterText.setPosition(10, 100);
		SelectCharacterText.setFillColor(Color::Green);

		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && girlCharacter.getGlobalBounds().contains(mouseposition))
		{

			

			cracterSelected = true;
			
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && boyCharcter.getGlobalBounds().contains(mouseposition))
		{
			
			cout << "lol";

			this->spriteSlected = true;

			cracterSelected = true;
		}


		if (cracterSelected)
		{
			page = 5;
		}



	}

}

void menu::UpdateAnimation()
{
	timer += 1;

	if (timer >= animationTimer)
	{
		this->boyCharcter.setTextureRect(sf::IntRect(16, y * 17, 16, 17));

		y++;

		y = y % 3;

	}

	if (timer >= animationTimer)
	{
		this->girlCharacter.setTextureRect(sf::IntRect(0, y * 17, 16, 17));
		y++;
		y = y % 3;
		timer = 0;
	}
	
}

void menu::movedown()
{
	if (selected + 1 <= 4) {
		mainmenu[selected].setFillColor(Color::White);
		selected++;
		if (selected == 4) {
			selected = 0;

		}
		mainmenu[selected].setFillColor(Color::Yellow);
	}
}
void menu::set_selected(int n)
{
	selected = n;
}

bool menu::getSpriteSlected()
{
	return spriteSlected;
}





int menu::getPage()
{
	return this->page;
}

void menu::initVariables()
{
	delay = sf::seconds(0.3f);
	inputEnabled = true;
	this->selected = 0;
	 
	timer = 0;
	animationTimer = 15;

	this->y = 0;
	
	rectHeight = 50.0f;
	rectWidth = 30.0f;
	recselected = 0;
	cracterSelected = false;
	
	spriteSlected = false;

	font.loadFromFile("assets/fonts/Barlock.otf");
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Yellow);
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(90);
	mainmenu[0].setPosition(Vector2f(400, 640 / (10)));

	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::White);
	mainmenu[1].setString("volume");
	mainmenu[1].setCharacterSize(90);
	mainmenu[1].setPosition(Vector2f(400, 640 / (10) + 100));

	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::White);
	mainmenu[2].setString("controlsss");
	mainmenu[2].setCharacterSize(90);
	mainmenu[2].setPosition(Vector2f(400, 640 / (10) + 200));

	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(Color::White);
	mainmenu[3].setString("exit");
	mainmenu[3].setCharacterSize(90);
	mainmenu[3].setPosition(Vector2f(400, 640 / (10) + 300));
	
}

void menu::setDelay()
{
	if (!inputEnabled)
	{
		// Check if the delay time has passed
		if (clock.getElapsedTime() >= delay)
		{
			// Enable input and reset the timer
			inputEnabled = true;
			clock.restart();
		}
	}
}

void menu::updateMenu()
{
	this->mainMenu();
	this->UpdateAnimation();
}




void menu::playername(RenderWindow& window, string& name)
{
	if (!name.empty()) 
	{
		name.clear();
	}
	Font font;
	font.loadFromFile("assets/fonts/Barlock.otf");
	Text HeadText;
	Text NameText;
	HeadText.setFont(font);
	NameText.setFont(font);
	HeadText.setString("enter your name");
	HeadText.setCharacterSize(70);
	NameText.setCharacterSize(70);
	HeadText.setPosition(10, 10);
	NameText.setPosition(10, 100);
	HeadText.setFillColor(Color::Green);
	NameText.setFillColor(Color::White);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed()) {
				window.close();
			}
			if (event.type == Event::TextEntered) {
				name += static_cast<char>(event.text.unicode);
			}
			if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
				name.resize(name.size() - 1);
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() > 1) {
				page = 4;
				return;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				page = 100;
				return;
			}
		}
		NameText.setString(name);
		window.clear();
		drawBackground(window);
		window.draw(HeadText);
		window.draw(NameText);
		window.display();
	}

}

void menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(mainmenu[i]);
	}
	
}
void menu::moveup()
{
	if (selected - 1 >= -1) {
		mainmenu[selected].setFillColor(Color::White);
		selected--;
		if (selected == -1) {
			selected = 3;
		}
		mainmenu[selected].setFillColor(Color::Yellow);
	}
}


void menu::controls(RenderWindow& window)
{
	font.loadFromFile("assets/fonts/Barlock.otf");
	controlstext[0].setFont(font);
	controlstext[0].setFillColor(Color::Yellow);
	controlstext[0].setString("Move up:   up");
	controlstext[0].setCharacterSize(50);
	controlstext[0].setPosition(Vector2f(100, 640 / (15)));

	controlstext[1].setFont(font);
	controlstext[1].setFillColor(Color::Yellow);
	controlstext[1].setString("Move down:   down");
	controlstext[1].setCharacterSize(50);
	controlstext[1].setPosition(Vector2f(100, 640 / (15) + 75));

	controlstext[2].setFont(font);
	controlstext[2].setFillColor(Color::Yellow);
	controlstext[2].setString("Move right:   right");
	controlstext[2].setCharacterSize(50);
	controlstext[2].setPosition(Vector2f(100, 640 / (15) + 150));

	controlstext[3].setFont(font);
	controlstext[3].setFillColor(Color::Yellow);
	controlstext[3].setString("Move left:   left");
	controlstext[3].setCharacterSize(50);
	controlstext[3].setPosition(Vector2f(100, 640 / (15) + 225));

	controlstext[4].setFont(font);
	controlstext[4].setFillColor(Color::Yellow);
	controlstext[4].setString("Pick up item:   space");
	controlstext[4].setCharacterSize(50);
	controlstext[4].setPosition(Vector2f(100, 640 / (15) + 300));

	controlstext[5].setFont(font);
	controlstext[5].setFillColor(Color::Yellow);
	controlstext[5].setString("Interact:   I");
	controlstext[5].setCharacterSize(50);
	controlstext[5].setPosition(Vector2f(100, 640 / (15) + 375));

	controlstext[6].setFont(font);
	controlstext[6].setFillColor(Color::Yellow);
	controlstext[6].setString("Enter a room:   Enter");
	controlstext[6].setCharacterSize(50);
	controlstext[6].setPosition(Vector2f(100, 640 / (15) + 450));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed())
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				page = 100;
				return;
			}

		}
		window.clear();

		
		drawBackground(window);

		window.draw(controlstext[1]);
		window.draw(controlstext[2]);
		window.draw(controlstext[3]);
		window.draw(controlstext[4]);
		window.draw(controlstext[5]);
		window.draw(controlstext[6]);

		window.display();

	}
}



sf::Vector2f menu::getmousepos(RenderWindow& window)
{
	mouseposition = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	return mouseposition;
}

void menu::drawBackground(RenderWindow& window)
	{

		window.draw(bg);

	}

	void menu::initBackground()
	{
		menuBackground.loadFromFile("assets/backgrownd.png");
		bg.setTexture(menuBackground);
	}
