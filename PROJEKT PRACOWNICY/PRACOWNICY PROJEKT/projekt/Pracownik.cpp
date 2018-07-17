#include "Pracownik.h"
int licznik = -1;

Pracownik::Pracownik(const char* im , const char * naz , int dzien, int miesiac, int rok) 
					 : m_DataUrodzenia(dzien, miesiac, rok)
			,  m_nIDZatrudnienia(licznik)
{
		licznik++;
}


/********************************************************************************************************************************************************/

Pracownik:: Pracownik(const Pracownik & wzor)
	: m_DataUrodzenia(1,1,2000)
	, m_nIDZatrudnienia(wzor.m_nIDZatrudnienia)
{
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	m_DataUrodzenia.Ustaw(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
}

/********************************************************************************************************************************************************/

Pracownik::~Pracownik(void)
{
}

/********************************************************************************************************************************************************/

const char* Pracownik::Imie(void) const		
{
	return m_Imie.Zwroc();		
}

/*********************************************************************************************************************************************************/

const char* Pracownik::Nazwisko(void) const		
{
	return m_Nazwisko.Zwroc();	
}

/********************************************************************************************************************************************************/

string Pracownik::DataUr(void) const		
{
	return m_DataUrodzenia.DataCala();	
}

/********************************************************************************************************************************************************/

void Pracownik::Imie(const char* nowe_imie)	
{
	cout << "Podaj nowe imie." << endl;
	m_Imie.Ustaw(nowe_imie); 			
}

/********************************************************************************************************************************************************/

void Pracownik::Nazwisko(const char* nowe_nazwisko)	
{
	cout << "Podaj nowe nazwisko." << endl;
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

/********************************************************************************************************************************************************/

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)   
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
	m_DataUrodzenia.Wypisz();
}

/********************************************************************************************************************************************************/
void Pracownik::Wypisz(void) const	
{
	m_Imie.Wypisz();
	cout << "\t" ;
	m_Nazwisko.Wypisz();
	cout << "\t";
	m_DataUrodzenia.Wypisz();
	cout << "\t";
	cout << m_nIDZatrudnienia << endl;

}

/********************************************************************************************************************************************************/

void Pracownik::Wpisz(void)	 
{
	cout << "Podaj imie pracownika." << endl;
	m_Imie.Wpisz();
	m_Imie.MaleNaDuze(); //dodatkowo dopisana funkcja w klasie Napis, która zamienia pierwsze litery ma³e na du¿e dla imienia
	cout << "Podaj nazwisko pracownika." << endl;
	m_Nazwisko.Wpisz();
	m_Nazwisko.MaleNaDuze(); //dodatkowo dopisana funkcja w klasie Napis, która zamienia pierwsze litery ma³e na du¿e dla nazwiska
	cout << "Podaj date urodzenia pracownika: " <<endl;
	m_DataUrodzenia.Wpisz();	
}

/********************************************************************************************************************************************************/

int Pracownik::SprawdzImie(const char* por_imie) const		
{
	return m_Imie.SprawdzNapis(por_imie); 
}

/********************************************************************************************************************************************************/

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const	
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko); 								
}

/********************************************************************************************************************************************************/

int Pracownik::Porownaj(const Pracownik &  wzorzec) const
{
		if(this->m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko())==1)
		{
			return 1;
		}

		else if(this->m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko())==-1)
		{
			return -1;
		}
	
		else if(this->m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko())==0)
		{
				if(this->m_Imie.SprawdzNapis(wzorzec.Imie()) == 1)
				{
					return 1;
				}
				
				else if(this->m_Imie.SprawdzNapis(wzorzec.Imie()) == -1)
				{
					return -1;
				}

				else if(this->m_Imie.SprawdzNapis(wzorzec.Imie()) == 0)
				{
					
						if(this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 1)
						{
							return 1;
						}
						
						else if(this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == -1)
						{
							return -1;
						}
	
						else if(this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 0)
						{
							return 0;
						}
				}
		}
}

/********************************************************************************************************************************************************/

ostream & operator<<(ostream &wy, const Pracownik &p)
{
	p.m_Imie.Wypisz();
	wy << "\t\t" ;
	p.m_Nazwisko.Wypisz();
	wy << "\t\t";
	p.m_DataUrodzenia.Wypisz();

	return wy;
}

/********************************************************************************************************************************************************/

istream & operator >>(istream &we, Pracownik &p)
{
	cout << "Podaj imie pracownika." << endl;
	we >> p.m_Imie;
	p.m_Imie.MaleNaDuze(); //dodatkowo dopisana funkcja w klasie Napis, która zamienia pierwsze litery ma³e na du¿e dla imienia
	cout << "Podaj nazwisko pracownika." << endl;
	we >> p.m_Nazwisko;
	p.m_Nazwisko.MaleNaDuze(); //dodatkowo dopisana funkcja w klasie Napis, która zamienia pierwsze litery ma³e na du¿e dla nazwiska
	cout << "Podaj date urodzenia pracownika: " <<endl;
	we >> p.m_DataUrodzenia;	

	return we;
}

/********************************************************************************************************************************************************/

Pracownik & Pracownik:: operator=(const Pracownik & wzor)
{
	
	if (this != &wzor)
	{
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia.Ustaw (wzor.m_DataUrodzenia.Dzien (), wzor.m_DataUrodzenia.Miesiac (), wzor.m_DataUrodzenia.Rok ());
	
	}
	return *this;

}

/********************************************************************************************************************************************************/

bool Pracownik:: operator==(const Pracownik & wzor) const
{
	m_Imie == wzor.m_Imie;
	m_Nazwisko == wzor.m_Nazwisko;
	m_DataUrodzenia.Porownaj(wzor.m_DataUrodzenia);
	m_nIDZatrudnienia == wzor.m_nIDZatrudnienia;

	if((m_Imie == wzor.m_Imie) && (m_Nazwisko == wzor.m_Nazwisko) && (m_DataUrodzenia.Porownaj(wzor.m_DataUrodzenia))
		&&  (m_nIDZatrudnienia == wzor.m_nIDZatrudnienia)) return true;

	else return false;
}
/********************************************************************************************************************************************************/