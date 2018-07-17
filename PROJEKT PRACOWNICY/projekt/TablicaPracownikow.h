#pragma once
#include "pracownik.h"
#include "Data.h"
#include <fstream>
#include <iomanip> // do wywo³ania setw()
#include <cstring>
#include <cstdio>

class TablicaPracownikow
{
public:
	TablicaPracownikow(void);
	~TablicaPracownikow(void);
	int j;
private:
	Pracownik m_pTablica[20];
	int m_nLiczbaPracownikow;
public:
	void Dodaj(const Pracownik & p);
	void Usun(const Pracownik & wzorzec);
	void WypiszPracownikow(void) const;
	const Pracownik * Szukaj(const char * nazwisko, const char * imie) const;
	const Data * SzukajData(string &datau) const;
	void Zapisz(const char* nazwa_pliku);
	void Wczytaj(const char* nazwa_pliku);
	
};
