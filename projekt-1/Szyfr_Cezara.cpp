/*  Przesuniecie o 3 pozycje w alfabecie
    bierzemy pod uwage male i duze litery oraz liczby   */

#include <iostream>
#include <string>
using namespace std;

inline int sprawdz(char znak)
{
    //jesli jest mala litera
	if(znak >= 'a' && znak <= 'z') return 0;
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
        if(spr < 2)
        {
            if(spr == 0)
            {
                a = 'a'; z = 'z';
                kl = klucz % 26;
            }
            else
            {
                a = 'A'; z = 'Z';
                kl = klucz % 26;
            }
        }
        if(spr == 2)
        {
            a = '0'; z = '9';
            kl = klucz % 10;
        }

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
    }
}



int main()
{
    string haslo = "WiTaM1290";
    cout <<"Podane haslo: " << haslo << endl;
    szyfrCezara(1000, haslo);
    cout <<"Po zaszyfowaniu dla 1000: " << haslo << endl;
   //szyfrCezara(-256, haslo);
   //cout <<"Po zaszyfowaniu dla -256: " << haslo << endl;


    return 0;
}







