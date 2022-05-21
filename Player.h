#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

class Player
{
private:
	RectangleShape shape;

	void initVariables();
	void initShape();

public:
	Player();
	virtual ~Player();

	void update();
	void render(RenderTarget* target);
};

