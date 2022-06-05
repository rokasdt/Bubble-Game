#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Player.h"
#include "Balls.h"

using namespace sf;

class Game
{
private:
	VideoMode videoMode; //storina window informacija
	RenderWindow* window; //pagrindinis
	bool endGame;
	Event sfmlEvent; //pullina kiekviena ivyki

	Player player;

	int points;

	Texture texture;
	Texture playerTexture;
	Font font;
	Text text;
	Text endGameText;

	std::vector<Balls> Ball;
	float spawnTimerMax;
	float spawnTimer;
	int maxBalls;

	void initVariables();
	void initWindow(); //Sukuria window
	void initFonts();
	void initText();

public:
	//Konstruktoriai ir destruktoriai
	Game();
	~Game();

	//Accessors (priedai?)
	const bool& getEndGame() const;

	//Funkcijos
	const bool running() const;
	void pollEvents();

	void spawnBalls();
	const int randBallType() const;
	void updatePlayer();
	void updateCollisions();
	void updateText();
	void update();

	void renderText(RenderTarget* target);
	void render();

};
