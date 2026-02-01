#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"

    class Luottotili : public Pankkitili {
public:
    Luottotili(const std::string& omistajaNimi, double luottoRaja);

    double getBalance() const override;   
    bool deposit(double summa) override;  
    bool withdraw(double summa) override; 

private:
    double luottoRaja;
};

#endif

