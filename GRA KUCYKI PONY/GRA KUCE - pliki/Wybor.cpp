#include "Wybor.h"


Wybor::Wybor(RenderWindow &okno)
{

	//czcionka sprawdzanie czy wszystko jest na swoim miejscu jak czegos brakuje pojawia sie odpowiedni blad
	if(!czcionka.loadFromFile("dane/4MYLOVER.TTF"))
	{
		MessageBox(NULL, "Brak czcionki.", "ERROR", NULL);
		return ;
	}
	
		//T這 sprawdzanie czy wszystko jest na swoim miejscu jak czegos brakuje pojawia sie odpowiedni blad
	
	//Fluttershy
	if(!tekstura.loadFromFile("dane/grafika/F2.png")) //sprawdzenie czy t這 jest zaladowane z pliku jak nie to wyswietla b豉d
	{
		MessageBox(NULL, "Brak kucyka.", "ERROR", NULL);
		return ;

	}

	//Pinkiepie
	if(!tekstura1.loadFromFile("dane/grafika/P1.png")) //sprawdzenie czy t這 jest zaladowane z pliku jak nie to wyswietla b豉d
	{
		MessageBox(NULL, "Brak kucyka.", "ERROR", NULL);
		return ;

	}

	//Rarity
	if(!tekstura2.loadFromFile("dane/grafika/RA2.png")) //sprawdzenie czy t這 jest zaladowane z pliku jak nie to wyswietla b豉d
	{
		MessageBox(NULL, "Brak kucyka.", "ERROR", NULL);
		return ;

	}

	//Rainbow Dash
	if(!tekstura3.loadFromFile("dane/grafika/RAIN.png")) //sprawdzenie czy t這 jest zaladowane z pliku jak nie to wyswietla b豉d
	{
		MessageBox(NULL, "Brak kucyka.", "ERROR", NULL);
		return ;

	}

	//Twillight Sparkle
	if(!tekstura4.loadFromFile("dane/grafika/T2.png")) //sprawdzenie czy t這 jest zaladowane z pliku jak nie to wyswietla b豉d
	{
		MessageBox(NULL, "Brak kucyka.", "ERROR", NULL);
		return ;

	}


	startWybor(okno);
	
}


Wybor::~Wybor(void)
{
}

void Wybor::startWybor(RenderWindow &okno)
{
	bool menu = false;
	Gra gra;
	
	Text nowa ("FLUTTERSHY", czcionka, 50);
	nowa.setStyle(Text::Bold);
	nowa.setColor(Color(255,255,200));
	nowa.setPosition(100, 150);

	Text nowa1 ("PINKIE PIE", czcionka, 50);
	nowa1.setStyle(Text::Bold);
	nowa1.setColor(Color(255,70,255));
	nowa1.setPosition(400, 660);

	Text nowa2 ("RARITY", czcionka, 50);
	nowa2.setStyle(Text::Bold);
	nowa2.setColor(Color::White);
	nowa2.setPosition(760, 150);

	Text nowa3 ("RAINBOW DASH", czcionka, 50);
	nowa3.setStyle(Text::Bold);
	nowa3.setColor(Color::Cyan);
	nowa3.setPosition(940, 660);

	Text nowa4 ("TWILIGHT \nSPARKLE", czcionka, 50);
	nowa4.setStyle(Text::Bold);
	nowa4.setColor(Color(200,63,255));
	nowa4.setPosition(1300, 100);

	Text nowa5 ("KUCYKI DO WYBORU", czcionka, 70);
	nowa5.setStyle(Text::Bold);
	nowa5.setColor(Color(102,255,102));
	nowa5.setPosition(1600/2 - nowa5.getGlobalBounds().width/2, 20);

	Text nowa6("Fluttershy - po wodzie i piasku chodzi normalnie, Pinkie Pie - zjada owoce za dwie, \nRarity - duzo zycia, wolniej chodzi, Rainbowdash - malo zycia, szybko biega \nTwilight Sparkle - ogien i las jej nie zabiera zycia", czcionka, 30);
	nowa6.setColor(Color::White);
	nowa6.setPosition(100,720);


	while (!menu)
	{
		
		Vector2f mysz(Mouse::getPosition(okno));
		Event zdarzenie;

		while (okno.pollEvent(zdarzenie))
		{

			if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)
			{	
				menu = true;

			}


			 else if(nowa.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				path = "dane/grafika/fluttershy.png";
				gra.Single();
				
			}



			else if(nowa1.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				path = "dane/grafika/pinkiepie.png";
				gra.Single();	
				
			}

			 else if(nowa2.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				path = "dane/grafika/rarity.png";
				gra.Single();
				
				
			}

			 
			 else if(nowa3.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				path = "dane/grafika/rainbowdash.png";
				gra.Single();
				
		
			}

			 else if(nowa4.getGlobalBounds().contains(mysz) &&
				zdarzenie.type == Event::MouseButtonReleased && zdarzenie.key.code == Mouse::Left)
			{
				path = "dane/grafika/twilightsparke.png";
				gra.Single();
						
			}

		}	

		okno.clear();// og鏊ne t這 
		fluttershy.setTexture(tekstura);
		pinkie.setTexture(tekstura1);
		rarity.setTexture(tekstura2);
		rainbowdash.setTexture(tekstura3);
		twilight.setTexture(tekstura4);

		fluttershy.setPosition(200,250);
		pinkie.setPosition(480,250);
		rarity.setPosition(760,250);
		rainbowdash.setPosition(1040,250);
		twilight.setPosition(1320,250);


			if (zegarek.getElapsedTime() > seconds(0.09f))
				{
					if (rama < 10 /*liczba klatek animacji*/)
						rama++;
					else
						rama = 0; //zapetlanie animacji

					fluttershy.setTextureRect(IntRect(rama * 140, 0, 140, 400));  // rama * szerokosc, 0, szerokosc, wysokosc
					pinkie.setTextureRect(IntRect(rama * 140, 0, 140, 400));
					rarity.setTextureRect(IntRect(rama * 140, 0, 140, 400));
					rainbowdash.setTextureRect(IntRect(rama * 140, 0, 140, 400));
					twilight.setTextureRect(IntRect(rama * 140, 0, 140, 400));

					zegarek.restart();
				}



		okno.draw(fluttershy);
		okno.draw(pinkie);
		okno.draw(rarity);
		okno.draw(rainbowdash);
		okno.draw(twilight);
		okno.draw(nowa);
		okno.draw(nowa1);
		okno.draw(nowa2);
		okno.draw(nowa3);
		okno.draw(nowa4);
		okno.draw(nowa5);
		okno.draw(nowa6);

		okno.display();




	}


}

string Wybor::path;

