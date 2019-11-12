#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include <SFML/Audio.hpp>
#include "item.h"

class enemy
{
public:
	enemy();
	~enemy();
	sf::Sprite enemy1,blood;
	bullet bul[30];
	sf::Clock see;
	sf::SoundBuffer gunshot; sf::Sound gun;

	int life = 100;
	bool alive = 1;
	bool seen = 0;
	
	void die();
	void face(sf::Sprite& target);
	void shoot();
	void walkrally();
	void spawn();
private:
	
	sf::Texture enemy1textture,bloodtextture;
	sf::Clock delay,reload,think,wait;
	int z = 0, c = 30;
	const float PI = 3.1415926536;
	float wtf;

};

