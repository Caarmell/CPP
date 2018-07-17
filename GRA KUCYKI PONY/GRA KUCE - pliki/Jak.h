#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h> 
#include <string>



using namespace sf; //przestrzeñ nazw biblioteka sfml (Font, Text)

class Jak_gram
{
public:
	Jak_gram(RenderWindow &okno);
	~Jak_gram(void);
private:
	Texture tlo;
	Sprite sprajt;

public:
	void startJak(RenderWindow &okno);
};

