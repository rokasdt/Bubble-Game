#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum BallTypes { DEFAULT = 0, DAMAGING, HEALING, SPEED, NROFTYPES }; //nroftypes paskutinis, nes automatiskai zinosi kiek tipu yra

using namespace sf;

class Balls
{
private:
	CircleShape shape;
	int type;

	void initShape(const RenderWindow& window);
public:
	Balls(const RenderWindow& window, int type);
	virtual ~Balls();

	//Accessor(?)
	const CircleShape getShape() const;
	const int& getType() const;


	//Funkcijos
	void update();
	void render(RenderTarget& target);
};

