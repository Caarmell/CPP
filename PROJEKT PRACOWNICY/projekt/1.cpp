// L03 Grupa 6
// Marta Jaworska
// Mateusz Jêdrzejczyk

#include <conio.h> //system ("pause")
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "TablicaPracownikow.h"

void MaleNaDuze1 (char z[40]);


int main()
{
	char  spr_imie[40];
	char  spr_nazwisko[40];
	
	string szukanie;

		
	Pracownik pracownik, wzorzec_p; // obiekt odwo³uje siê do publicznych funkcji klasy Pracownik
	
	TablicaPracownikow Tab;
	
	char znak;

	while(1)
	{
		string tresc = "\t\t PANEL PRACOWNIKOW - CO CHCESZ ZROBIC? ";
		
		string buzki(tresc.length() + 38, 2); // wbudowana funkcja podajemy w nawiasie ile razy ma byc wyswietlony dany znak i jaki to ma byc znak
		cout << buzki << endl;
		cout << endl;
		cout << tresc << endl;
		cout << endl;
		cout << " Nacisnij: \n\nd - Dodawanie nowego pracownika \t\t u - Usuwanie pracownika" << endl;
		cout << "s - Szukanie po imieniu i nazwisku \t\t p - Szukanie po dacie" << endl;
		cout << "o - Odczyt z pliku \t\t\t\t z - Zapis do pliku" << endl;
		cout << "w - Wypisywanie tablicy pracownikow \t\t q - Wyjscie" << endl;
		cout << endl;
		cout << buzki << endl;

		cin >> znak;

		switch(znak)
		{
		case 'd':
			cout << endl;
			pracownik.Wpisz();
			Tab.Dodaj(pracownik);
			cout << endl;
			break;
		case 'u':
			cout << endl;
			cout << "Podaj pracownika do usuniecia: " << endl;
			wzorzec_p.Wpisz();
			cout << "\nUsuwam pracownika: " << wzorzec_p.Imie() << " " << wzorzec_p.Nazwisko() << " " 
				 << wzorzec_p.DataUr() <<"\n" << endl;
			Tab.Usun(wzorzec_p);
			cout << endl;
			break;
		case 's':
			cout << endl;
			cout << "\n Wpisz szukanego pracownika a ja wypisze jego 1 miejsce wystapienia. " << endl;
			cout << "\n Podaj imie do sprawdzenia: ";
			cin >> spr_imie;
			MaleNaDuze1(spr_imie);
			cout << "\n Podaj nazwisko do sprawdzenia: ";
			cin >> spr_nazwisko;
			MaleNaDuze1(spr_nazwisko);
			cout << "\nSzukam pracownika: " << spr_imie << " " << spr_nazwisko << endl;
			Tab.Szukaj(spr_nazwisko, spr_imie);
			cout << endl;
			break;
		case 'p':
			cout << endl;
			cout <<"\n Podaj date do szukania w formacie dd-mm-rrrr: ";
			cin >> szukanie;
			Tab.SzukajData(szukanie);
			cout << endl;
			break;
		case 'o':
			Tab.Wczytaj ("dane.txt");
			cout << endl;
			break;
		case 'z':
			Tab.Zapisz ("dane.txt");
			cout << endl;
			break;
		case 'w':
			cout << endl;
			Tab.WypiszPracownikow();
			cout << endl;
			break;
		case 'q':
			return 0;
			break;
		default:
			cout << endl;
			cout << "Podano zly znak ! \nSprobuj jeszcze raz :)" << endl;
			cout << endl;
			break;

		}

		
	}

	system("pause");
	return 0;
}
