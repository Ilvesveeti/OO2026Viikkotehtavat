#ifndef CHEF_H
#define CHEF_H

#include <string>
using namespace std;

class Chef
{
public:
    Chef(string name);
    ~Chef();

    string getName();
    int makeSalad(int items);
    int makeSoup(int items);

protected:
    string chefName;
};

class ItalianChef : public Chef
{
public:
    ItalianChef(string name);
    ~ItalianChef();

    bool askSecret(string pw, int flour, int water);

private:
    int makePizza(int flour, int water);
    const string password = "pizza";
};

#endif
