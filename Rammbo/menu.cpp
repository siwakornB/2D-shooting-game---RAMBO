#include "menu.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "stage.h"
using namespace std;

menu::menu(sf::RenderWindow *window)
{
	this->window = window;
	font.loadFromFile("bangna-new.ttf");
	backgroundtextture.loadFromFile("pic/rambo.jpg");
	background.setTexture(backgroundtextture);
	dogtagtexture.loadFromFile("pic/dogtag.jpg");
	dogtag.setTexture(dogtagtexture);
	medal.loadFromFile("pic/medal2.jpg");
	backgroundmedal.setSize(sf::Vector2f(1920, 1080));
	backgroundmedal.setTexture(&medal);

}


menu::~menu()
{
}

void menu::main_menu()
{
	sf::Music song;
	song.openFromFile("Rambosong.wav");
	song.play();
	curchc=0;
	window->setKeyRepeatEnabled(false);
	sf::Text topic("Rammbo ",font,150),chc[3],name("SIWAKORN  BOONPAMEE [60010986]", font, 50);
	topic.setFillColor(sf::Color::Red);
	topic.setStyle(sf::Text::Bold);
	topic.setPosition(sf::Vector2f(750, 20));

	name.setFillColor(sf::Color::Red);
	name.setStyle(sf::Text::Bold);
	name.setPosition(sf::Vector2f(20, window->getSize().y -70));

	chc[0].setFont(font);
	chc[0].setFillColor(sf::Color::Red);
	chc[0].setCharacterSize(70);
	chc[0].setString("PLAY");
	chc[0].setPosition(sf::Vector2f(window->getSize().x / 2, 300));
	chc[0].setStyle(sf::Text::Bold);
	
	chc[1].setFont(font);
	chc[1].setFillColor(sf::Color::Red);
	chc[1].setCharacterSize(70);
	chc[1].setString("HIGH SCORE");
	chc[1].setPosition(sf::Vector2f(window->getSize().x / 2, 600));
	chc[1].setStyle(sf::Text::Bold);

	chc[2].setFont(font);
	chc[2].setFillColor(sf::Color::Red);
	chc[2].setCharacterSize(70);
	chc[2].setString("Exit");
	chc[2].setPosition(sf::Vector2f(window->getSize().x / 2, 900));
	chc[2].setStyle(sf::Text::Bold);

	sf::RectangleShape rect(sf::Vector2f(700, 80));
	rect.setFillColor(sf::Color::Black);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window->close(); break;				
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::Key::Return:
						switch (curchc)
						{
						case 0:	goto out;
						case 1: ladderboard(); break;
						case 2: window->close(); break;
						}
					case sf::Keyboard::Key::W:	if(curchc > 0)	curchc--;	break;
					case sf::Keyboard::Key::S:	if(curchc < 2)	curchc++;	break;
					}
			}
		}
		rect.setPosition(sf::Vector2f(window->getSize().x / 2, (300 * curchc) + 300));
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && curchc > 0) { curchc--;  }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && curchc <2) {  curchc++;  }
		rect.setPosition(sf::Vector2f(window->getSize().x / 2, (200 * curchc) + 200));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		{
			switch (curchc)
			{
			case 0:	goto out;
			case 2: window->close(); break;
			}
		}*/
		
		window->clear();
		window->draw(background);
		window->draw(rect);
		window->draw(topic);
		window->draw(chc[0]);
		window->draw(chc[1]);
		window->draw(chc[2]);
		window->draw(name);
		window->display();
	}
out: std::cout << "startgame" << std::endl;
}

void menu::pause_menu()
{
	curchc = 0;
	window->setKeyRepeatEnabled(false);
	sf::Text topic("Rammbo alpha", font, 150), chc[3], name("SIWAKORN  BOONPAMEE [60010986]", font, 50);
	topic.setFillColor(sf::Color::Red);
	topic.setStyle(sf::Text::Bold);
	topic.setPosition(sf::Vector2f(500, 20));

	name.setFillColor(sf::Color::Red);
	name.setStyle(sf::Text::Bold);
	name.setPosition(sf::Vector2f(20, window->getSize().y - 70));

	chc[0].setFont(font);
	chc[0].setFillColor(sf::Color::Red);
	chc[0].setCharacterSize(70);
	chc[0].setString("RESUME");
	chc[0].setPosition(sf::Vector2f(window->getSize().x / 2, 300));
	chc[0].setStyle(sf::Text::Bold);

	chc[1].setFont(font);
	chc[1].setFillColor(sf::Color::Red);
	chc[1].setCharacterSize(70);
	chc[1].setString("HIGH SCORE");
	chc[1].setPosition(sf::Vector2f(window->getSize().x / 2, 600));
	chc[1].setStyle(sf::Text::Bold);

	chc[2].setFont(font);
	chc[2].setFillColor(sf::Color::Red);
	chc[2].setCharacterSize(70);
	chc[2].setString("Exit");
	chc[2].setPosition(sf::Vector2f(window->getSize().x / 2, 900));
	chc[2].setStyle(sf::Text::Bold);

	sf::RectangleShape rect(sf::Vector2f(700, 80));
	rect.setFillColor(sf::Color::Black);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close(); break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Return:
					switch (curchc)
					{
					case 0:	goto out;
					case 1: ladderboard();
					case 2: window->close(); break;
					}
				case sf::Keyboard::Key::W:	if (curchc > 0)	curchc--;	break;
				case sf::Keyboard::Key::S:	if (curchc < 2)	curchc++;	break;
				}
			}
		}
		rect.setPosition(sf::Vector2f(window->getSize().x / 2, (300 * curchc) + 300));

		window->clear();
		window->draw(background);
		window->draw(rect);
		window->draw(topic);
		window->draw(chc[0]);
		window->draw(chc[1]);
		window->draw(chc[2]);
		window->draw(name);
		window->display();
	}
