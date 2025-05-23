#include "game.h"

sound::sound()
{
	// Load the sound file
	music.openFromFile("assets/sound/1.wav");
	//repeat sound
	music.setLoop(true);
	//play the sound
	music.play();

	font.loadFromFile("assets/fonts/Barlock.otf");
	volumeText[0].setFont(font);
	volumeText[0].setString("press M to mute");
	volumeText[0].setCharacterSize(40);
	volumeText[0].setPosition(75, 150);
	volumeText[0].setFillColor(Color::Red);

	volumeText[1].setFont(font);
	volumeText[1].setString("press up to Raise the Volume");
	volumeText[1].setCharacterSize(40);
	volumeText[1].setPosition(75, 300);
	volumeText[1].setFillColor(Color::Green);

	volumeText[2].setFont(font);
	volumeText[2].setString("press up to lower the Volume");
	volumeText[2].setCharacterSize(40);
	volumeText[2].setPosition(75, 450);
	volumeText[2].setFillColor(Color::Green);
}

void sound::volume(RenderWindow& window)
{
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed()) {
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::M))
			{
				music.setVolume(0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				music.setVolume(music.getVolume() + 10);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				music.setVolume(music.getVolume() - 10);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				menu.setPagenum(100);
				return;
			}
		}
		window.clear();



		menu.drawPlainBackground(window);

		window.draw(volumeText[0]);
		window.draw(volumeText[1]);
		window.draw(volumeText[2]);

		window.display();
	}
}