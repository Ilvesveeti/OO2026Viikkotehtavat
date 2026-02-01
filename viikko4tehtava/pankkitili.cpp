#include "pankkitili.h"

Pankkitili::Pankkitili(const std::string& omistajaNimi)
    : omistaja(omistajaNimi), saldo(0.0) {}

double Pankkitili::getBalance() const {
    return saldo;
}

bool Pankkitili::deposit(double summa) {
    if (summa <= 0.0) return false;
    saldo += summa;
    return true;
}

bool Pankkitili::withdraw(double summa) {
    if (summa <= 0.0) return false;
    if (summa > saldo) return false;   
    saldo -= summa;
    return true;
}