out: std::cout << "resume" << std::endl;
}

void menu::game_over(int a)
{
	std::string input;
	sf::Text over,stg,quote;
	int score;
	
	stg.setFont(font);
	stg.setFillColor(sf::Color::White);
	stg.setStyle(sf::Text::Bold);
	stg.setCharacterSize(80);
	stg.setPosition(sf::Vector2f(window->getSize().x / 2 - 500, window->getSize().y / 2+300));

	quote.setFont(font);
	quote.setFillColor(sf::Color::White);
	quote.setStyle(sf::Text::Bold);
	quote.setCharacterSize(80);
	quote.setPosition(sf::Vector2f(window->getSize().x / 6, window->getSize().y / 2 ));
	quote.setString("What's your name soldier?...");

	over.setFont(font);
	over.setFillColor(sf::Color::White);
	over.setStyle(sf::Text::Bold);
	over.setCharacterSize(150);
	over.setString("GAME  OVER");
	over.setPosition(sf::Vector2f(window->getSize().x / 2-500, window->getSize().y / 5));

	
	while (window->isOpen())
	{

		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close(); break;
			case sf::Event::TextEntered:
				{
					if (event.text.unicode >= 38 && event.text.unicode <= 122 && input.size() < 16)
					{
						input += static_cast<char>(event.text.unicode);
						stg.setString(input);
					}
					else if (event.text.unicode == 8 && input.size() >0)
					{
						input.erase(input.size() - 1, 1);
						stg.setString(input);
					}
					else if (event.text.unicode == '\r')
					{
						string playerNameHighScore[6];
						long HighScore[6];
						playerNameHighScore[5] = input;
						HighScore[5] = a;

						ifstream dataScore;
						dataScore.open("Player.txt");

						for (int i = 0; i < 5; i++) dataScore >> playerNameHighScore[i] >> HighScore[i];
						for (int i = 0; i < 5; i++) cout << playerNameHighScore[i] << " " << HighScore[i] << endl;

						dataScore.close();

						sf::Text gg1;
						gg1.setFont(font);

						for (int i = 0; i < 5; i++)
						for (int j = i + 1; j < 6; j++)
						{
						if (HighScore[i] < HighScore[j])
						{
							int temp = HighScore[i];
							HighScore[i] = HighScore[j];
							HighScore[j] = temp;
							string tempS = playerNameHighScore[i];
							playerNameHighScore[i] = playerNameHighScore[j];
							playerNameHighScore[j] = tempS;
						}
						}

						ofstream saveScore;
						saveScore.open("Player.txt");

						for (int i = 0; i < 5; i++) saveScore << playerNameHighScore[i] << " " << HighScore[i] << endl;

						saveScore.close();
						goto out;
					}
				}
			}
		}

		window->clear();
		window->draw(dogtag);
		window->draw(stg);
		window->draw(quote);	
		window->draw(over);
		window->display();
	}
out:std::cout << "d" << endl;
}

void menu::ladderboard()
{	
	//savescore
	string playerNameHighScore[6];
	long HighScore[6];

	ifstream dataScore;
	dataScore.open("Player.txt");

	for (int i = 0; i < 5; i++) dataScore >> playerNameHighScore[i] >> HighScore[i];
	for (int i = 0; i < 5; i++) cout << playerNameHighScore[i] << " " << HighScore[i] << endl;

	dataScore.close();

	sf::Text gg1;
	gg1.setFont(font);
	gg1.setCharacterSize(80);
	
	while (window->isOpen())
	{
		sf::Event event;
		while(window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close(); break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				goto out;
			}
		}
		window->clear();
		window->draw(backgroundmedal);
		for (int i = 0; i < 5; i++)
		{
			gg1.setPosition(550, i * 150 + 150);
			gg1.setString(playerNameHighScore[i]);
			window->draw(gg1);

			stringstream ss1;
			ss1 << HighScore[i];
			gg1.setPosition(1150, i * 150 + 150);
			gg1.setString(ss1.str());
			window->draw(gg1);
		}

		window->display();
	}
out: cout << "ww";
}
