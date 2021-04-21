#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void homofon2(string haslo_praw, string haslo_falsz)
{
    //generowanie tablicy liczb losowych i 2D
    srand(time(NULL));
    int alf[26][26];

    int liczby[676];
    for(int i = 0; i<=676; i++)
    {
        while(1)
        {
            int a;
            int b = 0;  //kontrola petli while
            a = rand()%700 + 1;
            for(int k = 0; k <= 676; k++)
            {

                if(liczby[k] == a)
                {
                    b = 1;
                    break;
                }

            }

            if(b == 1)
                continue;
            else if(b == 0)
            {
                liczby[i] = a;
                break;
            }
        }
    }

    //umieszczanie wylosowanych liczb w tablicy 2D
    int k = 0;
    for(int i = 0; i <26; i++)
    {
        for(int j = 0; j <26; j++)
        {
            alf[i][j] = liczby[k];
            k++;
        }
    }

    //szyfrowanie
    int wiersz;
    int kolumna;

    int rozmiar = haslo_praw.size();
    int szyfr[rozmiar];

    cout<<"szyfr: ";
    for(int i = 0; i < haslo_praw.size(); i++)
    {
        wiersz = (int)haslo_praw[i] - 65;
        kolumna = (int)haslo_falsz[i] - 65;

        szyfr[i] = alf[wiersz][kolumna];
        cout<<szyfr[i]<<" ";
        int a = szyfr[i];

    }
    cout<<endl;

    string tekst_praw;
    string tekst_falsz;


    for(int i = 0; i<5; i++)
    {
        int szukana = szyfr[i];
        char litera1;
        char litera2;

        for(int j=0; j<26; j++)
        {
            for(int k=0; k<26; k++)
            {
                if(alf[j][k] == szukana)
                {
                    litera1 = j + 65;
                    litera2 = k + 65;
                    tekst_praw = tekst_praw + litera1;
                    tekst_falsz = tekst_falsz + litera2;

                    break;
                }
            }
        }
    }
    cout<<"odszyfrowane prawdziwe: "<<tekst_praw<<endl;
    cout<<"odszyfrowane falszywe: "<<tekst_falsz<<endl;
}

int main()
{
    string haslo_praw = "LALKA";
    string haslo_falsz = "KATAR";

    homofon2(haslo_praw, haslo_falsz);

    return 0;
}
