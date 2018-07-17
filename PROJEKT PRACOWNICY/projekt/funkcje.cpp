#include <iostream>

using namespace std;

// funkcja sprawdzaj¹ca czy wpisane pierwsze litery s¹ du¿e czy ma³e, jak ma³e to poprawia na du¿e
// jest to wykorzystywane TYLKO w mainie dla wywo³ania funkcji SZUKAJ z Tabeli Pracowników
// to takie udogodnienie, ¿eby siê nie martwiæ, ¿e wpisaliœmy Gosia i gosia i nam nie znalaz³o

void MaleNaDuze1 (char z[40])
{
	int i =0;
	if((z[i] >= 97) && (z[i] <= 122))
	{
		z[i] = z[i] - 32;
	}
}



