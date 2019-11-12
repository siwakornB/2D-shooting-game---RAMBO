#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include "character.h"
#include <vector>
#include "menu.h"
#include "bullet.h"
#include <sstream>
#include "enemy.h"
#include "item.h"



class stage
{
public:
	stage();
	~stage();
	void stage1(sf::RenderWindow& window);

};