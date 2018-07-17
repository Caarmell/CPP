#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <Windows.h>
#include <math.h>
#include <iostream>


#define M_PI 3.14159265358979323846

using namespace sf;


class Gracz : public Drawable,
	Transformable
{
public:
	Gracz(void);
	~Gracz(void);
	int owoce;
	int zycie;
	int poz_x, poz_y;

	enum Status 
	{
		IDZ,
		TYL,
		PRAWO,
		LEWO,
		STOJ
	};
	float predkosc;

	Vector2f getPosition();
	Status getStatus();

	FloatRect getBoundingBox();
	Vector2f getSpeed();

	void odswiez();
	void tp();
	void stop();
	void idz();
	void idztyl();
	void idzPrawo();
	void idzLewo();
protected:
	int klatka_animacji;

private:
	Sprite sprite;
	Texture texture;

	Status status;


	size_t rama;

	Clock zegarek;

	virtual void draw(RenderTarget &cel, RenderStates stany) const;
};
