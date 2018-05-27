#pragma once
#include"Gra.h"
#include "Gracz.h"
#include "Wrog.h"
#include "Poziom.h"
#include "Luna.h"
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <string.h>
#include <cstdio>
#include <string>
#include <iostream>


using namespace std;
using namespace sf;

class Silnik
{
public:
	Silnik(RenderWindow &okno);
	~Silnik(void);

	void startSilnik(RenderWindow &okno);
	void sprawdz_kolizje();
	int iloscOwocow, poziom;


	void WczytajPoziom(string nazwaPliku);

private:
	Gracz player;
	Wrog chmura;
	Luna luna;
	Poziom poz;
	Texture tekstura[Poziom::LICZ];
	Sprite sprite[Poziom::wys][Poziom::szer];
	Music muzyka;
	Font czcionka;
};