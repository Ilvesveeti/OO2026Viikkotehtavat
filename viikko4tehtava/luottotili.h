#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"

    class Luottotili : public Pankkitili {
public:
    Luottotili(const std::string& omistajaNimi, double luottoRaja);

    double getBalance() const override;   // "luottoa jaljella"
    bool deposit(double summa) override;  // velanmaksu
    bool withdraw(double summa) override; // luotonosto

private:
    double luottoRaja;
};

#endif
