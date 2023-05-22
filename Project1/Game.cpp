#include"Game.h"


void Game::initVariables()
{
	this->view = sf::View(sf::FloatRect(0, 0, 530, 420));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	view.setCenter(215, 160);
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(960, 640);

	this->window = new sf::RenderWindow(this->videoMode, "Zwailian Life ", sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(60);
}

//Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::Coutmousepos()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousepos = sf::Mouse::getPosition(*window);

		std::cout << mousepos.x << " " << mousepos.y << std::endl;

	}
}

//Functions
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::initview(sf::RenderTarget& window)
{

	if (view.getCenter().x - view.getSize().x / 2 < 0)
	{
		view.setCenter(view.getSize().x / 2, view.getCenter().y);
	}
	if (view.getCenter().x + view.getSize().x / 2 > window.getSize().x)
	{
		view.setCenter(window.getSize().x - view.getSize().x / 2, view.getCenter().y);
	}
	if (view.getCenter().y - view.getSize().y / 2 < 0)
	{
		view.setCenter(view.getCenter().x, view.getSize().y / 2);
	}
	if (view.getCenter().y + view.getSize().y / 2 > window.getSize().y)
	{
		view.setCenter(view.getCenter().x, window.getSize().y - view.getSize().y / 2);
	}
	window.setView(view);
}	

void Game::updatePlayer()
{

	if (menu.getSpriteSlected())
	{
		player.updatePlayer(player.boyCharcter, this->window);
	}
	if (!menu.getSpriteSlected())
	{
		player.updatePlayer(player.girlCharacter, this->window);
	}
	intro.BusSene();
}

void Game::update()
{

	this->pollEvents();


	this->setbage();
	
	menu.updateMenu();

	this->Coutmousepos();

	menuState();

	menu.getmousepos(*window);
	
	menu.characterSelctionPage();

	this->updateView();

	if (menu.getPage() == 5)
	{
		player.Space();

		if (intro.cutSeneIsOver())
		{
			initview(*this->window);
		}

		map.updateBackgrowndBoundsCollision(player.boyCharcter);
		map.updateBackgrowndBoundsCollision(player.girlCharacter);
		
		intro.updateInput();

		this->updatePlayer();
		
	}
	if (menu.getPage() == 6)
	{
		initview(*this->window);
		this->updatePlayer();
	}
	if (menu.getPage() == 7)
	{
		initview(*this->window);
		this->updatePlayer();
	}
}

void Game::renderPlayer()
{
	if (player.getSpace())
	{
		if (menu.getSpriteSlected())
		{
			window->draw(player.boyCharcter);
		}
		if (!menu.getSpriteSlected())
		{
			window->draw(player.girlCharacter);
		}
			
	}
}


void Game::render()
{
	this->window->clear();



	//Render stuff
	menu.drawBackground(*window);

	menu.draw(*this->window);
	
	
	menu.renderCarcterSlection(*window);

	if (menu.getPage() == 5)
	{
		this->map.render(*this->window);

		this->renderPlayer();

		item.renderItems(player.boyCharcter, *window);


		
		this->initchat();

		if (npc.getI()) 
		{
			this->chat.GatenpcChat(*window);

			if (chat.FisPressed()) 
			{
				this->chat.GatenpcResponse1(*window);
			}
		}

		this->intro.render(*this->window);
	}

	if (menu.getPage() == 6)
	{
		map.renderoutdoors(*this->window);

		this->renderPlayer();
	}

	if (menu.getPage() == 7)
	{
		indoor.render(*this->window);

		this->renderPlayer();

		this->npc.render(*this->window);

		npc.rendernpc(*this->window);
	}


		this->window->display();
	
}

void Game::updateDt()
{
	/*Updates the dt variable with the time it takes to update and render one frame.*/

	this->dt = this->dtClock.restart().asSeconds();
}

void Game::setbage()
{
	if (map.gateposition(player.boyCharcter) && menu.getPage() == 5 || map.gateposition(player.girlCharacter) && menu.getPage() == 5)
	{
		player.setboyposition(Vector2f(400, 640));

		menu.setPagenum(6);
	}

	if (map.enteranceposition(player.boyCharcter) && menu.getPage() == 6 && Keyboard::isKeyPressed(Keyboard::Enter)
		|| map.enteranceposition(player.girlCharacter) && menu.getPage() == 6 && menu.getPage() == 6 && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		player.setboyposition(Vector2f(400, 640));
		menu.setPagenum(7);
	}

}

void Game::initchat()
{
	this->npc.render(*this->window);

	if (!chat.getechatisOver())
	{
		npc.initchat(player.boyCharcter, *window);
	}

	if (npc.getI())
	{
		this->chat.GatenpcChat(*window);

		if (chat.FisPressed())
		{
			this->chat.GatenpcResponse1(*window);
		}
	}
}


void Game::updateView()
{
	if (menu.getSpriteSlected())
	{
		view.setCenter(player.getBoyPosition().x+16, player.getBoyPosition().y+16);
	}
	if (!menu.getSpriteSlected())
	{
		view.setCenter(player.getgirlPosition().x + 16, player.getgirlPosition().y + 16);
	}
}

void Game::menuState()
{

	if (menu.getPage() == 3) 
	{
		this->window->close();
	}
	if (menu.getPage() == 0) 
	{
		menu.playername(*this->window, name);
	}
	if (menu.getPage() == 2)
	{
		menu.controls(*this->window);
	}
	if (menu.getPage() == 4)
	{
		
	}
	
}
