#include "stage.h"


stage::stage()
{
}

stage::~stage()
{
}

void stage::stage1(sf::RenderWindow& window)
{
renew :	sf::Event event;

	sf::Texture backgroundtextture;
	backgroundtextture.loadFromFile("pic/map1.png");
	sf::Sprite background;
	background.setTexture(backgroundtextture);

	sf::Texture UItextture;
	UItextture.loadFromFile("pic/UI.png");
	sf::RectangleShape UI(sf::Vector2f(1920, 200));
	UI.setTexture(&UItextture);
	UI.setPosition(0, window.getSize().y - 200);

	sf::RectangleShape aim(sf::Vector2f(50, 50));	sf::Texture crosshair; crosshair.loadFromFile("pic/Crosshair.png");
	aim.setTexture(&crosshair);
	aim.setOrigin(5, 5);

	sf::Font font;
	font.loadFromFile("bangna-new.ttf");
	sf::Text health, armor, ammo, maxammo,score,iscore,rere,tub;

	health.setPosition(500, window.getSize().y - 170);
	health.setFont(font);
	health.setCharacterSize(40);

	armor.setFillColor(sf::Color::Black);
	armor.setPosition(500, window.getSize().y - 80);
	armor.setFont(font);
	armor.setCharacterSize(40);

	ammo.setPosition(1000, window.getSize().y - 75);
	ammo.setFont(font);
	ammo.setFillColor(sf::Color::Black);
	ammo.setCharacterSize(40);

	tub.setPosition(1050, window.getSize().y - 75);
	tub.setFont(font);
	tub.setFillColor(sf::Color::Black);
	tub.setCharacterSize(40);
	tub.setString("/ ");

	maxammo.setPosition(1070, window.getSize().y - 75);
	maxammo.setFont(font);
	maxammo.setFillColor(sf::Color::Black);
	maxammo.setCharacterSize(40);
	
	score.setPosition(1670, window.getSize().y - 75);
	score.setFont(font);
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(40);

	iscore.setPosition(1500, window.getSize().y - 75);
	iscore.setFont(font);
	iscore.setCharacterSize(40);
	iscore.setFillColor(sf::Color::Black);
	iscore.setString("SCORE");

	rere.setFont(font);
	rere.setFillColor(sf::Color::Black);
	rere.setCharacterSize(40);

	sf::RectangleShape healthbar, armorbar, ihealthbar(sf::Vector2f(400, 50)), iarmorbar(sf::Vector2f(400, 50));
	healthbar.setFillColor(sf::Color::Red);
	healthbar.setPosition(200, window.getSize().y - 170);
	ihealthbar.setFillColor(sf::Color::White);
	ihealthbar.setPosition(200, window.getSize().y - 170);
	armorbar.setFillColor(sf::Color::Blue);
	armorbar.setPosition(200, window.getSize().y - 80);
	iarmorbar.setFillColor(sf::Color::White);
	iarmorbar.setPosition(200, window.getSize().y - 80);
	health.setFillColor(sf::Color::Black);
	
	sf::SoundBuffer gunshot; sf::Sound gun;
	gunshot.loadFromFile("M16Shot.wav");
	gun.setBuffer(gunshot);
	//std::vector<bullet*> bulvector;
	//bulvector.push_back(new bullet);
	bullet bul[100];

	sf::Clock clock, delayshot,reloadtime;
	sf::Time time;
	float reloadtimer=0;
	character player;
	player.cha.setPosition(700,500);

	std::vector<enemy*> emy;

	std::vector<item*> drop;
	drop.push_back(new item);
	drop[0]->healthboxshape.setPosition(750, 500);
	drop.push_back(new item);
	drop[1]->armorboxshape.setPosition(750, 550);
	

	const float PI = 3.1415926536;
	int i, z = 0, magazine = 30,allammo=120,scoreint=0;
	int whichitem;
	float h, j;
	int reload=-1;

	menu menu(&window);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));
	
	menu.main_menu();
	bool gotcha = 0;
	while (window.isOpen())
	{

		std::stringstream ss1, ss2, ss3, ss4,ss5,ss6; //ตัวอักษรแสดงสถานะเลือดและเกราะ	status text
		ss1 << player.life;
		health.setString(ss1.str());
		ss2 << player.armour;
		armor.setString(ss2.str());
		ss3 << magazine;
		ammo.setString(ss3.str());
		ss4 << scoreint;
		score.setString(ss4.str());
		ss5 << allammo;
		maxammo.setString(ss5.str());
		ss6 << reload;
		rere.setString(ss6.str());
		rere.setPosition(aim.getPosition().x+10,aim.getPosition().y+50);

		h = (float)player.life / 100 * 400; //แถบสถานะเลือดและเกราะ  status bar
		healthbar.setSize(sf::Vector2f(h, 50.f));
		j = (float)player.armour / 100 * 400;
		armorbar.setSize(sf::Vector2f(j, 50.f));

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Escape: { menu.pause_menu(); }
				}

			}
			/*if (event.type == sf::Event::KeyPressed)
			{
			if (event.key.code == sf::Keyboard::Escape)
			{
			std::cout << "the escape key was pressed" << std::endl;
			std::cout << "control:" << event.key.control << std::endl;
			std::cout << "alt:" << event.key.alt << std::endl;
			std::cout << "shift:" << event.key.shift << std::endl;
			std::cout << "system:" << event.key.system << std::endl;
			}
			}*/
		}
		float temp = reloadtime.getElapsedTime().asSeconds();
		reloadtime.restart();
		reloadtimer += temp;

		if (reloadtimer >= 1 && reload > 0) { reload--; reloadtimer = 0; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))			player.cha.move(0.0f, -1.2f);  //การเคลื่อนที่ movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))			player.cha.move(-1.2f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))			player.cha.move(0.0f, 1.2f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))			player.cha.move(1.2f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && magazine < 30 && gotcha == 0 )
		{
			reload = 3;	gotcha = 1;
		}
		if (reload ==0)
		{
			if (allammo >= 30) { allammo -= 30 - magazine;	magazine = 30; }
			else if (allammo < 30 && allammo != 0)
			{
				if (magazine + allammo >= 30)
				{
					allammo = magazine + allammo - 30;	magazine = 30;
				}
				else
				{
					magazine += allammo; allammo = 0;
				}
			}
			reload = -1;
			gotcha = 0;
		}
		if(player.cha.getPosition().x <= 20)	player.cha.move(2, 0.0);
		if(player.cha.getPosition().y <= 20)	player.cha.move(0, 2);
		if(player.cha.getPosition().y >= 1050)	player.cha.move(0, -2);
		if(player.cha.getPosition().x >= 1880)	player.cha.move(-2, 0);
		//view.setCenter(player.cha.getPosition());
		
		if (sf::Event::MouseMoved)	//การเคลื่อนที่ของเมาส์ mouse movement
		{
			float dx, dy, angplayer;
			aim.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

			dx = aim.getPosition().x - player.cha.getPosition().x;
			dy = aim.getPosition().y - player.cha.getPosition().y;
			angplayer = atan2(dy, dx)*(180 / PI);
			player.cha.setRotation(angplayer);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !gotcha)		//เมื่อกดปุ่มยิง			//(PI/180*player.cha.getRotation());
		{
			//p = new bullet(player.cha.getRotation());
			//bul.push_back(new bullet(player.cha.getRotation()));
			if (bul[z].visible == 0 && delayshot.getElapsedTime().asMilliseconds() > 150 && magazine > 0)	//firing loop
			{
				bul[z].shot.setPosition(player.cha.getPosition());
				bul[z].ang = (PI / 180 * (player.cha.getRotation() + rand() % 10 - 6));
				bul[z].visible = 1;
				bul[z].duration.restart();
				z++;
				magazine--;
				delayshot.restart();
				gun.play();

			}
			if (z > 99) z = 0;
		}
		for (i = 0; i<100; i++)			//shotmove loop
		{
			if (bul[i].visible == 1)
			{
				bul[i].bullet_move();
				if (bul[i].duration.getElapsedTime().asSeconds() >= 10)
				{
					bul[i].visible = 0;
				}
				for(int b=0;b < emy.size();b++)
				if (bul[i].shot.getGlobalBounds().intersects(emy[b]->enemy1.getGlobalBounds()) == 1 && emy[b]->alive == 1)
				{
					emy[b]->life -= 5;
					//std::cout << emy1.life << std::endl;
					bul[i].visible = 0;
					emy[b]->seen = 1;
					emy[b]->see.restart();
					if (emy[b]->life <= 0 )
					{
						emy[b]->die();
						scoreint += 15;
						whichitem = rand() % 10;
						switch (whichitem)
						{
						case 0:drop.push_back(new item);
							drop[drop.size() - 1]->healthboxshape.setPosition(emy[b]->enemy1.getPosition()); 
							drop[drop.size() - 1]->wth = whichitem;break;
						case 1:drop.push_back(new item);
							drop[drop.size() - 1]->armorboxshape.setPosition(emy[b]->enemy1.getPosition());	
							drop[drop.size() - 1]->wth = whichitem;break;
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
							drop.push_back(new item);
							drop[drop.size() - 1]->ammo.setPosition(emy[b]->enemy1.getPosition());	
							drop[drop.size() - 1]->wth = whichitem;
							break;
						}
					}
				}
			}
		}
		for (i = 0; i < emy.size() ; i++)			//enemys' shotmove loop
		{
			for (int b = 0; b < 30; b++)
			if (emy[i]->bul[b].visible == 1)
			{
				emy[i]->bul[b].bullet_move();

				if (emy[i]->bul[b].duration.getElapsedTime().asSeconds() >= 5)
				{
					emy[i]->bul[b].visible = 0;
				}
				if (emy[i]->bul[b].shot.getGlobalBounds().intersects(player.cha.getGlobalBounds()) == 1 && player.alive == 1)
				{
					if (player.armour > 0)
					{
						player.life -= emy[i]->bul[b].damage / 4;
						player.armour -= emy[i]->bul[b].damage * 4 / 7;
						if (player.armour <= 0)	player.armour = 0;
					}
					else player.life -= emy[i]->bul[b].damage;
					emy[i]->bul[b].visible = 0;
					if (player.life <= 0)
					{
						player.die();
						menu.game_over(scoreint);
						menu.ladderboard();
						goto renew;
					}
				}
			}
		}
		for (i = 0; i < drop.size(); i++)
		{
			if (drop[i]->wth == 0)
			{
				if (player.cha.getGlobalBounds().intersects(drop[i]->healthboxshape.getGlobalBounds()) && drop[i]->available == 1)	//special tiem
				{
					drop[i]->available = 0;
					player.life += 30;
					if (player.life > 100)
					{
						player.life = 100;
					}
				}
			}
			else if (drop[i]->wth == 1)
			{
				if (player.cha.getGlobalBounds().intersects(drop[i]->armorboxshape.getGlobalBounds()) && drop[i]->available == 1)	//special tiem
				{
					drop[i]->available = 0;
					player.armour = 100;
				}
			}
			else
			{
				if (player.cha.getGlobalBounds().intersects(drop[i]->ammo.getGlobalBounds()) && drop[i]->available == 1)	//special tiem
				{
					drop[i]->available = 0;
					allammo += rand() % 30 +20;
				}
			}
		}

		//time = clock.getElapsedTime();						//charactor status test
		//std::cout << time.asSeconds() << std::endl;
		if (clock.getElapsedTime().asSeconds() >= 3)
		{
			clock.restart();
			emy.push_back(new enemy);
			switch (rand() % 3)
			{
			case 0:	emy[emy.size() - 1]->enemy1.setPosition(rand() % 1900, 40); emy[emy.size() - 1]->seen = 1; break;
			case 1:	emy[emy.size() - 1]->enemy1.setPosition(40, rand() % 1000); emy[emy.size() - 1]->seen = 1; break;
			case 2:	emy[emy.size() - 1]->enemy1.setPosition(1900, rand() % 1000); emy[emy.size() - 1]->seen = 1; break;
			}
			whichitem = rand() % 8;
			switch (whichitem)
			{
			case 0:drop.push_back(new item);
				drop[drop.size() - 1]->healthboxshape.setPosition(rand() % 1900, 40);
				drop[drop.size() - 1]->wth = whichitem; break;
			case 1:drop.push_back(new item);
				drop[drop.size() - 1]->armorboxshape.setPosition(40, rand() % 1000);
				drop[drop.size() - 1]->wth = whichitem; break;
			case 2:
				drop.push_back(new item);
				drop[drop.size() - 1]->ammo.setPosition(1900, rand() % 1000);
				drop[drop.size() - 1]->wth = whichitem;
				break;
			}
		}
		//ai testing
		for (i = 0; i < emy.size(); i++)
		{
			if ((abs(emy[i]->enemy1.getPosition().x - player.cha.getPosition().x) <= 400 && abs(emy[i]->enemy1.getPosition().y - player.cha.getPosition().y) <= 400) && emy[i]->alive == 1)
			{
				emy[i]->see.restart();
				emy[i]->seen = 1;
				clock.restart();
			}
			if (emy[i]->see.getElapsedTime().asSeconds() > 9)
			{
				emy[i]->seen = 0;
			}

			if (emy[i]->seen == 1 && emy[i]->alive == 1)  emy[i]->face(player.cha);
			else if (clock.getElapsedTime().asSeconds() >= 5 && emy[i]->alive == 1) {
				emy[i]->walkrally();
			}
		}

		//window.setView(view);
		window.clear();
		window.draw(background);
		for (i = 0; i < emy.size(); i++)	window.draw(emy[i]->enemy1);

		for (i = 0; i < drop.size(); i++)
		{
			if (drop[i]->wth == 0 && drop[i]->available)
				window.draw(drop[i]->healthboxshape);
			else if(drop[i]->wth == 1 && drop[i]->available)
				window.draw(drop[i]->armorboxshape);
			else  if (drop[i]->available)
				window.draw(drop[i]->ammo);
		}

		for (i = 0; i < 100; i++)		//bullet draw loop
		{
			if (bul[i].visible == 1) window.draw(bul[i].shot);
		}
		window.draw(player.cha);
		for (int b = 0; b < emy.size(); b++)		//bullet draw loop
		{
			for (i = 0; i < 30; i++)
			{
				if (emy[b]->bul[i].visible == 1)  window.draw(emy[b]->bul[i].shot);
			}
			
		}
		window.draw(aim);
		if(reload > 0)	window.draw(rere);
		window.draw(UI);
		window.draw(ihealthbar);
		window.draw(iarmorbar);
		window.draw(healthbar);
		window.draw(armorbar);
		window.draw(health);
		window.draw(armor);
		window.draw(ammo);
		window.draw(tub);
		window.draw(maxammo);
		window.draw(iscore);
		window.draw(score);
		window.display();
	}
}
