#include "character.h"
#include <iostream>


using namespace std;

character::character()
{
	cout << "Status";
	playertextture.loadFromFile("pic/player.png");
	bloodtextture.loadFromFile("pic/blood.png");

	cha.setScale(sf::Vector2f(0.5f, 0.5f));
	cha.setPosition(sf::Vector2f(50, 50));
	cha.setTexture(playertextture);
	cha.setOrigin(sf::Vector2f(cha.getTexture()->getSize().x / 2, cha.getTexture()->getSize().y / 2));
}


character::~character()
{
	cout << "end";
}

void character::die()
{
	cha.setTexture(bloodtextture, true);
	cha.setScale(sf::Vector2f(0.25f, 0.25f));
	cha.setOrigin(sf::Vector2f(cha.getTexture()->getSize().x / 2,cha.getTexture()->getSize().y / 2));
	cha.setScale(sf::Vector2f(0.5f, 0.5f));
	alive = 0;
}