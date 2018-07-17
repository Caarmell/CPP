#pragma once
#include <iostream>
#include <string>
#include <iomanip> // do wywo³ania setw()

using namespace std;

class Napis
{
public:
	
	Napis(const char *nap = "");
	Napis(const Napis & wzor);
	~Napis(void);
	
private:
	char *m_pszNapis;
	int m_nDl;
	
public:
	const char* Zwroc(void) const;
	void Ustaw(const char* nowy_napis);
	void Wypisz(void) const;
	void Wpisz(void);
	int SprawdzNapis(const char* por_napis) const;
	void MaleNaDuze(void);
	Napis& operator=(const Napis &wzor);
	bool operator==(const Napis &wzor) const;
	friend ostream &operator<<(ostream & wy, const Napis &p);
	friend istream &operator>>(istream & we, const Napis &p);
};
