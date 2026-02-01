#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili {
public:
    explicit Pankkitili(const std::string& omistajaNimi);
    virtual ~Pankkitili() = default;

    virtual double getBalance() const;          
    virtual bool deposit(double summa);         
    virtual bool withdraw(double summa);        

protected:
    std::string omistaja;
    double saldo;
};

#endif

