#include "Gracz.h"
#include "Wybor.h"


Gracz::Gracz(void)
{
	poz_x = 0; 
	poz_y = 0;

	if (!texture.loadFromFile(Wybor::path))
	{
		MessageBox(NULL, "Nie odnaleziono textury Gracz!", "ERROR", NULL);
		return;
	}

	if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		zycie = 100;
		predkosc = 10;
	}

	if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		zycie = 100;
		predkosc = 10;
	}

	if (Wybor::path =="dane/grafika/rarity.png")
	{
		zycie = 200;
		predkosc = 6;
	}

	if (Wybor::path =="dane/grafika/rainbowdash.png")
	{
		zycie = 50;
		predkosc = 25;
	}

	if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		zycie = 100;
		predkosc = 10;
	}

	owoce = 0;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));

	sprite.setOrigin(32, 32); // do obracania wokol wlasnej osi. ustawiamy punkt do obrotu na srodku kafalka

	status = STOJ;

	rama = 0;


	sprite.setPosition(500, 300);
	zegarek.restart();
}


Gracz::~Gracz(void)
{
}


void Gracz::draw(RenderTarget &cel, RenderStates stany) const
{
	stany.transform *= getTransform();

	cel.draw(sprite);
}


void Gracz::odswiez()
{
		if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		predkosc = 10;
	}

	if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		predkosc = 10;
	}

	if (Wybor::path =="dane/grafika/rarity.png")
	{
		predkosc = 6;
	}

	if (Wybor::path =="dane/grafika/rainbowdash.png")
	{
		predkosc = 25;
	}

	if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		predkosc = 10;
	}


	if (zegarek.getElapsedTime() > seconds(0.09f))
	{
		if (status == STOJ) return;
		if (rama < 10 /*liczba klatek animacji*/)
			rama++;
		else
			rama = 0; //zapetlanie animacji

		sprite.setTextureRect(IntRect(rama * 64, 0, 64, 64));
		//x, y, szerokosc, wysokosc
		sprite.move(getSpeed());

		zegarek.restart();
	}
}


void Gracz::stop()
{
	status = STOJ;
	rama = 0;
}

void Gracz::tp()
{
	sprite.setPosition(500, 260);
}


void Gracz::idz()
{
	status = IDZ;
	poz_x = sprite.getPosition().x; // pozycja x kucyka
	poz_y = sprite.getPosition().y; // pozycja y kucyka
}

void Gracz::idztyl()
{
	status = TYL;
	poz_x = sprite.getPosition().x; // pozycja x kucyka
	poz_y = sprite.getPosition().y; // pozycja y kucyka
}

void Gracz::idzPrawo()
{
	status = PRAWO;
	poz_x = sprite.getPosition().x; // pozycja x kucyka
	poz_y = sprite.getPosition().y; // pozycja y kucyka
}

void Gracz::idzLewo()
{
	status = LEWO;
	poz_x = sprite.getPosition().x; // pozycja x kucyka
	poz_y = sprite.getPosition().y; // pozycja y kucyka
}


Vector2f Gracz::getPosition()
{
	return sprite.getPosition();
}

Gracz::Status Gracz::getStatus()
{
	return status;
}

FloatRect Gracz::getBoundingBox()
{
	return sprite.getGlobalBounds();
}

Vector2f Gracz::getSpeed()
{
	if (status == IDZ)
	{
		float rotacja = 0;
		float vx = sin((rotacja*M_PI) / 180.0f);
		float vy = -cos((rotacja*M_PI) / 180.0f);
		sprite.setRotation(360);
		return Vector2f(vx*predkosc, vy*predkosc);
	}
	if (status == LEWO)
	{
		float rotacja = 90;
		float vx = sin((rotacja * M_PI) / 180.0f);
		float vy = -cos((rotacja * M_PI) / 180.0f);
		sprite.setRotation(360);
		sprite.setScale(1.f, 1.f);
		return Vector2f(-predkosc*vx, predkosc*vy);
	}
	if (status == PRAWO)
	{
		float rotacja = 90;
		float vx = sin((rotacja * M_PI) / 180.0f);
		float vy = -cos((rotacja * M_PI) / 180.0f);
		sprite.setRotation(360);
		sprite.setScale(-1.f, 1.f);
		return Vector2f(predkosc*vx, -predkosc*vy);
	}
	if (status == TYL)
	{
		float rotacja = 0;
		float vx = sin((rotacja * M_PI) / 180.0f);
		float vy = -cos((rotacja * M_PI) / 180.0f);
		sprite.setRotation(360);
		return Vector2f(-predkosc*vx, -predkosc*vy);
	}

}




