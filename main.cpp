#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int karta()
{
	return rand() % 52 + 2;
}

bool czywylosowana(int tab[], int liczba, int dl)
{
	int i = 0;
	do
	{
		if (tab[i] == liczba)
			return true;
		i++;
	} while (i < dl + 1);
	return false;
}

void poczatek(int z[], int g[], int dl, int ilosc)
{
	int s = 0;
	int i = 0;
	do
	{
		s = karta();
		if (czywylosowana(z, s, dl) == false)
		{
			g[i] = s;
			i++;
			dl++;
			z[dl] = s;
		}

	} while (i < ilosc);
}

int kartapoczatkowa()
{
	int s = 0;
	s = karta();
	return s;
}

string zamiana(int l)
{
	string figura = " ";
	int dwa = l - 2;
	int trzy = l - 3;
	int piec = l - 5;
	if (dwa % 4 == 0 or dwa == 0)
		figura = "pik";
	if (l % 4 == 0)
		figura = "karo";
	if (trzy % 4 == 0 or trzy == 0)
		figura = "kier";
	if (piec % 4 == 0 or piec == 0)
		figura = "trefl";
	return figura;
}

int zamiana2(int l, string z)
{
	if (z == "pik")
		l = ((l - 2) / 4) + 2;
	if (z == "kier")
		l = ((l - 3) / 4) + 2;
	if (z == "karo")
		l = ((l - 4) / 4) + 2;
	if (z == "trefl")
		l = ((l - 5) / 4) + 2;
	return l;
}

void runda(int tab[], int ilekart, string ksf, int ksc)
{
	string figura;
	int cyfra;
	for (int i = 0; i < ilekart; i++)
	{
		cout << i + 1; cout << ". ";
		figura = zamiana(tab[i]);
		cout << figura;
		cout << " ";
		cyfra = zamiana2(tab[i], figura);
		if (cyfra == 11)
			cout << "jopek";
		else if (cyfra == 12)
			cout << "dama";
		else if (cyfra == 13)
			cout << "krol";
		else if (cyfra == 14)
			cout << "as";
		else
			cout << cyfra;
		if (figura == ksf or cyfra == ksc or cyfra == 12 or ksc == 12)
			cout << " mozna zagrac";
		cout << endl;
	}
}

void kns(string knf, int knc)
{
	string figura;
	int cyfra;
	figura = knf;
	cout << figura;
	cout << " ";
	cyfra = knc;
	if (cyfra == 11)
		cout << "jopek";
	else if (cyfra == 12)
		cout << "dama";
	else if (cyfra == 13)
		cout << "krol";
	else if (cyfra == 14)
		cout << "as";
	else
		cout << cyfra;
}

void draw(int z[], int g[], int dl, int ile, int iledobrac)
{
	int s = 0;
	int i = 0;
	do
	{
		s = karta();
		if (czywylosowana(z, s, dl) == false)
		{
			g[ile] = s;
			i++;
			z[dl] = s;
		}

	} while (i < iledobrac);
}


void play(int tab[], int k, string kf, int kc, int ilekartwrence)
{
	bool y = false;
	do
	{
		if (zamiana(tab[k]) == kf or zamiana2(tab[k], zamiana(tab[k])) == kc or zamiana2(tab[k], zamiana(tab[k])) == 12 or kc == 12)
		{
			kf = zamiana(tab[k]);
			kc = zamiana2(tab[k], zamiana(tab[k]));
			for (int i = 0; i < ilekartwrence - 1; i++)
			{
				if (i >= k)
				{
					tab[i] = tab[i + 1];
				}
			}
			y = true;
		}
		else
			cout << "nie mozesz zagrac tej karty" << endl;
	} while (y = false);

}


