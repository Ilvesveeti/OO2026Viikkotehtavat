#include "Chef.h"
#include <iostream>
#include <algorithm>

using namespace std;



Chef::Chef(string name) : chefName(name)
{
    cout << "Chef " << chefName << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int items)
{
    int portions = items / 5;
    cout << "Chef " << chefName << " with "
         << items << " items can make salad "
         << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int items)
{
    int portions = items / 3;
    cout << "Chef " << chefName << " with "
         << items << " items can make soup "
         << portions << " portions" << endl;
    return portions;
}


ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout << "ItalianChef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << " destruktori" << endl;
}

bool ItalianChef::askSecret(string pw, int flour, int water)
{
    if (pw.compare(password) == 0)
    {
        cout << "Password ok!" << endl;

        int pizzas = makePizza(flour, water);

        cout << "ItalianChef " << chefName << " with "
             << flour << " flour and "
             << water << " water can make "
             << pizzas << " pizzas" << endl;

        return true;
    }
    return false;
}

int ItalianChef::makePizza(int flour, int water)
{
    return min(flour / 5, water / 5);
}
