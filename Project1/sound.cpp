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
	volumeText[0].setString("press down to mute");
	volumeText[0].setCharacterSize(60);
	volumeText[0].setPosition(75, 150);
	volumeText[0].setFillColor(Color::Red);

	volumeText[1].setFont(font);
	volumeText[1].setString("press up to unmute");
	volumeText[1].setCharacterSize(60);
	volumeText[1].setPosition(75, 350);
	volumeText[1].setFillColor(Color::Green);
}

void sound::volume(RenderWindow& window)
{
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed()) {
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				music.setVolume(0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				music.setVolume(100);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				menu.setPagenum(100);
				return;
			}
		}
		window.clear();



		menu.drawBackground(window);

		window.draw(volumeText[0]);
		window.draw(volumeText[1]);

		window.display();
	}
}