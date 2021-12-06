#include <iostream>

using namespace std;

int dodawanie(int n, int m)
{
    return n + m;
}

int odejmowanie(int n, int m)
{
    return n - m;
}

void mnożenie(int n, int m)
{
    cout << n * m;
}

bool pełnoletność(int wiek)
{
    return (wiek >= 18) ? true : false;     //podwójne sprawdzenie
}

//bool pełnoletność(int wiek)
//{
//    if (wiek >= 18)
//    {
//        return true;                      //dluzsza wersja tego na gorze
//    }
//    return false;
//}

string wypiszczypełnoletni(int wiek)
{
    return (wiek >= 18) ? "pełnoletni" : "niepełnoletni";
}

    int wiek;
    cin >> wiek;
    
    cout << wypiszczypełnoletni(wiek);

    int wiek;
    cin >> wiek;
    bool czypełnoletni = pełnoletność(wiek);

    cout << czypełnoletni;*/

    int n, m, wynik;
    cin >> n >> m;

    cout << dodawanie(n, m) << endl;
    wynik = odejmowanie(n, m);
    cout << wynik << endl;
    mnożenie(n, m);

    return 0;
}
