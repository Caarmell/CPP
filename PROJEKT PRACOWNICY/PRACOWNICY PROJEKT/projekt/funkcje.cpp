#include <iostream>

using namespace std;

// funkcja sprawdzaj�ca czy wpisane pierwsze litery s� du�e czy ma�e, jak ma�e to poprawia na du�e
// jest to wykorzystywane TYLKO w mainie dla wywo�ania funkcji SZUKAJ z Tabeli Pracownik�w
// to takie udogodnienie, �eby si� nie martwi�, �e wpisali�my Gosia i gosia i nam nie znalaz�o

void MaleNaDuze1 (char z[40])
{
	int i =0;
	if((z[i] >= 97) && (z[i] <= 122))
	{
		z[i] = z[i] - 32;
	}
}



