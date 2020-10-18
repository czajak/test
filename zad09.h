#include <iostream>

using namespace std;

//Klasa obslugujaca wyjatki =================
class wyjatek
{
	public:
		string info_wyjatek()
		{
			return "Wykryto wyjatek! Stos jest pusty.";
		}	
};
//===========================================

template <class T>
class stos
{
	private:
		T* wartosci;
		T* pomocniczy_stos;
		int ile;
	public:
		stos()
		{
			ile = 0;
		}

		~stos()
		{
			delete[] wartosci;
		}

		void dodaj_na_stos(T nowy_element)
		{
			pomocniczy_stos = new T[ile];
			for (int i = 0; i < ile; i++)
			{
				pomocniczy_stos[i] = wartosci[i];
			}
			delete[] wartosci;
			wartosci = new T[ile + 1];
			for (int i = 0; i < ile; i++)
			{
				wartosci[i] = pomocniczy_stos[i];
			}
			wartosci[ile] = nowy_element;
			ile++;
			delete[] pomocniczy_stos;
		}

		void zdejmij_ze_stosu()
		{
			if (ile == 0)
			{
				throw wyjatek();
			}
			else
			{
				ile--;
				pomocniczy_stos = new T[ile];
				for (int i = 0; i < ile; i++)
				{
					pomocniczy_stos[i] = wartosci[i];
				}
				delete[] wartosci;
				wartosci = new T[ile];
				for (int i = 0; i < ile; i++)
				{
					wartosci[i] = pomocniczy_stos[i];
				}
				delete[] pomocniczy_stos;
			}
		}

		void oproznij_stos()
		{
			ile = 0;
			wartosci = new T[ile];
		}

		void czy_pusty()
		{
			if (ile == 0)
			{
				cout << "Stos jest pusty." << endl;
			}
			else
			{
				cout << "Stos nie jest pusty." << endl;
			}
		}

		void ile_elementow()
		{
			cout << "Na stosie jest " << ile << " elementow." << endl;
		}

		void skopiuj_stos(stos& obiektKlasy)
		{
			ile = obiektKlasy.ile;
			for (int i = 0; i < ile; i++)
			{
				wartosci[i] = obiektKlasy.wartosci[i];
			}
		}
};