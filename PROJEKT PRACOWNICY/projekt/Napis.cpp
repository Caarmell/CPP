#include "Napis.h"



Napis::Napis(const char *nap )
{
	m_nDl = strlen(nap);
	m_pszNapis = new char[m_nDl + 1];
}

/********************************************************************************************************************************************************/

Napis::Napis(const Napis & wzor)
{
	
	m_pszNapis = new char[strlen(wzor.m_pszNapis) + 1];

	strcpy(m_pszNapis, wzor.m_pszNapis);
	
	
}

/********************************************************************************************************************************************************/

Napis::~Napis(void)
{
	delete [] m_pszNapis;
}

/********************************************************************************************************************************************************/

 const char* Napis::Zwroc(void) const
{
	return m_pszNapis;    
}

/********************************************************************************************************************************************************/

void Napis::Ustaw(const char* nowy_napis) 
{
	char a[40];
	cout << "Wpisz nowe: ";
	cin >> a;
	m_pszNapis = new char [strlen(a)+1];
	strcpy(m_pszNapis, a);
	nowy_napis = m_pszNapis;

}

/********************************************************************************************************************************************************/

void Napis::Wypisz(void) const
{
	cout << setw(20) << m_pszNapis;
	// setw to wbudowana funkcja która ustawia nam odpowiednio napisy, sprawdza jakiej s¹ d³ugoœci 
	//je¿eli nie tyle ile jest zapisane w nawiasie to dodaje spacje przez co kolumny s¹ równiutkie :)
	// dzia³a na stringach dlatego wy¿ej jest przypisanie chara do stringa za pomoc¹ operatora przypisania '='
}

/********************************************************************************************************************************************************/

void Napis::Wpisz(void)
{
	char a[40];

	cout << "Wpisz: " ;
	cin >> a ;
	m_pszNapis = new char [strlen(a) + 1];
	strcpy(m_pszNapis,a);
}

/********************************************************************************************************************************************************/

int Napis::SprawdzNapis(const char* por_napis) const
{					
	string napis = m_pszNapis, porownaj = por_napis;

			 	if(napis > porownaj) return 1;  
				else if(napis < porownaj) return -1;  
				else if(napis == porownaj) return 0; 
				
}

/********************************************************************************************************************************************************/

void Napis::MaleNaDuze(void)
{
	int i =0;
	if((m_pszNapis[i] >= 97) && (m_pszNapis[i] <= 122))
	{
		m_pszNapis[i] = m_pszNapis[i] - 32;
	}
		
}
/*********************************************************************************************************************************************************/

Napis & Napis:: operator=(const Napis &wzor)
{

	if (this != &wzor)
	{
		//Cz. destruktorowa
		delete[] m_pszNapis;

		//Cz. Konst.Kopiujacego
		m_pszNapis = new char[strlen(wzor.m_pszNapis) + 1];

		strcpy(m_pszNapis, wzor.m_pszNapis);
	}
	return *this;
}

/********************************************************************************************************************************************************/

bool Napis::operator==(const Napis &wzor) const
{
	int a;
	a = strcmp(m_pszNapis, wzor.m_pszNapis);

	if(a==0) return true;
	else return false;



}

/********************************************************************************************************************************************************/

ostream &operator<<(ostream & wy, const Napis &p)
{
	wy << setw(20) << p.m_pszNapis;
	return wy;
}

/********************************************************************************************************************************************************/

istream &operator>>(istream & we, const Napis &p)
{
	cout << "Wpisz: " ;
	we >> p.m_pszNapis ;
	return we;
}

/********************************************************************************************************************************************************/