#pragma once
#include <SFML/Graphics.hpp>
class character
{
public:
	character();
	~character();
	sf::Sprite cha;
	
	int life = 100;
	int armour = 100;

	void die();
	bool alive = 1;
private:
	
	sf::Texture playertextture, bloodtextture;
};