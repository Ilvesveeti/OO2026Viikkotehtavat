#include "luottotili.h"

Luottotili::Luottotili(const std::string& omistajaNimi, double raja)
    : Pankkitili(omistajaNimi), luottoRaja(raja)
{
    if (luottoRaja < 0.0) luottoRaja = 0.0;
    saldo = 0.0; 
}


double Luottotili::getBalance() const {
    return luottoRaja + saldo; 
}

bool Luottotili::deposit(double summa) {
    if (summa <= 0.0) return false;
    if (saldo >= 0.0) return false; 

    saldo += summa;
    if (saldo > 0.0) saldo = 0.0;  
    return true;
}

bool Luottotili::withdraw(double summa) {
    if (summa <= 0.0) return false;
    if (saldo - summa < -luottoRaja) return false;

    saldo -= summa;
    return true;
}

