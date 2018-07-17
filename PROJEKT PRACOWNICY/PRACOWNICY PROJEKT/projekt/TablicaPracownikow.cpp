#include "TablicaPracownikow.h"

TablicaPracownikow::TablicaPracownikow(void)
: m_nLiczbaPracownikow(0)
{

}

/********************************************************************************************************************************************************/

TablicaPracownikow::~TablicaPracownikow(void)
{
}

/********************************************************************************************************************************************************/

void TablicaPracownikow::Dodaj(const Pracownik & p)
{
	
	m_pTablica[m_nLiczbaPracownikow]=p;
	int s, c, x=0;
	m_nLiczbaPracownikow++;
	Pracownik pomocnicza, pomocna[20]; //potrzebujemy zmiennej pomocnicza kt�ra b�dzie u�yta do dodawania pracownika
	for(int i = 0; i < m_nLiczbaPracownikow; i++)
	{
		for(int k = 0; k < m_nLiczbaPracownikow - i - 1; k++) // napisane na podstawie algorytmu sortowania b�belkowego
		{
			if(m_pTablica[k].Porownaj(m_pTablica[k+1]) == 1)

			//m_pTablica[k] > m_pTablica[k+1]
			// do zmiennej pomocnicza przypisujemy wi�ksz� warto�� czyli w tym przypadku m_pTablica[k]
			// nast�pnie do m_pTablica[k] wpisujemy mniejsz� warto�� czyli m_pTablica[k+1]
			// nast�pnie przypisujemy do m_pTablica[k+1] to co przechowywujemy w zmiennej pomocnicza
			// czyli warto�� wi�ksz�

			{
				pomocnicza = m_pTablica[k]; 
				m_pTablica[k] = m_pTablica[k+1];
				m_pTablica[k+1] = pomocnicza; 
			}
			
			if(m_pTablica[k].Porownaj(m_pTablica[k+1]) == 0)

				// jak wprowadzone dane s� takie jak znajduj�cy si� w Tablicy Pracownik�w pracownik to usuwamy pracownika

			{

				// tak samo dla usun
				// przepisujemy od pocz�tku do momentu w kt�rym si� powtarza
				// przepisujemy do nowej tablicy pomocna kt�ra b�dzie nam teraz przechowywa� pracownik�w wszystkich opr�cz powtarzaj�cych si�
				// sprawdzamy dwie rzeczy, poniewa� gdy przychodzi taki sam pracownik jak ju� by� np Jan Kowalski
				// to automatycznie jest w��czone sortowanie i ustawia go pod Janem Kowalskim
				// teraz wystarczy por�wna� i przepisa� jednego a drugiego wyrzuci�
				// w m_pTablica wyst�puj� wszyscy pracownicy, nawet powtarzaj�cy sie
				// dlatego korzystamy z tablicy pomocnicza, kt�r� na ko�cu przypisujemy do m_pTablica

				for (int s = 0; s < m_nLiczbaPracownikow; s++)
					{
						if (m_pTablica[s].Porownaj(m_pTablica[s+1]) != 0)
							{
								pomocna[x] = m_pTablica[s];
								x++;
							}

					}
				
						for (c = 0; c < 20; c++)
							{
								m_pTablica[c] = pomocna[c]; // przepisanie do tablicy tablicy pomoc po jednym elemencie !
							}
			}
		}
	}
	
}

/********************************************************************************************************************************************************/

void TablicaPracownikow::Usun(const Pracownik & wzorzec)
{
	// wyzej opisany spos�b dzia�ania

	Pracownik pomoc[20];
	int k = 0, s;
	for (int i = 0; i < m_nLiczbaPracownikow; i++)
	{
		if(wzorzec.Porownaj(m_pTablica[i]) != 0)
		{
			pomoc[k] = m_pTablica[i];
			k++;
		}

	}

	for (s = 0; s < 20; s++)
	{
		m_pTablica[s] = pomoc[s]; // przepisanie do tablicy tablicy pomoc po jednym elemencie !
	}

	m_nLiczbaPracownikow--;

}

