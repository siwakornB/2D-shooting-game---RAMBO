#pragma once
#include <SFML/Graphics.hpp>
class bullet
{
public:
	bullet();
	~bullet();
	sf::RectangleShape shot;

	sf::Clock duration;
	float ang, damage = 7;
	void bullet_move();
	bool visible = 0;
};

