#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
using namespace std;
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) cout << "*";
	cout << "Autor programu: Simon Dudek\n\n";
	for (int i = 1; i <= 120; i++) cout << "*";
}
void los(int x, int tab[10][10], int pocz, int kon, int kontroler) {
	srand(kontroler);
	if (pocz == 0) {
		kon++;
		for (int i = 0, j = 0; i < x && j < x; i++) {
			tab[j][i] = (pocz + rand() % kon);
			if (i == x - 1) {
				i = -1;
				j++;
			}
		}
	}
	else {
		if (pocz > 0) {
			kon -= pocz - 1;
			for (int i = 0, j = 0; i < x && j < x; i++) {
				tab[j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
			}
		}
		else {
			kon += (pocz * (-1)) + 1;
			for (int i = 0, j = 0; i < x && j < x; i++) {
				tab[j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
			}
		}
	}
}
void dodawanie(int x, int tab1[10][10], int tab2[10][10]) {
	for (int i = 0, j = 0; i < x && j < x; i++) {
		tab1[j][i]+=tab2[j][i];
		if (i == x - 1) {
			i = -1;
			j++;
		}
	}
}
void wyswietl(int x, int tab[10][10]) {
	for (int i = 0, j = 0; i < x && j < x; i++) {
		if (tab[j][i] >= 0 && tab[j][i]<10)
		{
			cout << " " << tab[j][i] << " ";
			if (i == x - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
		else {
			cout << tab[j][i] << " ";
			if (i == x - 1) {
				cout << endl;
				i = -1;
				j++;
			}
		}
	}
}
int main()
{
	int wym, beg, end, mac1[10][10], mac2[10][10], control;
	time_t t;
	control = time(&t);
	setlocale(LC_ALL, "");
	autor();
	cout << "\nMaksymalny rozmiar macierzy to 10x10. ";
	cout << "Podaj wymiar macierzy: ";
	cin >> wym;
	while (wym > 10 || wym < 0)
	{
		cout << "Błędny rozmiar! Proszę ponowownie podać wymiar macierzy: ";
		cin >> wym;
	}
	cout << "Podaj zakres losowanych liczb.\n";
	cout << "Początek: ";
	cin >> beg;
	cout << "Koniec: ";
	cin >> end;
	while (beg >= end) {
		cout << "Błędne wpisanie zakresu! Aby zdefiniować liczba pocątkowa musi być mniejsza niż liczba końcowa!\n";
		cout << "Początek: ";
		cin >> beg;
		cout << "Koniec: ";
		cin >> end;
	}
	cout << endl;
	los(wym, mac1, beg, end, control);
	control = time(&t);
	los(wym, mac2, beg, end, control);
	cout << "\n\n\nPierwsza macierz: \n\n";
	wyswietl(wym, mac1);
	cout << "\n\n\nDruga macierz: \n\n";
	wyswietl(wym, mac2);
	dodawanie(wym, mac1, mac2);
	cout << "\n\n\nSuma macierzy 1 i 2: \n\n";
	wyswietl(wym, mac1);
	system("pause");
	return 0;
}