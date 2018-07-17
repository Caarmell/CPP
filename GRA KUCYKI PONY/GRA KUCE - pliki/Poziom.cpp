#include "Poziom.h"



Poziom::Poziom(void)
{

}

Poziom::Poziom(string plik_mapy)
{
	wczytajPlik(plik_mapy);
}

Poziom::~Poziom(void)
{
}

void Poziom::wczytajPlik(string plik_mapy)
{
	fstream plik;
	plik.open("dane/mapy/" + plik_mapy, std::ios::in);

	if (!plik.is_open())
		cout << "Nie znaleziono poziomu: " + plik_mapy;
	else
	{
		for (int y = 0; y<wys; y++)
		for (int x = 0; x<szer; x++)
		{
			int tmp;
			plik >> tmp;
			poziom[y][x].typ = Typy(tmp);

			if (tmp == 0)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}
			else if (tmp == 1)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = true;
				poziom[y][x].jestWolny = false;
			}
			else if (tmp == 2)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = true;
			}
			else if (tmp == 3)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = true;
			}

			else if (tmp == 4)
			{
				poziom[y][x].jestKolizja = true;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}

			else if (tmp == 5)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = true;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}

			else if (tmp == 6)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}

			else if (tmp == 7)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = false;
				poziom[y][x].jestOgien = true;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}

			else if (tmp == 8)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = true;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}

			else if (tmp == 9)
			{
				poziom[y][x].jestKolizja = false;
				poziom[y][x].jestOwoc = true;
				poziom[y][x].jestOgien = false;
				poziom[y][x].jestProfit = false;
				poziom[y][x].jestWolny = false;
			}
		}
	}

	plik.close();
}