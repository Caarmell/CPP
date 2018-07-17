#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h> 
#include <string>
#include "Gra.h"

using namespace std;

using namespace sf; //przestrzeñ nazw biblioteka sfml (Font, Text, Sprite) 

class Wybor
{
public:
	
	Wybor(RenderWindow &okno);
	~Wybor(void);
	void startWybor(RenderWindow &okno);
	static string path;


private:
	Texture tekstura, tekstura1, tekstura2, tekstura3, tekstura4;
	Sprite fluttershy, rainbowdash, rarity, twilight, pinkie; 
	size_t rama;
	Clock zegarek;
	Font czcionka;
	

};

