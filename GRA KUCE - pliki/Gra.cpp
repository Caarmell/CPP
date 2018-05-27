#include "Gra.h"
#include "Wybor.h"

RenderWindow okno(VideoMode(1600,896),"Kuce");

Gra::Gra(void)
{
	ContextSettings ustawienia;
	ustawienia.antialiasingLevel = 10; // nie kwadratowy obraz
	stan = KONIEC;
	okno.setFramerateLimit(100); // maksymalna czestotliwoœæ odœwie¿enia ekranu

	//czcionka sprawdzanie czy wszystko jest na swoim miejscu jak czegos brakuje pojawia sie odpowiedni blad
	if(!czcionka.loadFromFile("dane/4MYLOVER.TTF"))
	{
		MessageBox(NULL, "Brak czcionki.", "ERROR", NULL);
		return ;
	}

	//T³o sprawdzanie czy wszystko jest na swoim miejscu jak czegos brakuje pojawia sie odpowiedni blad
	if(!tlo.loadFromFile("dane/tla/nowy.png")) //sprawdzenie czy t³o jest zaladowane z pliku jak nie to wyswietla b³ad
	{
		MessageBox(NULL, "Brak t³a.", "ERROR", NULL);
		return ;
	}


	


	stan = MENU;
}


Gra::~Gra(void)
{
}


void Gra::Start(void)
{
	while(stan != KONIEC)
	{
		switch(stan)
		{
		case StanGry::MENU:
			Menu();
			break;
		case StanGry::GRA:
			Single();
			break;
		case StanGry::KUCYKI:
			Kucyki();
			break;

		case StanGry::JAK:
			Jak();
			break;
		}
	}
}

void Gra::Menu()
{
	Text tytul ("Kuce", czcionka, 90);
	tytul.setStyle(Text::Bold); //czy pogrubione, pochylone, podkreœlone
	tytul.setStyle(Text::Italic); // bold - pogrubione, italic - pochylenie
	tytul.setStyle(Text::Underlined); // underlined - podkreslenie
	tytul.setColor(Color(244,0,161)); // kolor fashion fuchsia

	tytul.setPosition(1600/2 - tytul.getGlobalBounds().width/2, 60); //(x,y)


	Text nowa ("Nowa Gra", czcionka, 70);
	nowa.setStyle(Text::Bold);
	nowa.setColor(Color::White);
	nowa.setPosition(1600/2 - nowa.getGlobalBounds().width/2, 200); // x = szerokoœæ ekranu podzielona na pó³ i odejmujemy od tego po³owe d³ugoœci napisu, 
																	//aby napis by³ idealnie na œrodku

	Text instrukcja ("Gra - sterowanie", czcionka, 70);
	instrukcja.setStyle(Text::Bold);
	instrukcja.setColor(Color::White);
	instrukcja.setPosition(1600/2 - instrukcja.getGlobalBounds().width/2, 300);

	Text exit ("Koniec", czcionka, 70);
	exit.setStyle(Text::Bold);
	exit.setColor(Color::White);
	exit.setPosition(1600/2 - exit.getGlobalBounds().width/2, 400);



	while (stan == MENU)
	{
		Vector2f mysz (Mouse::getPosition(okno));
		Event zdarzenie;

		while(okno.pollEvent(zdarzenie))
		{
			//Wciœniêcie ESC lub przycisk X
			if(zdarzenie.type == Event::Closed || zdarzenie.type == Event::KeyPressed &&
				zdarzenie.key.code == Keyboard::Escape)
				stan = KONIEC;

			
			
			//klikniêcie MENU                                        
			else if(nowa.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				stan = KUCYKI;
				//stan = GRA;
			}
			
			//klikniêcie GRA - sterowanie
			else if(instrukcja.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				stan = JAK;	

			}

			//klikniêcie KONIEC
			else if(exit.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				stan = KONIEC;
			}
	}

	if(nowa.getGlobalBounds().contains(mysz))  nowa.setColor(Color(0,112,255)); //kolor brandeis blue
	else nowa.setColor(Color::White);
	
	if(instrukcja.getGlobalBounds().contains(mysz))  instrukcja.setColor(Color(127,255,0)); //kolor chartreuse
	else instrukcja.setColor(Color::White);
	
	if(exit.getGlobalBounds().contains(mysz))  exit.setColor(Color(255,244,79)); // kolor lemon yellow
	else exit.setColor(Color::White);


	sprajt.setTexture(tlo); //obiekt klasy Sprite do wyœwietlania t³a, które wczeœniej zosta³o za³adowane z pliku

	okno.clear();
	okno.draw(sprajt);
	okno.draw(tytul);
	okno.draw(nowa);
	okno.draw(instrukcja);
	okno.draw(exit);
	

	okno.display();

	}
}


void Gra::Jak()
{
	
	Jak_gram jak(okno);
	stan = MENU;
}

void Gra::Single()
{
	Silnik silnik(okno);
	stan = MENU;
}

void Gra::Kucyki()
{
	//Wybor wybor(okno);
	Wybor wybor(okno);
	stan = MENU;
}

