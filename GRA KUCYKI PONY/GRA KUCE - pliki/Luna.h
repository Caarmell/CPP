#pragma once
#include <SFML\Graphics.hpp>
#include<vector>
#include <ctime>
#include <Windows.h>


using namespace sf;
using namespace std;


// dziedziczenie po klasach z SFML
class Luna : public Drawable,
	Transformable
{
public:
	Luna(void);
	~Luna(void);
	void odswiez();
	int kierunek;
	enum Status
	{
		IDZ,
		STOJ
	};

	float predkosc;
	Vector2f getPosition();
	FloatRect getBoundingBoxLuna();
	Status getStatus();


	struct pozycja{
		bool jestLuna;
	};

	const static int szer = 25;
	const static int wys = 14;
	pozycja miejsce[szer][wys];

private:
	Sprite sprite;
	Texture tekstura;

	Status status;

	size_t ramka;

	Clock zegar;

	virtual void draw(RenderTarget &cel, RenderStates stan) const;
};

