#include "Player.h"

void Player::initVariables()
{
}

void Player::initShape()
{
	this->shape.setFillColor(Color::Green);
	this->shape.setSize(Vector2f(50.f, 50.f)); //f = float
}

Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(RenderTarget* target)
{
	target->draw(this->shape);
}

