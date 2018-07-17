#pragma once
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Poziom
{
public:

	//funkcje skladowe klasy
	Poziom();
	Poziom (string plik_mapy);

	void wczytajPlik(string plik_mapy);

	~Poziom(void);

	//"podklasy"  Co jest czym w tablicy z teksturami 
	enum Typy
	{
		NIC,
		TECZA,
		WODA,
		PIASEK,
		MUR,
		OGIEN,
		TRAWA,
		LAS,
		BANAN,
		JABLKO,
		LICZ

	};

	struct Pole
	{
		Typy typ;
		bool jestKolizja;
		bool jestOwoc;
		bool jestOgien;
		bool jestProfit;
		bool jestWolny;
	};

	//zmienne
	const static int szer = 25;
	const static int wys = 14;

	const static int pole_szer = 64;
	const static int pole_wys = 64;

	Pole poziom [wys][szer];
};


