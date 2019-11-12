#include "bullet.h"



bullet::bullet()
{
	shot.setSize(sf::Vector2f(10, 10));
	shot.setFillColor(sf::Color::White);
	shot.setOrigin(5, 5);
}


bullet::~bullet()
{

}

void bullet::bullet_move()
{
	float x,y;
	x = cos(ang);
	y = sin(ang);
	shot.move(3*x, 3*y);
}