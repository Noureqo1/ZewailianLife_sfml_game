#include "game.h"

//loading font

void Chat::initFont()
{
	this->font.loadFromFile("assets/fonts/chat.ttf");
}

//initiating variables

Chat::Chat()
{
	doaaresp = 0;
	naggarresp = 0;
	wallidresp = 0;
	doaaAnswer = false;
	walidAnswer = false;
	naggarAnswer = false;
	chatdoaaIsover = false;
	chatnaggarIsover = false;
	chatwalidIsover = false;
	int times = 0;
	this->gatechatIsover = false;
	this->f = false;
	this->initFont();
	this->selected = 0;
}




int Chat::pressed()
{
	return selected;
}


void Chat::GatenpcChat(RenderWindow& window)
{
	this->gatenpcText[0].setFont(font);
	this->gatenpcText[0].setFillColor(Color::White);
	this->gatenpcText[0].setString
	("'hello and welcome \n \nto zewailian life\n \nhow can i help you?'");
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
	this->drDoaaText[0].setString("'hello iam DrDoaa\n\niam your csai151\n\ninstructor\n\nhow can i help you?'");
	this->drDoaaText[0].setCharacterSize(6);
	this->drDoaaText[0].setPosition(Vector2f(235, 200));

	this->drDoaaText[1].setFont(font);
	this->drDoaaText[1].setFillColor(Color::Yellow);
	this->drDoaaText[1].setString("1)i wanted to do my HW");
	this->drDoaaText[1].setCharacterSize(6);
	this->drDoaaText[1].setPosition(Vector2f(235, 253));

	this->drDoaaText[2].setFont(font);
	this->drDoaaText[2].setFillColor(Color::Yellow);
	this->drDoaaText[2].setString("2)i wanted to do my quiz");
	this->drDoaaText[2].setCharacterSize(6);
	this->drDoaaText[2].setPosition(Vector2f(235, 270));

	this->drDoaaText[3].setFont(font);
	this->drDoaaText[3].setFillColor(Color::Yellow);
	this->drDoaaText[3].setString("3)i will be back");
	this->drDoaaText[3].setCharacterSize(6);
	this->drDoaaText[3].setPosition(Vector2f(235, 290));



	for (int i = 0; i < 4; i++) {

		if (!doaaAnswer)
			window.draw(drDoaaText[i]);
	}
}



void Chat::DrdoaaResponse1(RenderWindow& window)
{
	initinputs();
	this->drDoaaresponse1Text[0].setFont(font);
	this->drDoaaresponse1Text[0].setFillColor(Color::White);
	this->drDoaaresponse1Text[0].setString("'if you want to\n\ndo your assignment\n\ngo find the assignment\n\nitem in the map'");
	this->drDoaaresponse1Text[0].setCharacterSize(6);
	this->drDoaaresponse1Text[0].setPosition(Vector2f(235, 200));
	if (!chatdoaaIsover)
	{
		if (doaaresp == 1)
		{
			doaaAnswer = true;
			window.draw(drDoaaresponse1Text[0]);
		}
		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			chatdoaaIsover = true;

			wallidresp = 0;
			naggarresp = 0;
		}
			
	}
}


void Chat::DrdoaaResponse2(RenderWindow& window)
{
	this->drDoaaresponse2Text[0].setFont(font);
	this->drDoaaresponse2Text[0].setFillColor(Color::White);
	this->drDoaaresponse2Text[0].setString("'if you want to do your quiz\n\ngo find the quiz item in the map'");
	this->drDoaaresponse2Text[0].setCharacterSize(6);
	this->drDoaaresponse2Text[0].setPosition(Vector2f(235, 200));
	if (!chatdoaaIsover)
	{
		if (doaaresp == 2)
		{
			doaaAnswer = true;
			window.draw(drDoaaresponse2Text[0]);
		}
		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			chatdoaaIsover = true;
			wallidresp = 0;
			naggarresp = 0;
		}
			

		if (doaaresp==3)
		{
			chatdoaaIsover = true;

			wallidresp = 0;
			naggarresp = 0;
		}
	}
}


