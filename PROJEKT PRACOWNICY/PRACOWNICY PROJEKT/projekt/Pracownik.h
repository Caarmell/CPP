#pragma once
#include "Napis.h"
#include "Data.h"
#include <iostream>



using namespace std;

class Pracownik
{
public:
	Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);
	~Pracownik(void);


private:
	Napis m_Imie; // obiekt ktory pozwala na odwolanie sie do publicznych funkcji klasy Napis
	Napis m_Nazwisko; // obiekt ktory pozwala na odwolanie sie do publicznych funkcji klasy Napis
	Data m_DataUrodzenia; // obiekt ktory pozwala na odwolanie sie do publicznych funkcji klasy Data
	const int m_nIDZatrudnienia;
	int zmienna;

public:
	const char* Imie(void) const;
	const char* Nazwisko(void) const;
	string DataUr(void) const;	
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz(void) const;
	void Wpisz(void);
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik &  wzorzec) const;
	friend ostream & operator<<(ostream &wy, const Pracownik &p);
	friend istream & operator >>(istream &we, Pracownik &p);
	Pracownik & operator=(const Pracownik & wzor);
	bool operator==(const Pracownik & wzor) const;
	friend class TablicaPracownikow;

};

