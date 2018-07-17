#include "Data.h"


/********************************************************************************************************************************************************/


Data::Data(int d, int m, int r)
{
	Ustaw(d,m,r);
}

/********************************************************************************************************************************************************/
 
Data::~Data(void)
{
}

/********************************************************************************************************************************************************/

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

/********************************************************************************************************************************************************/

int Data::Dzien() const
{
	return m_nDzien;
}

/********************************************************************************************************************************************************/

int Data::Miesiac() const
{
	return m_nMiesiac;
}

/********************************************************************************************************************************************************/

int Data::Rok() const
{
	return m_nRok;
}

/********************************************************************************************************************************************************/

void Data::Wypisz(void) const
{
	string data="";
	string tmp="";

	//itoa - s³u¿y do zamieniania z inta na stringa
	// sprawdzamy czy dzien i miesiac jest mniejszy od 10 jak tak to dodajemy 0, aby data by³a w formacie dd-mm
	// dla roku robimy podobne sprawdzenie tylko ¿e trzeba sprawdziæ jeszcze czy mniejszy od 100 i od 1000
	// ¿eby rok by³ w formacie rrrr
	// dziêki rozbudowanej funkcji wypisz nasz rok jest zawsze w formacie dd-mm-rrrr
	
	if (m_nDzien < 10)
	{
		data += "0" ;
		itoa(m_nDzien, (char*)tmp.c_str(), 10);  // zamiana z chara na stringa
		data += tmp.c_str(); //doklejenie wy¿szej linijki do naszej daty, w której jest zero, dziêki temu bêdzie wyœwietlaæ 0(1-9)
		
	}
	else
	{
		itoa(m_nDzien, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (m_nMiesiac < 10)
	{
		data += "-0";
		itoa(m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else 
	{
		data += "-";
		itoa(m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (m_nRok < 10)
	{
		data += "-000";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
	
	else if (m_nRok < 100) 
	{
		data += "-00";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	else if (m_nRok < 1000) 
	{
		data += "-0";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else
	{
		data += "-";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	// po sklejeniu ca³ej daty wypisujemy :) 
	cout << data;

	
}

/********************************************************************************************************************************************************/

void Data::Wpisz(void)
{
	cout << "Podaj dzien: " ;
	cin >> m_nDzien;
	cout << "Podaj miesiac: " ;
	cin >> m_nMiesiac;
	cout << "Podaj rok: " ;
	cin >> m_nRok;
	Koryguj(); 
}

/********************************************************************************************************************************************************/

void Data::Koryguj(void)
{
	if(m_nMiesiac >12)
		m_nMiesiac = 12;
	if(m_nMiesiac<1)
		m_nMiesiac = 1;
	if(m_nDzien < 1) m_nDzien = 1; // kazdy dzien w kazdym miesiacu zaczyna sie od 1
	else 
		if((m_nRok % 4) != 0 && m_nMiesiac == 2 && m_nDzien > 28) m_nDzien = 28; //tylko dla lutego w roku, ktory ma 365 dni
	else
		if((m_nRok % 4) == 0 && m_nMiesiac == 2 && m_nDzien > 29) m_nDzien = 29; //tylko dla lutego w roku przestepnym (366 dni)
	else 
		if((m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 
		|| m_nMiesiac == 8 || m_nMiesiac == 10  || m_nMiesiac == 12) 
		&& m_nDzien > 31) m_nDzien = 31;		//miesiace ktore maja 31 dni
	else 
		if((m_nMiesiac == 4 || m_nMiesiac == 6   || m_nMiesiac == 9 || m_nMiesiac == 11) 
		&& m_nDzien > 30) m_nDzien = 30;		// miesiace ktore maja 30 dni
}

/********************************************************************************************************************************************************/

int Data::Porownaj(const Data &wzor) const 
{										  
	
	if (wzor.m_nRok > m_nRok) return -1;
	else if (wzor.m_nRok < m_nRok) return 1;
	else if (wzor.m_nRok == m_nRok) 
	{
		if (wzor.m_nMiesiac > m_nMiesiac) return -1;
		else if (wzor.m_nMiesiac < m_nMiesiac) return 1;
		else if (wzor.m_nMiesiac == m_nMiesiac) 
		{
			if (wzor.m_nDzien > m_nDzien) return -1;
			else if (wzor.m_nDzien < m_nDzien) return 1;
			else if (wzor.m_nDzien == m_nDzien) return 0;
		}
	} 

}

/********************************************************************************************************************************************************/

string Data::DataCala(void) const
{
	string data="";
	string tmp="";

	//itoa - s³u¿y do zamieniania z inta na stringa
	// sprawdzamy czy dzien i miesiac jest mniejszy od 10 jak tak to dodajemy 0, aby data by³a w formacie dd-mm
	// dla roku robimy podobne sprawdzenie tylko ¿e trzeba sprawdziæ jeszcze czy mniejszy od 100 i od 1000
	// ¿eby rok by³ w formacie rrrr
	// data jest zawsze w formacie dd-mm-rrrr
	
	if (m_nDzien < 10)
	{
		data += "0" ;
		itoa(m_nDzien, (char*)tmp.c_str(), 10);  // zamiana z chara na stringa
		data += tmp.c_str(); //doklejenie wy¿szej linijki do naszej daty, w której jest zero, dziêki temu bêdzie wyœwietlaæ 0(1-9)
		
	}
	else
	{
		itoa(m_nDzien, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (m_nMiesiac < 10)
	{
		data += "-0";
		itoa(m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else 
	{
		data += "-";
		itoa(m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (m_nRok < 10)
	{
		data += "-000";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
	
	else if (m_nRok < 100) 
	{
		data += "-00";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	else if (m_nRok < 1000) 
	{
		data += "-0";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else
	{
		data += "-";
		itoa(m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	// po sklejeniu ca³ej daty wypisujemy :) 
	

	return data;

	
}

/********************************************************************************************************************************************************/


// strumien wyjscia dla daty
ostream &operator<<(ostream & wy, const Data &d)
{
	string data="";
	string tmp="";

	//itoa - s³u¿y do zamieniania z inta na stringa
	// sprawdzamy czy dzien i miesiac jest mniejszy od 10 jak tak to dodajemy 0, aby data by³a w formacie dd-mm
	// dla roku robimy podobne sprawdzenie tylko ¿e trzeba sprawdziæ jeszcze czy mniejszy od 100 i od 1000
	// ¿eby rok by³ w formacie rrrr
	// dziêki rozbudowanej funkcji wypisz nasz rok jest zawsze w formacie dd-mm-rrrr
	
	if (d.m_nDzien < 10)
	{
		data += "0" ;
		itoa(d.m_nDzien, (char*)tmp.c_str(), 10);  // zamiana z chara na stringa
		data += tmp.c_str(); //doklejenie wy¿szej linijki do naszej daty, w której jest zero, dziêki temu bêdzie wyœwietlaæ 0(1-9)
		
	}
	else
	{
		itoa(d.m_nDzien, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (d.m_nMiesiac < 10)
	{
		data += "-0";
		itoa(d.m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else 
	{
		data += "-";
		itoa(d.m_nMiesiac, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	if (d.m_nRok < 10)
	{
		data += "-000";
		itoa(d.m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
	
	else if (d.m_nRok < 100) 
	{
		data += "-00";
		itoa(d.m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}

	else if (d.m_nRok < 1000) 
	{
		data += "-0";
		itoa(d.m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	else
	{
		data += "-";
		itoa(d.m_nRok, (char*)tmp.c_str(), 10);
		data += tmp.c_str();
	}
		
	// po sklejeniu ca³ej daty wypisujemy :) 
	wy << data;
	return wy;

}

/********************************************************************************************************************************************************/

istream &operator>>(istream & we, Data &d)
{


	cout << "Podaj dzien: " ;
	we >> d.m_nDzien;
	cout << "Podaj miesiac: " ;
	we >> d.m_nMiesiac;
	cout << "Podaj rok: " ;
	we >> d.m_nRok;
	d.Koryguj(); 

	return we;
}

/********************************************************************************************************************************************************/