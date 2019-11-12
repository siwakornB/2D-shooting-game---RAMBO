#include "item.h"



item::item()
{
	vest.loadFromFile("pic/vest.png");
	firstaid.loadFromFile("pic/firstaid.png");
	cartridge.loadFromFile("pic/cartridge.png");
	healthboxshape.setTexture(&firstaid);
	armorboxshape.setTexture(&vest);
	ammo.setTexture(&cartridge);
	healthboxshape.setSize(sf::Vector2f(50, 50));
	armorboxshape.setSize(sf::Vector2f(50, 50));
	ammo.setSize(sf::Vector2f(50, 50));
}


item::~item()
{
}