#include "Jak.h"


Jak_gram::Jak_gram(RenderWindow &okno)
{
	//T�o sprawdzanie czy wszystko jest na swoim miejscu jak czegos brakuje pojawia sie odpowiedni blad
	if(!tlo.loadFromFile("dane/tla/tlo1.png")) //sprawdzenie czy t�o jest zaladowane z pliku jak nie to wyswietla b�ad
	{
		MessageBox(NULL, "Brak t�a.", "ERROR", NULL);
		return ;

	}

	startJak(okno);

}


Jak_gram::~Jak_gram(void)
{
}

void Jak_gram::startJak(RenderWindow &okno)
{
	bool menu = false;
	
	while (!menu)
	{
	
		Event zdarzenie;

		while (okno.pollEvent(zdarzenie))
		{

			if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)
			{	
				menu = true;

			}

		}		

		okno.clear();// og�lne t�o 
		sprajt.setTexture(tlo);
		okno.draw(sprajt);
		okno.display();

	}


}