int main()
{
	int dlugosc = 0;
	int juzdobrane[52];
	int iloscgraczy = 0;
	bool czyokgraczy = false;
	int koniec = 0;
	bool makao1 = false; bool makao2 = false; bool makao3 = false; bool makao4 = false;
	int gracz1[52]; int gracz2[52]; int gracz3[52]; int gracz4[52];
	int kartanastole; string kartanastolefigura; int kartanastolecyfra;
	int zastepczacyfra; string zastepczafigura;
	int ilekartwrence1 = 5; int ilekartwrence2 = 5; int ilekartwrence3 = 5; int ilekartwrence4 = 5;
	string dzialaniegracza;
	int ktorarunda = 1;
	int karta;
	srand(time(NULL));

	do
	{
		cout << "podaj ilosc graczy od 2 do 4" << endl;
		cin >> iloscgraczy;
		if (iloscgraczy == 2 or iloscgraczy == 3 or iloscgraczy == 4)
		{
			czyokgraczy = true;
		}
	} while (czyokgraczy == false);
	koniec = iloscgraczy;
	system("cls");

	do
	{
		kartanastole = kartapoczatkowa();
		kartanastolefigura = zamiana(kartanastole);
		kartanastolecyfra = zamiana2(kartanastole, kartanastolefigura);
	} while (kartanastolecyfra > 10);
	juzdobrane[0] = kartanastole;

	poczatek(juzdobrane, gracz1, dlugosc, ilekartwrence1);
	dlugosc += 5;
	poczatek(juzdobrane, gracz2, dlugosc, ilekartwrence2);
	dlugosc += 5;
	if (iloscgraczy == 3 or iloscgraczy == 4)
	{
		poczatek(juzdobrane, gracz3, dlugosc, ilekartwrence3);
		dlugosc += 5;
	}
	if (iloscgraczy == 4)
	{
		poczatek(juzdobrane, gracz4, dlugosc, ilekartwrence4);
		dlugosc += 5;
	}


	do
	{
		bool y = false;
		if (makao1 == false && ilekartwrence1 == 1)
		{

			for (int i = 0; i <= 5; i++)
			{
				draw(juzdobrane, gracz1, dlugosc, ilekartwrence1, 1);
				ilekartwrence1 += 1;
				dlugosc += 1;
			}

		}
		if (makao2 == false && ilekartwrence2 == 1)
		{

			for (int i = 0; i <= 5; i++)
			{
				draw(juzdobrane, gracz2, dlugosc, ilekartwrence2, 1);
				ilekartwrence2 += 1;
				dlugosc += 1;
			}

		}
		if (makao3 == false && ilekartwrence3 == 1)
		{
			for (int i = 0; i <= 5; i++)
			{
				draw(juzdobrane, gracz3, dlugosc, ilekartwrence3, 5);
				ilekartwrence3 += 5;
				dlugosc += 5;
			}
		}
		if (makao4 == false && ilekartwrence4 == 1)
		{
			for (int i = 0; i <= 5; i++)
			{
				draw(juzdobrane, gracz4, dlugosc, ilekartwrence4, 5);
				ilekartwrence4 += 5;
				dlugosc += 5;
			}
		}
		if (dzialaniegracza != "cheat")
		{
			system("cls");
		}

		cout << "karta lezaca na stole: " << endl;
		cout << endl;
		kns(kartanastolefigura, kartanastolecyfra);
		cout << endl;
		cout << endl;
		cout << "tura gracza nr: ";
		cout << ktorarunda << endl;
		cout << "twoje karty: " << endl;
		if (ktorarunda == 1)
		{
			runda(gracz1, ilekartwrence1, kartanastolefigura, kartanastolecyfra);
		}
		if (ktorarunda == 2)
		{
			runda(gracz2, ilekartwrence2, kartanastolefigura, kartanastolecyfra);
		}
		if (ktorarunda == 3)
		{
			runda(gracz3, ilekartwrence3, kartanastolefigura, kartanastolecyfra);
		}
		if (ktorarunda == 4)
		{
			runda(gracz4, ilekartwrence4, kartanastolefigura, kartanastolecyfra);
		}
		cout << endl;
		cout << "wybierz swoje dzialanie: " << endl;
		cout << "komenda quit konczy program " << endl;
		cout << "komenda cheat pokaze karty wszystkich graczy" << endl;
		cout << "komenda play umozliwi Ci zagranie karty" << endl;
		cout << "komenda draw zakonczy twoja ture dobraniem karty" << endl;
		cout << "wpisz komende makao gdy zostanie ci ostatnia karta (bezposrednio przed zagraniem przedostatniej)" << endl;
		cin >> dzialaniegracza;
		if (dzialaniegracza == "quit")
			return 0;
		if (dzialaniegracza == "cheat")
		{
			system("cls");
			cout << "karty gracza nr 1:" << endl;
			runda(gracz1, ilekartwrence1, kartanastolefigura, kartanastolecyfra);
			cout << endl;
			cout << "karty gracza nr 2:" << endl;
			runda(gracz2, ilekartwrence2, kartanastolefigura, kartanastolecyfra);
			cout << endl;
			if (iloscgraczy == 3 or iloscgraczy == 4)
			{
				cout << "karty gracza nr 3:" << endl;
				runda(gracz3, ilekartwrence3, kartanastolefigura, kartanastolecyfra);
				cout << endl;
			}
			if (iloscgraczy == 4)
			{
				cout << "karty gracza nr 4:" << endl;
				runda(gracz4, ilekartwrence4, kartanastolefigura, kartanastolecyfra);
				cout << endl;
			}
		}
		if (dzialaniegracza == "play")
		{
			do
			{
				cout << "wpisz nr karty ktora chcesz zagrac lub wyjdz wpisujac 0" << endl;
				cin >> karta;
				if (karta == 0)
				{
					ktorarunda -= 1;
					break;
				}
				karta -= 1;
				if (ktorarunda == 1)
				{
					if (zamiana(gracz1[karta]) == kartanastolefigura or zamiana2(gracz1[karta], zamiana(gracz1[karta])) == kartanastolecyfra or zamiana2(gracz1[karta], zamiana(gracz1[karta])) == 12 or kartanastolecyfra == 12)
					{
						y = true;
						kartanastolefigura = zamiana(gracz1[karta]);
						kartanastolecyfra = zamiana2(gracz1[karta], zamiana(gracz1[karta]));
						play(gracz1, karta, kartanastolefigura, kartanastolecyfra, ilekartwrence1);
						ilekartwrence1 -= 1;
					}

				}
				if (ktorarunda == 2)
				{
					if (zamiana(gracz2[karta]) == kartanastolefigura or zamiana2(gracz2[karta], zamiana(gracz2[karta])) == kartanastolecyfra or zamiana2(gracz2[karta], zamiana(gracz2[karta])) == 12 or kartanastolecyfra == 12)
					{
						y = true;
						kartanastolefigura = zamiana(gracz2[karta]);
						kartanastolecyfra = zamiana2(gracz2[karta], zamiana(gracz2[karta]));
						play(gracz2, karta, kartanastolefigura, kartanastolecyfra, ilekartwrence2);
						ilekartwrence2 -= 1;
					}

				}
				if (ktorarunda == 3)
				{
					if (zamiana(gracz3[karta]) == kartanastolefigura or zamiana2(gracz3[karta], zamiana(gracz3[karta])) == kartanastolecyfra or zamiana2(gracz3[karta], zamiana(gracz3[karta])) == 12 or kartanastolecyfra == 12)
					{
						y = true;
						kartanastolefigura = zamiana(gracz3[karta]);
						kartanastolecyfra = zamiana2(gracz3[karta], zamiana(gracz3[karta]));
						play(gracz3, karta, kartanastolefigura, kartanastolecyfra, ilekartwrence3);
						ilekartwrence3 -= 1;
					}
				}
				if (ktorarunda == 4)
				{
					if (zamiana(gracz4[karta]) == kartanastolefigura or zamiana2(gracz4[karta], zamiana(gracz4[karta])) == kartanastolecyfra or zamiana2(gracz4[karta], zamiana(gracz4[karta])) == 12 or kartanastolecyfra == 12)
					{
						y = true;
						kartanastolefigura = zamiana(gracz4[karta]);
						kartanastolecyfra = zamiana2(gracz4[karta], zamiana(gracz4[karta]));
						play(gracz4, karta, kartanastolefigura, kartanastolecyfra, ilekartwrence4);
						ilekartwrence4 -= 1;
					}
				}

			} while (y == false);
			ktorarunda += 1;
		}
		if (dzialaniegracza == "draw")
		{
			if (ktorarunda == 1)
			{
				draw(juzdobrane, gracz1, dlugosc, ilekartwrence1, 1);
				ilekartwrence1 += 1;
				dlugosc += 1;
				makao1 = false;
			}
			if (ktorarunda == 2)
			{
				draw(juzdobrane, gracz2, dlugosc, ilekartwrence2, 1);
				ilekartwrence2 += 1;
				dlugosc += 1;
				makao2 = false;
			}
			if (ktorarunda == 3)
			{
				draw(juzdobrane, gracz3, dlugosc, ilekartwrence3, 1);
				ilekartwrence3 += 1;
				dlugosc += 1;
				makao3 = false;
			}
			if (ktorarunda == 4)
			{
				draw(juzdobrane, gracz4, dlugosc, ilekartwrence4, 1);
				ilekartwrence4 += 1;
				dlugosc += 1;
				makao4 = false;
			}
			ktorarunda += 1;
		}
		if (dzialaniegracza == "makao")
		{
			if (ktorarunda == 1 && ilekartwrence1==2)
			{
				makao1 = true;
			}
			if (ktorarunda == 2 && ilekartwrence2==2)
			{
				makao2 = true;
			}
			if (ktorarunda == 3 && ilekartwrence3==2)
			{
				makao3 = true;
			}
			if (ktorarunda == 4 && ilekartwrence4==2)
			{
				makao4 = true;
			}
		}

		if (ilekartwrence1 == 0 or ilekartwrence2 == 0 or ilekartwrence3 == 0 or ilekartwrence4 == 0)
		{
			ktorarunda += 1;
		}
		if (ktorarunda == iloscgraczy + 1)
		{
			ktorarunda = 1;
		}
		if (ilekartwrence1 == 0 or ilekartwrence2 == 0 or ilekartwrence3 == 0 or ilekartwrence4 == 0)
		{
			koniec -= 1;
		}
	} while (koniec > 1);
}
