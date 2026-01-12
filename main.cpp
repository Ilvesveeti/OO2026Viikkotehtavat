#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum)
{
    int arvottuLuku = rand() % maxnum + 1;

    int arvaus;
    int laskuri = 0;

    while (true) {
        cout << "Arvaa luku (1-" << maxnum << "): ";
        cin >> arvaus;
        laskuri++;

        if (arvaus < arvottuLuku) {
            cout << "Liian pieni\n";
        }
        else if (arvaus > arvottuLuku) {
            cout << "Liian suuri\n";
        }
        else {
            cout << "Oikein!\n";
            break;
        }
    }

    return laskuri;
}

int main()
{
    srand(time(nullptr));

    int arvauksia = game(40);

    cout << "Arvauksia yhteensa: " << arvauksia << endl;

    return 0;
}

