#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;

class Balls
{
private:
	CircleShape shape;

	void initShape();
public:
	Balls();
	virtual ~Balls();
	

	//Funkcijos
	void update();
	void render(RenderTarget& target);
};

