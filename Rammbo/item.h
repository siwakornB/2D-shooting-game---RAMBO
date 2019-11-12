#pragma once
#include <SFML/Graphics.hpp>
#include "character.h"
class item
{
public:
	item();
	~item();

	
	sf::RectangleShape healthboxshape, armorboxshape,ammo;
	int wth;
	bool available=1;
private:
	sf::Texture vest, firstaid,cartridge;

};

