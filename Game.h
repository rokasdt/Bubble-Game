#pragma once

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

using namespace sf;

class Game
{
private:
	VideoMode videoMode; //storina window informacija
	RenderWindow* window; //pagrindinis
	bool endGame;
	Event sfmlEvent; //pullina kiekviena ivyki

	Player player;

	void initVariables();
	void initWindow(); //Sukuria window

public:
	//Konstruktoriai ir destruktoriai
	Game();
	~Game();

	//Accessors (priedai?)

	//Modai

	//Funkcijos
	const bool running() const;
	void pollEvents();

	void update();
	void render();

};
