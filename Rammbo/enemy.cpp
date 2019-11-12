#include "enemy.h"


enemy::enemy()
{
	enemy1textture.loadFromFile("pic/enemy1.png");
	bloodtextture.loadFromFile("pic/blood.png");
	blood.setTexture(bloodtextture);

	gunshot.loadFromFile("M16Shot.wav");
	gun.setBuffer(gunshot);

	enemy1.setScale(sf::Vector2f(0.5f, 0.5f));
	enemy1.setPosition(sf::Vector2f(50, 50));
	enemy1.setTexture(enemy1textture);
	enemy1.setOrigin(sf::Vector2f(enemy1.getTexture()->getSize().x / 2, enemy1.getTexture()->getSize().y / 2));


	srand(time(NULL));
}


enemy::~enemy()
{
}

void enemy::die()
{
	enemy1.setTexture(bloodtextture,true);
	enemy1.setScale(sf::Vector2f(0.25f, 0.25f));
	enemy1.setOrigin(sf::Vector2f(enemy1.getTexture()->getSize().x / 2, enemy1.getTexture()->getSize().y / 2));
	enemy1.setScale(sf::Vector2f(0.5f, 0.5f));
	alive = 0;

}

void enemy::face(sf::Sprite & target)
{
	float dx, dy, ang;
	dx = target.getPosition().x - enemy1.getPosition().x;
	dy = target.getPosition().y - enemy1.getPosition().y;
	ang = atan2(dy, dx)*(180 / PI);
	if (ang >= 0)
	{
		ang = abs(ang);
	}
	else
	{
		ang = 360 - abs(ang);
	}

	if (!(enemy1.getRotation() > ang - 2 && enemy1.getRotation() < ang + 2))  //rotate
	{

			if (enemy1.getRotation() < ang)
			{
				enemy1.setRotation(enemy1.getRotation() + 0.7);
			}
			else  enemy1.setRotation(enemy1.getRotation() - 0.7);
	}
	
	
	

	if ((enemy1.getRotation() > ang - 2 && enemy1.getRotation() < ang + 2) &&	//shoot condition
		((abs(enemy1.getPosition().x - target.getPosition().x) < 400) && (abs(enemy1.getPosition().y - target.getPosition().y) < 400)))
	{
		think.restart();
		shoot();
	}
	

	if (think.getElapsedTime().asSeconds() > 1)
	{
		enemy1.move(0.5*cos(ang), 0.5*sin(ang));
	}
	
}
	

void enemy::shoot()
{
	if (bul[z].visible == 0 && delay.getElapsedTime().asMilliseconds() > 300 && c > 0)	//firing loop
	{
		gun.play();
		bul[z].shot.setPosition(enemy1.getPosition());
		bul[z].ang = (PI / 180 * (enemy1.getRotation() + rand()%20 -10));
		bul[z].visible = 1;
		bul[z].duration.restart();
		z++;
		c--;
		delay.restart();
		if (c == 0)	reload.restart();
	}
	if (z >= 30) z = 0;
	if (c == 0 && reload.getElapsedTime().asMilliseconds() > 3000)
	{
		c = 30;
		reload.restart();
	}
}

void enemy::walkrally()
{
	if (wait.getElapsedTime().asSeconds() >= 8)
	{
		wtf = abs(enemy1.getRotation() + rand() % 60 - 30);
		wait.restart();
	}
	if (!(enemy1.getRotation() > wtf - 2 && enemy1.getRotation() < wtf + 2))  //rotate
	{
		think.restart();
		if (enemy1.getRotation() < wtf)
		{
			enemy1.setRotation(enemy1.getRotation() + 0.7);
		}
		else  enemy1.setRotation(enemy1.getRotation() - 0.7);
	}
	if ((enemy1.getRotation() > wtf - 2 && enemy1.getRotation() < wtf + 2) &&  think.getElapsedTime().asSeconds() <= 1.5)
	{
		enemy1.move(cos(enemy1.getRotation()), sin(enemy1.getRotation()));
		
	}

}

void enemy::spawn()
{
}



