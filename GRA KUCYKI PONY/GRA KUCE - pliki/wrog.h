#pragma once
#include <SFML\Graphics.hpp>
#include<vector>
#include <ctime>
#include <Windows.h>

using namespace sf;
using namespace std;


// dziedziczenie po klasach z SFML
class Wrog : public Drawable,
	Transformable
{
public:
	Wrog(void);
	~Wrog(void);
	void odswiez();
	int kierunek, kierunek1, kierunek2, kierunek3;
	enum Status
	{
		IDZ,
		STOJ
	};

	float predkosc;
	Vector2f getPosition();
	FloatRect getBoundingBox();
	FloatRect getBoundingBox1();
	FloatRect getBoundingBox2();
	FloatRect getBoundingBox3();
	Status getStatus();


	struct pozycja{
		bool jestWrog;
	};

	const static int szer = 25;
	const static int wys = 14;
	pozycja miejsce[szer][wys];

private:
	Sprite sprite, sprite1, sprite2, sprite3;
	Texture tekstura;

	Status status;

	size_t ramka;

	Clock zegar;

	virtual void draw(RenderTarget &cel, RenderStates stan) const;
};

