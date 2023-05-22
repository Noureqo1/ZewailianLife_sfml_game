#pragma once
#include"Game.h"

class Chat
{
private:
	int times;
	bool gatechatIsover;
	bool f;
	Font font;
	Text gatenpcText[2];
	Text GatenpcresponseText[2];

	Text drDoaaText[4];
	Text drDoaaresponse1Text[1];
	Text drDoaaresponse2Text[1];
	Text drDoaaresponse3Text[1];
	Text drDoaaresponse4Text[1];

	Text drwalidText[4];
	Text drwalidresponse1Text[1];
	Text drwalidresponse2Text[1];
	Text drwalidresponse3Text[1];
	Text drwalidresponse4Text[1];

	Text AcademicNpcText[4];
	Text AcademicNpcResponse1Text[1];
	Text AcademicNpcResponse2Text[1];

	int selected;

	void initFont();

public:

	Chat();

	void chatSelection();

	int pressed();

	void moveup();

	void movedown();

	void GatenpcChat(RenderWindow& window);

	void GatenpcResponse1(RenderWindow& window);

	void DrdoaaChat(RenderWindow& window);

	void DrdoaaResponse1(RenderWindow& window);

	void DrdoaaResponse2(RenderWindow& window);

	void DrdoaaResponse3(RenderWindow& window);

	void DrdoaaResponse4(RenderWindow& window);

	void DrwalidChat(RenderWindow& window);

	void DrwalidResponse(RenderWindow& window);

	void AcademicNpcChat(RenderWindow& window);

	void AcademicNpcResponse1(RenderWindow& window);

	void AcademicNpcResponse2(RenderWindow& window);

	bool FisPressed();
};

