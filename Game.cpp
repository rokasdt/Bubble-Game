//visos pozicijos daromos koordinaciu sistemoje, 0.f = kairys, virsutinis kampas.

#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Zaidimas", Style::Close || Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Konstruktoriai ir destruktoriai
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen(); //kol open, returnins true
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) //trikrina koks ivykis
	{
		switch (this->sfmlEvent.type)
		{
		case Event::Closed: //jei uzdaryti, tai uzdaro window
			this->window->close();
			break;
		case Event::KeyPressed: //jei mygtukas paspaustas
			if (this->sfmlEvent.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->player.update(this->window);
}

void Game::render()
{
	this->window->clear(); //isvalo

	//renderina
	this->player.render(this->window);

	this->window->display();
}

