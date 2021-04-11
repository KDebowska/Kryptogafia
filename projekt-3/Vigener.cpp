//Szyfr Vigenera

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void szyfrVigenera(string haslo, string tekst)
{
    // generowanie alfabetow do szyfrowania
    char alfabet[91][91];
    for(int i = 0; i < 91; i++)
    {
        for(int j = 0; j < 91; j++)
        {
            alfabet[i][j] = 0;
        }

    }
    for(int i = 65; i < 91; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            char k = i + j;
            if(k<=90)
                alfabet[i][j] = k;
            if(k>90)
            {
                k = k - 26;
                alfabet[i][j] = k;
            }
        }
    }


    //sprawdzanie powtarzalnosci liter w hasle i usuwanie powtarzajacych sie liter
    char tab[5];
    for(int i = 0; i<5; i++)
    {
        tab[i] = 0;
    }
    string haslo2;
    for(int i = 0; i<=haslo.length(); i++)
    {
        tab[i] = haslo[i];

        for(int j=i+1; j<= haslo.length(); j++)
        {
            if(tab[i]==haslo[j])
                tab[i] = 0;
        }

        if(tab[i]==0)
            continue;
        else
            haslo2 = haslo2 + tab[i];
    }

    //szyfrowanie
    int klucz = 0;
    char znak;
    string tekst2;
    for(int i=0; i<tekst.length(); i++)
    {
        int wiersz, kolumna;
        znak = tekst[i];
        kolumna = znak - 65;
        wiersz = haslo2[klucz];
        tekst2 = tekst2 + alfabet[wiersz][kolumna];

        if(klucz < haslo2.length()-1)
            klucz++;
        else
            klucz = 0;
    }

    cout<<tekst2;

}

int main()
{
    string haslo = "KOKOS";
    string tekst = "KRYPTOGRAFIA";
    cout<<"Przed zaszyfrowaniem: "<<tekst<<endl;
    cout<<"Po zaszyfrowaniu: ";
    szyfrVigenera(haslo,tekst);
    cout<<endl;
    return 0;
}












