//Rozszyfrowac plik1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Szyfr Cezara **************************************************************
inline int sprawdz(char znak)
{

	//jesli jest duza litera
	if(znak >= 'A' && znak <= 'Z') return 1;
	//liczba
	if(znak >='0' && znak<= '9') return 2;
	//inne
	return 3;
}

void szyfrCezara(int klucz, string &haslo)
{
    int rozmiar = haslo.length();
    char a, z;
    int spr;
    int kl = klucz;

    //sprawdzenie czy haslo miesci sie w zakresie
    for(int i = 0; i < rozmiar; i++)
    {
        spr = sprawdz(haslo[i]); //sprawdza wielkosci liter albo czy to cyfry
        if(spr == 1)
        {
            a = 'A'; z = 'Z';
            kl = klucz % 26;

        }
        if(spr == 2)
        {
            a = '0'; z = '9';
            kl = klucz % 10;
        }
        //cout << "klucz: " << klucz << endl;
        //cout <<i <<": "<< haslo[i] <<endl;
        if(spr == 3)
        {
           continue;
        }

        if(kl >= 0)
        {
            if(haslo[i] - kl >= a)
                haslo[i] = haslo[i] - kl;
            else if(haslo[i] - kl < a)
                haslo[i] = haslo[i] - kl + (z - a + 1);
                // (z - a + 1) liczba elementów (liter, cyfr)
        }
        if(kl < 0)
        {
            if(haslo[i] - kl <= z)
                haslo[i] = haslo[i] - kl;
            else if(haslo[i] - kl > z)
                haslo[i] = haslo[i] - kl - (z - a + 1);
        }
       //cout<< haslo[i]<<endl;
    }
}
// **************************************************************************

int main()
{
    //otwarcie pliku
    fstream plik;
    string linia;
    vector <string> dane; //tablica do ktorej wczytuje dane

    plik.open("plik1.txt", ios::in);
    if(plik.good() == true)
    {
        cout<< "Otwarto plik" <<endl;

        //pobieranie danych
        int i = 0;
        while(!plik.eof())
        {
            getline(plik, linia);
            dane.push_back(linia);  //linie danych wpisywane do tablicy
            cout<<dane[i]<<endl;
            i++;
        }
        plik.close();
    }
    cout<<"********************************************\n"<<endl;

    //sprawdzanie kluczy pokolei

    for(int i = -26; i<=0; i++)
    {
        string linia_danych = dane[0];
        szyfrCezara(i,linia_danych);
        cout<<"klucz: "<< i << " wynik: "<< linia_danych<< endl;
    }

    return 0;
}
