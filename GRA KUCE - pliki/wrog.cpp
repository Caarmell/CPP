#include "wrog.h"


Wrog::Wrog(void)
{
	if (!tekstura.loadFromFile("dane/grafika/chmurka.png"))
	{
		MessageBox(NULL, "Nie odnaleziono textury Wrog!", "ERROR", NULL);
		return;
	}
	sprite.setTexture(tekstura);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));
	sprite1.setTexture(tekstura);
	sprite1.setTextureRect(IntRect(0, 0, 64, 64));
	sprite2.setTexture(tekstura);
	sprite2.setTextureRect(IntRect(0, 0, 64, 64));
	sprite3.setTexture(tekstura);
	sprite3.setTextureRect(IntRect(0, 0, 64, 64));
	kierunek = 1;
	kierunek1 = 1;
	kierunek2 = 1;
	kierunek3 = 1;
	sprite.setOrigin(32, 32);
	sprite1.setOrigin(32, 32);
	sprite2.setOrigin(32, 32);
	sprite3.setOrigin(32, 32);

	status = IDZ;

	ramka = 0;
	predkosc = 15;

	sprite.setPosition(100, 100);
	sprite1.setPosition(800, 250);
	sprite2.setPosition(1000, 640);
	sprite3.setPosition(400, 720);
	zegar.restart();
}


Wrog::~Wrog(void)
{
}

void Wrog::odswiez()
{
	if (zegar.getElapsedTime() > seconds(0.09f))
	{
		if (status == STOJ) return;
		if (ramka < 5 /*liczba klatek animacji*/)
			ramka++;
		else
			ramka = 0; //zapetlanie animacji

		sprite.setTextureRect(IntRect(ramka * 64, 0, 64, 64));
		sprite1.setTextureRect(IntRect(ramka * 64, 0, 64, 64));
		sprite2.setTextureRect(IntRect(ramka * 64, 0, 64, 64));
		sprite3.setTextureRect(IntRect(ramka * 64, 0, 64, 64));
		//x, y, szerokosc, wysokosc

		srand(time(NULL));  // funkcja pseudolosowa
		kierunek = (rand() % 8) + 1; //zeby nie chodzily w kolko, tylko mogl isc w jednym kierunku dluzej
		kierunek1 = (rand() % 8) + 1;
		kierunek2 = (rand() % 8) + 1;
		if (sprite.getPosition().x>1600)
			sprite.setPosition(0, sprite.getPosition().y);
		if (sprite.getPosition().x<0)
			sprite.setPosition(1600, sprite.getPosition().y);
		if (sprite.getPosition().y>896)
			sprite.setPosition(sprite.getPosition().x, 0);
		if (sprite.getPosition().y<0)
			sprite.setPosition(sprite.getPosition().x, 896);

		if (sprite1.getPosition().x>1600)
			sprite1.setPosition(0, sprite1.getPosition().y);
		if (sprite1.getPosition().x<0)
			sprite1.setPosition(1600, sprite1.getPosition().y);
		if (sprite1.getPosition().y>896)
			sprite1.setPosition(sprite1.getPosition().x, 0);
		if (sprite1.getPosition().y<0)
			sprite1.setPosition(sprite1.getPosition().x, 896);

		if (sprite2.getPosition().x>1600)
			sprite2.setPosition(0, sprite2.getPosition().y);
		if (sprite2.getPosition().x<0)
			sprite2.setPosition(1600, sprite2.getPosition().y);
		if (sprite2.getPosition().y>896)
			sprite2.setPosition(sprite2.getPosition().x, 0);
		if (sprite2.getPosition().y<0)
			sprite2.setPosition(sprite2.getPosition().x, 896);

		if (sprite3.getPosition().x>1600)
			sprite3.setPosition(0, sprite3.getPosition().y);
		if (sprite3.getPosition().x<0)
			sprite3.setPosition(1600, sprite3.getPosition().y);
		if (sprite3.getPosition().y>896)
			sprite3.setPosition(sprite3.getPosition().x, 0);
		if (sprite3.getPosition().y<0)
			sprite3.setPosition(sprite3.getPosition().x, 896);

		if (kierunek == 1)
		{
			sprite.move(0, -10);
			sprite.setRotation(0);
		}

		else if (kierunek == 2)
		{
			sprite.move(10, 0);
			sprite.setRotation(90);
		}

		else if (kierunek == 3)
		{
			sprite.move(0, 10);
			sprite.setRotation(180);
		}

		else if (kierunek >= 4)
		{
			sprite.move(-10, 0);
			sprite.setRotation(270);
		}

		if (kierunek1 == 1)
		{
			sprite1.move(-10, 0);
			sprite1.setRotation(270);
		}

		else if (kierunek1 == 2)
		{
			sprite1.move(10, 0);
			sprite1.setRotation(90);
		}

		else if (kierunek1 == 3)
		{
			sprite1.move(0, 10);
			sprite1.setRotation(180);
		}

		else if (kierunek1 >= 4)
		{
			sprite1.move(0, -10);
			sprite1.setRotation(0);
		}

		if (kierunek2 == 1)
		{
			sprite2.move(0, -10);
			sprite2.setRotation(0);
		}

		else if (kierunek2 == 2)
		{
			sprite2.move(10, 0);
			sprite2.setRotation(90);
		}

		else if (kierunek2 == 3)
		{
			sprite2.move(-10, 0);
			sprite2.setRotation(270);
		}

		else if (kierunek2 >= 4)
		{
			sprite2.move(0, 10);
			sprite2.setRotation(180);
		}

		if (kierunek == 1)
		{
			sprite3.move(0, -10);
			sprite3.setRotation(0);
		}

		else if (kierunek == 2)
		{
			sprite3.move(10, 0);
			sprite3.setRotation(90);
		}

		else if (kierunek == 3)
		{
			sprite3.move(0, 10);
			sprite3.setRotation(180);
		}

		else if (kierunek >= 4)
		{
			sprite3.move(-10, 0);
			sprite3.setRotation(270);
		}



		zegar.restart();
	}
}

void Wrog::draw(RenderTarget &cel, RenderStates stan) const
{
	stan.transform *= getTransform();

	cel.draw(sprite);
	cel.draw(sprite1);
	cel.draw(sprite2);
	cel.draw(sprite3);
}

Vector2f Wrog::getPosition()
{
	return sprite.getPosition();
}

Wrog::Status Wrog::getStatus()
{
	return status;
}

FloatRect Wrog::getBoundingBox()
{
	return sprite.getGlobalBounds();
}

FloatRect Wrog::getBoundingBox1()
{
	return sprite1.getGlobalBounds();
}

FloatRect Wrog::getBoundingBox2()
{
	return sprite2.getGlobalBounds();
}

FloatRect Wrog::getBoundingBox3()
{
	return sprite3.getGlobalBounds();
}
