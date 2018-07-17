#include "Silnik.h"
#include "Wrog.h"


Silnik::Silnik(RenderWindow &okn)
{
	iloscOwocow = 0;
	poziom = 1;
	chmura.miejsce[250][300].jestWrog = true;
	chmura.miejsce[1000][550].jestWrog = true;
	chmura.miejsce[200][640].jestWrog = true;
	luna.miejsce[100][100].jestLuna = true;

	if (!czcionka.loadFromFile("dane/4MYLOVER.ttf"))
	{
		MessageBox(NULL, "Nie odnaleziono czcionki!", "ERROR", NULL);
		return;
	}
	//wczytanie tekstur
	for (int i = 1; i < Poziom::LICZ; i++)
	{
		tekstura[i].loadFromFile("dane/grafika/mapy.png", IntRect((i - 1)*poz.pole_szer, 0, poz.pole_szer, poz.pole_wys));
	}

	//ustawienie kafli
	poz.wczytajPlik("map.poziom");

	//Muzyka - musi byæ w konstruktorze bo inaczej nie dzia³a
	if(!muzyka.openFromFile("dane/muzyka/pony.ogg")) //sprawdzenie czy muzyka w pliku jak nie to wyswietla b³ad 
	{
		MessageBox(NULL, "Brak muzyki.", "ERROR", NULL);
		return ;
	}

	muzyka.setLoop(true);
	muzyka.play();


	for (int i = 0; i<poz.wys; i++)
	{
		for (int j = 0; j<poz.szer; j++)
		{
			if (poz.poziom[i][j].typ != Poziom::NIC)
			{
				sprite[i][j].setTexture(tekstura[poz.poziom[i][j].typ]);
				sprite[i][j].setPosition(j*poz.pole_szer, i*poz.pole_wys);
				if (poz.poziom[i][j].typ == Poziom::BANAN) iloscOwocow++;
				if (poz.poziom[i][j].typ == Poziom::JABLKO) iloscOwocow++;
			}
		}
	}
	startSilnik(okn);
}



Silnik::~Silnik(void)
{
}

void Silnik::startSilnik(RenderWindow &okno)
{
	bool menu = false;
	Clock zegar;
	float timer = 0;

	while (!menu)
	{
		Time t1 = zegar.getElapsedTime(); 
		string hp = "\tZYCIE: ", hp2, czas1, czas2, str, tmp, tmp1 = "\tOWOCKI:", str1;// hp2 ilosc zycia
		itoa(player.zycie, (char*)hp2.c_str(), 10);
		str1 = hp2.c_str();
		itoa(player.owoce, (char*)tmp.c_str(), 10);
		str = tmp.c_str();
		timer = t1.asSeconds();
		itoa(timer, (char*)czas1.c_str(), 10);
		czas2 = czas1.c_str();
		Text licznik("\tCZAS: " + czas2 + " " + hp + " " + str1 + " " + tmp1 + " " + str, czcionka, 25);
		licznik.setStyle(Text::Bold);
		licznik.setColor(Color::Magenta);
		licznik.setPosition(800, 0);
		Vector2f mysz(Mouse::getPosition(okno));
		Event zdarzenie;

		while (okno.pollEvent(zdarzenie))
		{

			if (zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Escape)
				menu = true;
			if (player.zycie == 0)
			{
				string tmp,wy,z;
				char* a;
				itoa(player.owoce,(char*)tmp.c_str(),10);
				wy=tmp.c_str();
				z="KONIEC GRY :( \nTwoja liczba owocow: ";
				z+=wy;
				a = new char[z.length()];
				strcpy(a,z.c_str());
				MessageBox(NULL, a , "ERROR", NULL);
				return ;
	
				menu = true;
			}
			if (iloscOwocow == 0)
			{
				poziom++;
				string tmp2, str1;
				itoa(poziom, (char*)tmp2.c_str(), 10);
				string str = tmp2.c_str();
				string tmp3 = "map" + str;
				WczytajPoziom(tmp3);
			}

		}


		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.idzPrawo();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player.idz();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.idzLewo();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			player.idztyl();
		}

		else
		{player.stop();}

		sprawdz_kolizje();
		player.odswiez();
		chmura.odswiez();
		luna.odswiez();

		if (iloscOwocow == 0)player.tp();

		okno.clear(Color(140, 255, 255, 0));// ogólne t³o 
		//rysowanie poziomu
		for (int i = 0; i<poz.wys; i++)
		for (int j = 0; j<poz.szer; j++)
		if (poz.poziom[i][j].typ !=Poziom::NIC)
			okno.draw(sprite[i][j]);

		if(player.zycie<0) player.zycie=0;			

		okno.draw(chmura);
		okno.draw(luna);
		okno.draw(player);
		okno.draw(licznik);
		okno.display();

	}


}

