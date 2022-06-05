#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->hpMax = 3;
	this->hp = hpMax;
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

const RectangleShape& Player::getShape() const
{
	return this->shape;
}

//accessors
const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

//funkcijos
void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;

	if (this->hp < 0)
		this->hp = 0;


}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;
	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

void Player::gainSpeed(const int speed)
{
	this->movementSpeed += 0.1;
}

void Player::resetSpeed(const int speed)
{
	this->movementSpeed = 10.f;
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

	//kaire siena
	if (this->shape.getGlobalBounds().left <= 0.f) //ar kairys zaidejo figuros kampas susiliecia su siena
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//desine siena
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) //lyginama desine siena su desiniu zaidejo figuros kampu
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top); //reikia atimti zaidejo figuros ploti, kad butu imamas desinys kampas vietoj kairio
	//virsus
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//apacia
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);

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

