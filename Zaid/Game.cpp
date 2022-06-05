#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Zaidimas", Style::Close || Style::Titlebar);
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
}

void Game::initFonts()
{
	this->font.loadFromFile("Fonts/PixellettersFull.ttf");
}

void Game::initText()
{
	this->text.setFont(this->font);
	this->text.setFillColor(Color::White);
	this->text.setCharacterSize(32);

	//end game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(Color::Red);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(Vector2f(270, 75));
	this->endGameText.setString("GAME OVER");
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}


//funkcijos
const bool Game::running() const
{
	return this->window->isOpen();
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

void Game::spawnBalls()
{
	//timer
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->Ball.size() < this->maxBalls)
		{
			this->Ball.push_back(Balls(*this->window, this->randBallType()));

			this->spawnTimer = 0.f;
		}

	}
}

const int Game::randBallType() const
{
	int type = BallTypes::DEFAULT;

	int randValue = rand() % 100 + 1;
	if (randValue > 84 && randValue <= 94)
		type = BallTypes::DAMAGING;
	else if (randValue > 94 && randValue <= 99)
		type = BallTypes::HEALING;
	else if (randValue > 99 && randValue <= 100)
		type = BallTypes::SPEED;

	return type;
}

void Game::updatePlayer()
{
	this->player.update(this->window);

	if (this->player.getHp() <= 0)
		this->endGame = true;
}

void Game::updateCollisions()
{
	//patikrinti collision
	for (size_t i = 0; i < this->Ball.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->Ball[i].getShape().getGlobalBounds()))
		{
			switch (this->Ball[i].getType())
			{
			case BallTypes::DEFAULT:
				this->points += 10;
				this->player.gainSpeed(1);
				break;
			case BallTypes::DAMAGING:
				this->player.takeDamage(1);
				break;
			case BallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			case BallTypes::SPEED:
				this->player.resetSpeed(1);
				break;
			}

			//ball pasalinimas
			this->Ball.erase(this->Ball.begin() + i);
		}
	}

}

void Game::updateText()
{
	std::stringstream ss; //pavercia data i string, kad butu galima printint

	ss << "Points: " << this->points << "\n";
	ss << "Health: " << this->player.getHp() << " / " << this->player.getHpMax() << "\n";

	this->text.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->spawnBalls();
		this->updatePlayer();
		this->updateCollisions();
		this->updateText();
	}
}

void Game::renderText(RenderTarget* target)
{
	target->draw(this->text);
}

void Game::render()
{

	this->window->clear(); //isvalo

	texture.loadFromFile("Backround/Kanye.png");
	Sprite backround(texture);
	this->window->draw(backround);

	//renderina
	this->player.render(this->window);

	for (auto i : this->Ball)
	{
		i.render(*this->window);
	}


	//render text
	this->renderText(this->window);

	//render end text
	if (this->endGame == true)
		this->window->draw(this->endGameText);

	this->window->display();


}