void Silnik::sprawdz_kolizje()
{
	
	//pobranie aktualnej wartoœci boxa
	FloatRect box1(player.getBoundingBox());
	FloatRect enemybox1(chmura.getBoundingBox());
	FloatRect enemybox2(chmura.getBoundingBox1());
	FloatRect enemybox3(chmura.getBoundingBox2());
	FloatRect enemybox4(chmura.getBoundingBox3());
	FloatRect enemyboxluna(luna.getBoundingBoxLuna());
	//zaktualizowanie go do wartoœci gdyby gracz siê ruszy³

	box1.left += (player.getSpeed().x); //dzielimy na 10 aby bardziej  zbli¿yæ siê do œciany
	box1.top += (player.getSpeed().y);

	/*
	Schemat sprawdzania naszego boxa z ponumerowanymi wierzcholkami
	1 ___ 2
	|     |
	3 ___ 4
	*/

	//1
	int x = box1.left / poz.pole_szer;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	int y = box1.top / poz.pole_wys;

	if (poz.poziom[y][x].jestKolizja && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();

	}

	//2
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	y = box1.top / poz.pole_wys;
	if (poz.poziom[y][x].jestKolizja && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}

	//3
	x = (box1.left) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestKolizja && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}

	//4
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestKolizja && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		player.stop();
	}

	//1 ogien
	x = box1.left / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOgien && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		
		
		if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		player.predkosc = 20;
	}
		else
		{
			player.zycie -= 0.1;
			player.predkosc = 5;
			Sleep(100);
		}

	}

	//2 ogien
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOgien && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		

	if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		player.predkosc = 20;
	}
		else
		{
			player.zycie -= 0.1;
			player.predkosc = 5;
			Sleep(100);
		}
	}

	//3 ogien
	x = (box1.left) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOgien && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		
	
	if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		player.predkosc = 20;
	}
		else
		{
			player.zycie -= 0.1;
			player.predkosc = 5;
			Sleep(100);
		}
	}

	//4 ogien
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOgien && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		
	if (Wybor::path =="dane/grafika/twilightsparke.png")
	{
		player.predkosc = 20;
	}
		else
		{
			player.zycie -= 0.1;
			player.predkosc = 5;
			Sleep(100);
		}
		
	}

	//1 owoce
	x = box1.left / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOwoc && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		

	if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		 player.owoce++;
	}

		player.owoce++;
		iloscOwocow--;
	}

	//2 owoce
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOwoc && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		 player.owoce++;
	}
		player.owoce++;
		iloscOwocow--;
	}

	//3 owoce
	x = (box1.left) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_szer;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOwoc && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		 player.owoce++;
	}
		player.owoce++;
		iloscOwocow--;
	}

	//4 owoce
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestOwoc && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		if (Wybor::path =="dane/grafika/pinkiepie.png")
	{
		 player.owoce++;
	}
		player.owoce++;
		iloscOwocow--;
	}


	//1 wolniej piasek woda 
	x = box1.left / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;

	if (poz.poziom[y][x].jestWolny && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		
		if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		player.predkosc = 10;
	}
		else 
			{
				player.predkosc = 0.5;
				Sleep(100);
			}

	}

	//2 wolniej piasek woda 
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestWolny && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
	
		if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		player.predkosc = 10;
	}
		else 
			{
				player.predkosc = 0.5;
				Sleep(100);
			}
	}

	//3 wolniej piasek woda 
	x = (box1.left) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestWolny && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		
			if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		player.predkosc = 10;
	}
		else 
			{
				player.predkosc = 0.5;
				Sleep(100);
			}
	}

	//4 wolniej piasek woda 
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestWolny && box1.intersects(sprite[y][x].getGlobalBounds()))
	{

		if (Wybor::path =="dane/grafika/fluttershy.png")
	{
		player.predkosc = 10;
	}
		else 
			{
				player.predkosc = 0.5;
				Sleep(100);
			}
	}




	//1 bonus
	x = box1.left / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestProfit && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		player.zycie+=10;
	}

	//2 bonus
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = box1.top / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestProfit && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		player.zycie+=10;
	}

	//3 bonus
	x = (box1.left) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_szer;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestProfit && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		player.zycie+=10;
	}

	//4 bonus
	x = (box1.left + poz.pole_szer) / poz.pole_szer;
	y = (box1.top + poz.pole_wys) / poz.pole_wys;
	if (x > 1600) x=1600;
	if (x<0) x=0;
	if (poz.poziom[y][x].jestProfit && box1.intersects(sprite[y][x].getGlobalBounds()))
	{
		sprite[y][x].setPosition(Vector2f(1600, 0));
		player.zycie+=10;
	}

	//1 wrog chmura jesli chmura wejdzie na mnie
	if (enemybox1.intersects(box1) || enemybox2.intersects(box1) || enemybox3.intersects(box1) || enemybox4.intersects(box1))
	{

		player.zycie -= 0.1;
		Sleep(100);
		return;

	}
	//2 wrog chmura jesli ja wejde na chmure
	if (box1.intersects(enemybox1) || box1.intersects(enemybox2) || box1.intersects(enemybox3) || box1.intersects(enemybox3))
	{

		player.zycie -= 0.1;
		Sleep(100);
		return;

	}

	// 1 pozerajaca kucyka luna jak luna wejdzie w kucyka
		if (enemyboxluna.intersects(box1))
	{

		player.zycie = 0;
		//Sleep(100);
		return;

	}
	// 2 pozerajaca kucyka luna jak kucyk wejdzie w luna
	if (box1.intersects(enemyboxluna))
	{

		player.zycie = 0;
		//Sleep(100);
		return;

	}

}

void Silnik::WczytajPoziom(string nazwaPliku)
{
	poz.wczytajPlik(nazwaPliku + ".poziom");

	for (int i = 0; i<poz.wys; i++)
	{
		for (int j = 0; j<poz.szer; j++)
		{
			if (poz.poziom[i][j].typ != Poziom::NIC)
			{
				sprite[i][j].setTexture(tekstura[poz.poziom[i][j].typ]);
				sprite[i][j].setPosition(j*poz.pole_szer, i*poz.pole_wys);
				if (poz.poziom[i][j].typ == Poziom::JABLKO) iloscOwocow++;
				if (poz.poziom[i][j].typ == Poziom::BANAN) iloscOwocow++;
			}
		}
	}

}
