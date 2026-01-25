#include "Chef.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Chef chef("Gordon");

    int saladItems;
    cout << "Count of salad items: ";
    cin >> saladItems;
    chef.makeSalad(saladItems);

    int soupItems;
    cout << "Count of soup items: ";
    cin >> soupItems;
    chef.makeSoup(soupItems);

    ItalianChef italianChef("Mario");

    string pw;
    int flour, water;

    cout << "Password for Italian chef: ";
    cin >> pw;

    cout << "How much flour? ";
    cin >> flour;

    cout << "How much water? ";
    cin >> water;

    italianChef.askSecret(pw, flour, water);

    return 0;
}
