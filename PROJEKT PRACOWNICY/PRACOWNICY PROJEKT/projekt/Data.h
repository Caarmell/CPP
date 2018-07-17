#pragma once
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Data
{
public:
	
	Data(int d, int m, int r);
	~Data(void);
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz(void) const;
	void Wpisz(void);
	string DataCala(void) const;
	friend ostream &operator<<(ostream & wy, const Data &d);
	friend istream &operator>>(istream & we, Data &d);
	
private:
	void Koryguj(void);
public:
	int Porownaj(const Data &wzor) const;

};
