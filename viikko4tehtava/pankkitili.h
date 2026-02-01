#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili {
public:
    explicit Pankkitili(const std::string& omistajaNimi);
    virtual ~Pankkitili() = default;

    virtual double getBalance() const;          // Kayttotilin saldo (rahana)
    virtual bool deposit(double summa);         // talletus
    virtual bool withdraw(double summa);        // nosto

protected:
    std::string omistaja;
    double saldo;
};

#endif
