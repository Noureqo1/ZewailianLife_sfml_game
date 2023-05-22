#include "game.h"

void Chat::initFont()
{
	this->font.loadFromFile("assets/fonts/chat.ttf");
}


Chat::Chat()
{
	int times = 0;
	this->gatechatIsover = false;
	this->f = false;
	this->initFont();
	this->selected = 0;
}

void Chat::chatSelection()
{

}


int Chat::pressed()
{
	return selected;
}


void Chat::moveup()
{
	if (selected - 1 >= -1) {
		drDoaaText[selected].setFillColor(Color::White);
		selected--;
		if (selected == 0)
		{
			selected = 3;
		}
		drDoaaText[selected].setFillColor(Color::Yellow);
	}
}


void Chat::movedown()
{
	if (selected + 1 <= 4) {
		drDoaaText[selected].setFillColor(Color::White);
		selected++;
		if (selected == 4)
		{
			selected = 1;
		}
		drDoaaText[selected].setFillColor(Color::Yellow);
	}

}


void Chat::GatenpcChat(RenderWindow& window)
{
	this->gatenpcText[0].setFont(font);
	this->gatenpcText[0].setFillColor(Color::White);
	this->gatenpcText[0].setString
	("hello and welcome \n \nto zewailian life\n \nhow can i help you?");
	this->gatenpcText[0].setCharacterSize(6);
	this->gatenpcText[0].setPosition(Vector2f(295, 490));

	this->gatenpcText[1].setFont(font);
	this->gatenpcText[1].setFillColor(Color::Yellow);
	this->gatenpcText[1].setString("how can i get inside");
	this->gatenpcText[1].setCharacterSize(6);
	this->gatenpcText[1].setPosition(Vector2f(295, 540));

	FisPressed();

	for (int i = 0; i < 2; i++) {
		if (!f)
			window.draw(gatenpcText[i]);

	}
}


void Chat::GatenpcResponse1(RenderWindow& window)
{
	this->GatenpcresponseText[0].setFont(font);
	this->GatenpcresponseText[0].setFillColor(Color::White);
	this->GatenpcresponseText[0].setString("'you can get inside\n\nby picking up ID card\n\nthat you will find \n\nin the map'");
	this->GatenpcresponseText[0].setCharacterSize(6);
	this->GatenpcresponseText[0].setPosition(Vector2f(293, 490));

	this->GatenpcresponseText[1].setFont(font);
	this->GatenpcresponseText[1].setFillColor(Color::Yellow);
	this->GatenpcresponseText[1].setString("thanks ahmed");
	this->GatenpcresponseText[1].setCharacterSize(8);
	this->GatenpcresponseText[1].setPosition(Vector2f(300, 550));

	for (int i = 0; i < 2; i++)
	{
		if (!gatechatIsover)
		{
			window.draw(GatenpcresponseText[i]);

			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				gatechatIsover = true;
			}
		}

	}

}


void Chat::DrdoaaChat(RenderWindow& window)
{
	this->drDoaaText[0].setFont(font);
	this->drDoaaText[0].setFillColor(Color::White);
	this->drDoaaText[0].setString("hello my name is DrDoaa iam your csai151 instructor how can i help you? ");
	this->drDoaaText[0].setCharacterSize(6);
	this->drDoaaText[0].setPosition(Vector2f(293, 490));

	this->drDoaaText[1].setFont(font);
	this->drDoaaText[1].setFillColor(Color::Yellow);
	this->drDoaaText[1].setString("i wanted to do my assignment");
	this->drDoaaText[1].setCharacterSize(6);
	this->drDoaaText[1].setPosition(Vector2f(293, 520));

	this->drDoaaText[2].setFont(font);
	this->drDoaaText[2].setFillColor(Color::White);
	this->drDoaaText[2].setString("i wanted to do my quiz");
	this->drDoaaText[2].setCharacterSize(6);
	this->drDoaaText[2].setPosition(Vector2f(293, 540));

	this->drDoaaText[3].setFont(font);
	this->drDoaaText[3].setFillColor(Color::White);
	this->drDoaaText[3].setString("nothing i will come back another time");
	this->drDoaaText[3].setCharacterSize(6);
	this->drDoaaText[3].setPosition(Vector2f(293, 560));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveup();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movedown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		if (pressed() == 1)
		{
			DrdoaaResponse1(window);
		}
		else if (pressed() == 2)
		{
			DrdoaaResponse2(window);
		}
		else if (pressed() == 3)
		{


		}
	}
	for (int i = 0; i < 4; i++) {
		window.draw(drDoaaText[i]);
	}
}



void Chat::DrdoaaResponse1(RenderWindow& window)
{
	this->drDoaaresponse1Text[0].setFont(font);
	this->drDoaaresponse1Text[0].setFillColor(Color::White);
	this->drDoaaresponse1Text[0].setString("if you want to do your assignment go find the assignment item in the map ");
	this->drDoaaresponse1Text[0].setCharacterSize(6);
	this->drDoaaresponse1Text[0].setPosition(Vector2f(400, 640 / (10)));

	window.draw(drDoaaresponse1Text[0]);

}