/********************************************************************************************************************************************************/

void TablicaPracownikow::WypiszPracownikow(void) const
{
	cout << setw(20) <<"IMIE PRACOWNIKA" << "\t" << setw(20) << "NAZWISKO PRACOWNIKA" << "\t" << "DATA URODZ." << "\t" << "ID" << endl;
	cout << endl;

	for ( int i=0; i < m_nLiczbaPracownikow; i++)
	{
		 m_pTablica[i].Wypisz();  // wypisanie tablicy po jednym elemencie 
	}
}

/********************************************************************************************************************************************************/

const Pracownik * TablicaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	int i, k= 0;

	// funkcja strcmp s�u�y do por�wnywania char�w
	// przeszukujemy ca�� tablic� i wypisuje pierwsze wystapienie pracownika
	
	for (i=0; i <m_nLiczbaPracownikow; i++)
	{
		if(strcmp( m_pTablica[i].Imie(), imie ) == 0 )
		{
			if(strcmp(m_pTablica[i].Nazwisko(), nazwisko) == 0)
			{
				k = 1;
				break;
			}
		}
		
	}
	
	if(k == 1)
		{
			cout << "\nPracownik jest w Tablicy Pracownikow na miejscu: " << i + 1 << endl;
		}
	else
		{
			cout << "\nTaki pracownik nie istnieje w tablicy ! " << endl;
			return 0;
		}
	
}

/********************************************************************************************************************************************************/

const Data * TablicaPracownikow::SzukajData(string &datau) const
{
	int i, k= 0;

	// nowe stworzone przez nas funkcje por�wnujemy na stringach
	// zwraca pierwsze wystapienie daty urodzenia 
	
	
	for (i=0; i <m_nLiczbaPracownikow; i++)
	{
		if(m_pTablica[i].DataUr() == datau )
		{
				k = 1;
				break;
		}
		
	}
	
	if(k == 1)
		// wypisuje miejsce wystapienia pracownika
		// wypisuje takze jego imie i nazwisko
		{
			cout << "\nPracownik jest w Tablicy Pracownikow na miejscu: " << i + 1 << endl;
			cout << "\nTen pracownik to: " << m_pTablica[i].Imie() << " " << m_pTablica[i].Nazwisko() << endl;
		}
	else
		{
			cout << "\nTaki pracownik nie istnieje w tablicy ! " << endl;
			return 0;
		}
	
}

void TablicaPracownikow::Zapisz (const char * nazwa_pliku)
{
	fstream plik (nazwa_pliku, ios::out);

	if (!plik.good ())
	{
		cout << "\nBlad odczytu \"" << nazwa_pliku << "\"!";
		return;
	}

	plik << m_nLiczbaPracownikow << endl;

	for (int i = 0; i < m_nLiczbaPracownikow; i++)
	{
		plik
			<< setw(20) << m_pTablica[i].Imie () << '\t'
			<< setw(20) << m_pTablica[i].Nazwisko () << '\t'
			<< m_pTablica[i].m_DataUrodzenia.Dzien () << '-'
			<< m_pTablica[i].m_DataUrodzenia.Miesiac () << '-'
			<< m_pTablica[i].m_DataUrodzenia.Rok () << '\t'
			<< m_pTablica[i].m_nIDZatrudnienia << endl << endl;
	}

	cout << "\nGotowe!" << endl;
	plik.close ();
}

void TablicaPracownikow::Wczytaj (const char * nazwa_pliku)
{
	string linia;
  ifstream plik ("dane.txt");
  if (plik.is_open())
  {
	  cout << "Wypisuje z pliku: \n" <<endl;
    while ( getline (plik,linia) )
    {
      cout << linia << '\n';
    }
    plik.close();
  }

  else cout << "Nie moge otworzyc pliku!";
}