void Chat::DrwalidChat(RenderWindow& window)
{
	this->drwalidText[0].setFont(font);
	this->drwalidText[0].setFillColor(Color::White);
	this->drwalidText[0].setString("'hello iam DrWalid\n\niam your math105\n\n instructor \n\nhow can i help you?'");
	this->drwalidText[0].setCharacterSize(6);
	this->drwalidText[0].setPosition(Vector2f(755, 220));

	this->drwalidText[1].setFont(font);
	this->drwalidText[1].setFillColor(Color::Yellow);
	this->drwalidText[1].setString("assignment");
	this->drwalidText[1].setCharacterSize(6);
	this->drwalidText[1].setPosition(Vector2f(755, 275));

	this->drwalidText[2].setFont(font);
	this->drwalidText[2].setFillColor(Color::Yellow);
	this->drwalidText[2].setString("quiz");
	this->drwalidText[2].setCharacterSize(6);
	this->drwalidText[2].setPosition(Vector2f(755, 300));

	this->drwalidText[3].setFont(font);
	this->drwalidText[3].setFillColor(Color::Yellow);
	this->drwalidText[3].setString("i will be back");
	this->drwalidText[3].setCharacterSize(6);
	this->drwalidText[3].setPosition(Vector2f(755, 320));

	for (int i = 0; i < 4; i++) {
		window.draw(drwalidText[i]);
	}
}


void Chat::AcademicNpcChat(RenderWindow& window)
{
	this->AcademicNpcText[0].setFont(font);
	this->AcademicNpcText[0].setFillColor(Color::White);
	this->AcademicNpcText[0].setString("'welcome to the academic \n\niam elnaggar \n\nhow can i help you?'");
	this->AcademicNpcText[0].setCharacterSize(6);
	this->AcademicNpcText[0].setPosition(Vector2f(737, 505));

	this->AcademicNpcText[1].setFont(font);
	this->AcademicNpcText[1].setFillColor(Color::Yellow);
	this->AcademicNpcText[1].setString("what are the\n\nitems here?");
	this->AcademicNpcText[1].setCharacterSize(6);
	this->AcademicNpcText[1].setPosition(Vector2f(740, 545));

	this->AcademicNpcText[2].setFont(font);
	this->AcademicNpcText[2].setFillColor(Color::Yellow);
	this->AcademicNpcText[2].setString("where is the\n\ninstructors office");
	this->AcademicNpcText[2].setCharacterSize(6);
	this->AcademicNpcText[2].setPosition(Vector2f(740, 570));

	this->AcademicNpcText[3].setFont(font);
	this->AcademicNpcText[3].setFillColor(Color::Yellow);
	this->AcademicNpcText[3].setString("i will be back ");
	this->AcademicNpcText[3].setCharacterSize(6);
	this->AcademicNpcText[3].setPosition(Vector2f(740, 600));



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
	this->AcademicNpcResponse2Text[0].setPosition(Vector2f(400, 50));
	window.draw(AcademicNpcResponse1Text[0]);
}

bool Chat::getdoaachatIsover()
{
	return chatdoaaIsover;
}

bool Chat::getwalidchatIsover()
{
	return chatwalidIsover;
}

bool Chat::getnaggarchatIsover()
{
	return chatnaggarIsover;
}

void Chat::initinputs()
{
	if (Keyboard::isKeyPressed(Keyboard::Num1))
	{
		doaaresp = 1;
		wallidresp = 1;
		naggarresp = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2))
	{
		doaaresp = 2;
		wallidresp = 2;
		naggarresp = 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3))
	{
		doaaresp = 3;
		wallidresp = 3;
		naggarresp = 3;
	}
}

//boolean that will be used to delete and display next chat

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