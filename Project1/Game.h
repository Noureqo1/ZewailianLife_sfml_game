#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include<ctime>
#include<vector>
#include "map.h"
#include"player.h"
#include "CutSene.h"
#include "menu.h"
#include "NPC.h"
#include"Chat.h"
#include"indoorsMap.h"
#include "sound.h"
#include"items.h"
#include <string>


class Game
{
private:

	sf::View view;

	sf::Clock dtClock;
	float dt;

	sf::Vector2f position;

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	sf::Vector2i mousepos;

	string name;

	CutSene intro;

	Map map;

	Player player;

	menu menu;

	NPC npc;

	Chat chat;

	items item;

	indoorsMap indoor;

	sound sound;

	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	void Coutmousepos();

	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();
	void initview(sf::RenderTarget& window);

	void initchat();

	void updateView();

	void updatePlayer();

	void renderPlayer();

	void updateDt();

	void setbage();

	void menuState();

	void update();

	void render();

};