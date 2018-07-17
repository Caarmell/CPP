#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h> 
#include <string>
#include "Silnik.h"
#include "Jak.h"
#include "Wybor.h"

using namespace sf; //przestrzeñ nazw biblioteka sfml (Font, Text) 

class Gra
{
public:
	Gra(void);
	~Gra(void);
	void Start(void);
	friend class Wybor;

protected:
	enum StanGry {MENU, JAK, GRA, KUCYKI, KONIEC}; //typ zmiennej wyliczeniowy
	StanGry stan;

private:
	Font czcionka;
	Texture tlo; 
	Sprite sprajt;

	void Menu();
	void Jak();
	void Single();
	void Kucyki();

	
	
};
