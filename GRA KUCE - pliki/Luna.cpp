#include "Luna.h"


Luna::Luna(void)
{
	if (!tekstura.loadFromFile("dane/grafika/luna.png"))
	{
		MessageBox(NULL, "Nie odnaleziono textury Luna!", "ERROR", NULL);
		return;
	}
	sprite.setTexture(tekstura);
	sprite.setTextureRect(IntRect(0, 0, 120, 120));
	kierunek = 1;
	sprite.setOrigin(60, 60);

	status = IDZ;

	ramka = 0;
	predkosc = 60;

	sprite.setPosition(100, 100);
	zegar.restart();
}


Luna::~Luna(void)
{
}

void Luna::odswiez()
{
	if (zegar.getElapsedTime() > seconds(0.09f))
	{
		if (status == STOJ) return;
		if (ramka < 10 /*liczba klatek animacji*/)
			ramka++;
		else
			ramka = 0; //zapetlanie animacji

		sprite.setTextureRect(IntRect(ramka * 120, 0, 120, 120));

		//x, y, szerokosc, wysokosc

		srand(time(NULL));  // funkcja pseudolosowa
		kierunek = (rand() % 16) + 1; //zeby nie chodzily w kolko, tylko mogl isc w jednym kierunku dluzej

		if (sprite.getPosition().x>1600)
			sprite.setPosition(0, sprite.getPosition().y);
		if (sprite.getPosition().x<0)
			sprite.setPosition(1600, sprite.getPosition().y);
		if (sprite.getPosition().y>896)
			sprite.setPosition(sprite.getPosition().x, 0);
		if (sprite.getPosition().y<0)
			sprite.setPosition(sprite.getPosition().x, 896);

		

		if (kierunek == 1) //góra
		{
			sprite.move(0, -10);
			sprite.setRotation(0);
			sprite.setScale(1.f, 1.f);
		}

		else if (kierunek >= 2 && kierunek <= 8)//prawo
		{
			sprite.move(10, 0);
			sprite.setRotation(360);
			sprite.setScale(-1.f, 1.f);

		}

		else if (kierunek >= 10) // ty³
		{
			sprite.move(0, 10);
			sprite.setRotation(360);
			sprite.setScale(1.f, 1.f);
		}

		else if (kierunek == 9) // lewo
		{
			sprite.move(-10, 0);
			sprite.setRotation(360);
			sprite.setScale(1.f, 1.f);
		}

		zegar.restart();
	}
}

void Luna::draw(RenderTarget &cel, RenderStates stan) const
{
	stan.transform *= getTransform();

	cel.draw(sprite);
	
}

Vector2f Luna::getPosition()
{
	return sprite.getPosition();
}

Luna::Status Luna::getStatus()
{
	return status;
}

FloatRect Luna::getBoundingBoxLuna()
{
	return sprite.getGlobalBounds();
}

