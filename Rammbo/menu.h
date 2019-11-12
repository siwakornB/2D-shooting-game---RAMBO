#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "stage.h"

class menu
{
public:
	menu(sf::RenderWindow *window);
	~menu();
	void main_menu();
	void pause_menu();
	void game_over(int a);
	void ladderboard();
	
	
private:
	sf::RenderWindow *window;
	sf::Font font;
	sf::Sprite background,dogtag;
	sf::Texture backgroundtextture,dogtagtexture,medal;
	sf::RectangleShape backgroundmedal;
	unsigned int curchc;

};

