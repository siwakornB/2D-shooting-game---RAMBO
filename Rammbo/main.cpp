#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "menu.h"
#include <sstream>
#include "stage.h"
#include <fstream>

using namespace std;

int main()
{
	int score = 0;
	sf::RenderWindow window(sf::VideoMode(1024,720), "SFML KABOOOOM",sf::Style::Fullscreen); 
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(600);

	stage chapter;
	menu menu(&window);

	chapter.stage1(window);

	

	return 0;
}