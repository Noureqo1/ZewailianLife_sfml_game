#include "game.h"

sound::sound()
{
	// Load the sound file
	music.openFromFile("assets/sound/1.wav");
	music.setLoop(true);
	music.play();

}