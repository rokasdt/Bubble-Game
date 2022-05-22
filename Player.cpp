#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initShape()
{
	this->shape.setFillColor(Color::Green);
	this->shape.setSize(Vector2f(50.f, 50.f)); //.f = float
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y); //zaidejo pozicija

	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::updateInput()
{
	//keyboard
	if (Keyboard::isKeyPressed(Keyboard::A)) //ar mygtukas paspaustas
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) 
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) 
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const RenderTarget* target)
{
	FloatRect playerBounds = this->shape.getGlobalBounds();
	//kaire siena
	if (playerBounds.left <= 0.f) //ar kairys zaidejo figuros kampas susiliecia su siena
		this->shape.setPosition(0.f, playerBounds.top);
	//desine siena
	if (playerBounds.left + playerBounds.width >= target->getSize().x) //lyginama desine siena su desiniu zaidejo figuros kampu
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top); //reikia atimti zaidejo figuros ploti, kad butu imamas desinys kampas vietoj kairio
	//virsus
	if (playerBounds.top <= 0.f) 
		this->shape.setPosition(playerBounds.left, 0.f);
	//apacia
	if (playerBounds.top + playerBounds.height >= target->getSize().y) 
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);

}

void Player::update(const RenderTarget* target)
{
	this->updateInput();

	//atsitrenkimas i siena
	this->updateWindowBoundsCollision(target);
}

void Player::render(RenderTarget* target)
{
	target->draw(this->shape);
}

