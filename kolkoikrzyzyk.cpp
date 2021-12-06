#include <iostream>

using namespace std;

char tablica[10] = { '0','1','2','3','4','5','6','7','8','9' };
int numerpola;

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

void narysujtablice()
{
    system("cls");
    cout << "   |   |   " << endl << " " << tablica[1] << " | " << tablica[2] << " | " << tablica[3] << " " << endl << "___|___|___" << endl;
    cout << "   |   |   " << endl << " " << tablica[4] << " | " << tablica[5] << " | " << tablica[6] << endl << "___|___|___" << endl;
    cout << "   |   |   " << endl << " " << tablica[7] << " | " << tablica[8] << " | " << tablica[9] << endl << "   |   |   " << endl;
}

bool czywygrał()
{
    if (tablica[1] == tablica[4] && tablica[4] == tablica[7])
    {
        return true;
    }
    else if (tablica[2] == tablica[5] && tablica[5] == tablica[8])
    {
        return true;
    }
    else if (tablica[3] == tablica[6] && tablica[6] == tablica[9])
    {
        return true;
    }
    else if (tablica[1] == tablica[2] && tablica[2] == tablica[3])
    {
        return true;
    }
    else if (tablica[4] == tablica[5] && tablica[5] == tablica[6])
    {
        return true;
    }
    else if (tablica[7] == tablica[8] && tablica[8] == tablica[9])
    {
        return true;
    }
    else if (tablica[1] == tablica[5] && tablica[5] == tablica[9])
    {
        return true;
    }
    else if (tablica[7] == tablica[5] && tablica[5] == tablica[3])
    {
        return true;
    }
    else return false;

}
bool poprawnoscwpisanegoruchu()
{
    if (numerpola <= 9 && numerpola > 0)
    {
        if (tablica[numerpola] == 'x' || tablica[numerpola] == 'o')
        {
            cout << "wybierz inne pole" << endl;
        }
        else 
            return true;
    }
    else cout << "wpisz cyfre od 1 do 9" << endl;
    return false;
}

int main()
{   
    int gracz = 1;
    int liczbaoperacji = 1;
    char znak;
    
    bool wygrana = false;
    bool czyJestKomputer = NULL;
    int liczbaGraczy;

    cout << "wybierz ilość graczy (1 albo 2)" << endl;

    while (true)
    {
        cin >> liczbaGraczy;
        if (liczbaGraczy == 1)
        {
            czyJestKomputer = true;
            break;
        }
        else if (liczbaGraczy == 2)
        {
            czyJestKomputer = false;
            break;
        }
        else
            cout << "wybierz poprawną ilość graczy" << endl;
    }

    while (liczbaoperacji!=10)
    {
        narysujtablice();
        if (liczbaoperacji % 2 == 0)
        {
            gracz = 2;
        }

        else
        {
            gracz = 1;
        }
        znak = (gracz == 1) ? 'o' : 'x';

        cout << "ruch gracza " << gracz << endl;

        while (true && (czyJestKomputer==false || gracz==1))
        {
            while (!(cin >> numerpola))
            {
                cout << "wpisz cyfre od 1 do 9" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            //cin >> numerpola;

            if (poprawnoscwpisanegoruchu())
                break;
        }

        while (true && czyJestKomputer == true && gracz==2)
        {
            numerpola = rand() % 9 + 1;
            if (poprawnoscwpisanegoruchu)
                break;
        }

        tablica[numerpola] = znak;

        wygrana = czywygrał();

        if (wygrana == true)
        {
            narysujtablice();
            cout << "wygrana gracza " << gracz;
            return 0;
        }

        liczbaoperacji++;
    }

    cout << "remis";

    /*int wiek;
    cin >> wiek;
    
    cout << wypiszczypełnoletni(wiek);*/

    /*int wiek;
    cin >> wiek;
    bool czypełnoletni = pełnoletność(wiek);

    cout << czypełnoletni;*/

    /*int n, m, wynik;
    cin >> n >> m;

    cout << dodawanie(n, m) << endl;
    wynik = odejmowanie(n, m);
    cout << wynik << endl;
    mnożenie(n, m);*/

    return 0;
}