void Chat::DrdoaaResponse2(RenderWindow& window)
{
	this->drDoaaresponse2Text[0].setFont(font);
	this->drDoaaresponse2Text[0].setFillColor(Color::White);
	this->drDoaaresponse2Text[0].setString("if you want to do your quiz go find the quiz item in the map ");
	this->drDoaaresponse2Text[0].setCharacterSize(6);
	this->drDoaaresponse2Text[0].setPosition(Vector2f(400, 640 / (10)));
	window.draw(drDoaaresponse2Text[0]);
}

void Chat::DrdoaaResponse3(RenderWindow& window)
{

}

void Chat::DrdoaaResponse4(RenderWindow& window)
{

}


void Chat::DrwalidChat(RenderWindow& window)
{
	this->drwalidText[0].setFont(font);
	this->drwalidText[0].setFillColor(Color::White);
	this->drwalidText[0].setString("hello my name is DrWalid,iam your math105 instructor how can i help you?");
	this->drwalidText[0].setCharacterSize(6);
	this->drwalidText[0].setPosition(Vector2f(400, 640 / (10)));

	this->drwalidText[1].setFont(font);
	this->drwalidText[1].setFillColor(Color::White);
	this->drwalidText[1].setString("i wanted to do my assignment");
	this->drwalidText[1].setCharacterSize(6);
	this->drwalidText[1].setPosition(Vector2f(400, 640 / (10)));

	this->drwalidText[2].setFont(font);
	this->drwalidText[2].setFillColor(Color::White);
	this->drwalidText[2].setString("i wanted to do my quiz");
	this->drwalidText[2].setCharacterSize(6);
	this->drwalidText[2].setPosition(Vector2f(400, 640 / (10)));

	this->drwalidText[3].setFont(font);
	this->drwalidText[3].setFillColor(Color::White);
	this->drwalidText[3].setString("nothing i will come another time");
	this->drwalidText[3].setCharacterSize(6);
	this->drwalidText[3].setPosition(Vector2f(400, 640 / (10)));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveup();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movedown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{

		if (pressed() == 1)
		{
			DrdoaaResponse1(window);
		}
		else if (pressed() == 2)
		{
			DrdoaaResponse2(window);
		}
		else if (pressed() == 3)
		{

		}
	}
	for (int i = 0; i < 4; i++)
	{
		window.draw(drwalidText[i]);
	}
}


void Chat::AcademicNpcChat(RenderWindow& window)
{
	this->AcademicNpcText[0].setFont(font);
	this->AcademicNpcText[0].setFillColor(Color::White);
	this->AcademicNpcText[0].setString("hello and welcome to academic building my name is elnaggar how can i help you?");
	this->AcademicNpcText[0].setCharacterSize(6);
	this->AcademicNpcText[0].setPosition(Vector2f(400, 640 / (10)));

	this->AcademicNpcText[1].setFont(font);
	this->AcademicNpcText[1].setFillColor(Color::White);
	this->AcademicNpcText[1].setString("what are the items here?");
	this->AcademicNpcText[1].setCharacterSize(6);
	this->AcademicNpcText[1].setPosition(Vector2f(400, 640 / (10)));

	this->AcademicNpcText[2].setFont(font);
	this->AcademicNpcText[2].setFillColor(Color::White);
	this->AcademicNpcText[2].setString("where are the instructors office");
	this->AcademicNpcText[2].setCharacterSize(6);
	this->AcademicNpcText[2].setPosition(Vector2f(400, 640 / (10)));

	this->AcademicNpcText[3].setFont(font);
	this->AcademicNpcText[3].setFillColor(Color::White);
	this->AcademicNpcText[3].setString("i will be back later");
	this->AcademicNpcText[3].setCharacterSize(6);
	this->AcademicNpcText[3].setPosition(Vector2f(400, 640 / (10)));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveup();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movedown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{

		if (pressed() == 1)
		{
			AcademicNpcResponse1(window);
		}
		else if (pressed() == 2)
		{
			AcademicNpcResponse2(window);
		}
		else if (pressed() == 3)
		{

		}
	}

	for (int i = 0; i < 4; i++) {
		window.draw(AcademicNpcText[i]);
	}
}


void Chat::AcademicNpcResponse1(RenderWindow& window)
{
	this->AcademicNpcResponse1Text[0].setFont(font);
	this->AcademicNpcResponse1Text[0].setFillColor(Color::White);
	this->AcademicNpcResponse1Text[0].setString("in the academic building you can find the quizes items and outside you can find the assignments items");
	this->AcademicNpcResponse1Text[0].setCharacterSize(6);
	this->AcademicNpcResponse1Text[0].setPosition(Vector2f(400, 640 / (10)));
	window.draw(AcademicNpcResponse1Text[0]);
}


void Chat::AcademicNpcResponse2(RenderWindow& window)
{
	this->AcademicNpcResponse2Text[0].setFont(font);
	this->AcademicNpcResponse2Text[0].setFillColor(Color::White);
	this->AcademicNpcResponse2Text[0].setString("the room on your left is Drwalid's and on the right is Drdoaa's room ");
	this->AcademicNpcResponse2Text[0].setCharacterSize(6);
	this->AcademicNpcResponse2Text[0].setPosition(Vector2f(400, 640 / (10)));
	window.draw(AcademicNpcResponse1Text[0]);
}



bool Chat::FisPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		f = true;
		times += 1;
	}
	return f;
}

bool Chat::getechatisOver()
{
	return gatechatIsover;
}
