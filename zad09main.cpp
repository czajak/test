#include <iostream>
#include "zad09.h"

using namespace std;

int main()
{
	cout << "========== Test stosu dla liczb typu int ==========" << endl;
	stos<int> sInt;
	try
	{
		sInt.dodaj_na_stos(5);
		sInt.dodaj_na_stos(15);
		sInt.ile_elementow();
		sInt.zdejmij_ze_stosu();
		sInt.ile_elementow();
		sInt.dodaj_na_stos(6);
		sInt.oproznij_stos();
		sInt.czy_pusty();
		sInt.zdejmij_ze_stosu();
		stos<int>sInt2;
		sInt2.skopiuj_stos(sInt);
	}
	catch (wyjatek w)
	{
		cout << w.info_wyjatek();
	}

	cout << endl << endl << "========== Test stosu dla liczb typu float ==========" << endl;
	stos<float> sFloat;
	try
	{
		sFloat.dodaj_na_stos(5);
		sFloat.dodaj_na_stos(15);
		sFloat.ile_elementow();
		sFloat.zdejmij_ze_stosu();
		sFloat.ile_elementow();
		sFloat.dodaj_na_stos(6);
		sFloat.oproznij_stos();
		sFloat.czy_pusty();
		sFloat.zdejmij_ze_stosu();
		stos<float>sFloat2;
		sFloat2.skopiuj_stos(sFloat);
	}
	catch (wyjatek w)
	{
		cout << w.info_wyjatek();
	}
	return 0;
}