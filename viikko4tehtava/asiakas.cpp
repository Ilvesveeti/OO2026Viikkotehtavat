#include "asiakas.h"
#include <iostream>
#include <iomanip>

Asiakas::Asiakas(const std::string& nimi_, double raja)
    : nimi(nimi_), kayttotili(nimi_), luottotili(nimi_, raja)
{
    std::cout << "Pankkitili luotu " << nimi << ":lle\n";
    std::cout << "Luottotili luotu " << nimi << ":lle, luottoraja "
              << std::fixed << std::setprecision(0) << raja << "\n";
    std::cout << "Asiakkuus luotu " << nimi << "\n";
}

std::string Asiakas::getNimi() const {
    return nimi;
}

void Asiakas::showSaldo() const {
    std::cout << "Kayttotilin saldo " << std::fixed << std::setprecision(0)
    << kayttotili.getBalance() << "\n";
    std::cout << "Luottotilin saldo " << std::fixed << std::setprecision(0)
              << luottotili.getBalance() << "\n";
}

bool Asiakas::talletus(double summa) {
    if (kayttotili.deposit(summa)) {
        std::cout << "Pankkitili: talletus " << std::fixed
                  << std::setprecision(0) << summa << " tehty\n";
        return true;
    }
    return false;
}

bool Asiakas::nosto(double summa) {
    if (kayttotili.withdraw(summa)) {
        std::cout << "Pankkitili: nosto " << std::fixed
                  << std::setprecision(0) << summa << " tehty\n";
        return true;
    }
    return false;
}

bool Asiakas::luotonNosto(double summa) {
    if (luottotili.withdraw(summa)) {
        std::cout << "Luottotili: nosto " << std::fixed
                  << std::setprecision(0) << summa
                  << " tehty, luottoa jaljella "
                  << luottotili.getBalance() << "\n";
        return true;
    }
    return false;
}

bool Asiakas::luotonMaksu(double summa) {
    if (luottotili.deposit(summa)) {
        std::cout << "Luottotili: maksu " << std::fixed
                  << std::setprecision(0) << summa << " tehty\n";
        return true;
    }
    return false;
}

bool Asiakas::tiliSiirto(double summa, Asiakas& vastaanottaja) {
    if (summa <= 0.0) return false;

    std::cout << "Pankkitili: " << nimi << " siirtaa "
              << std::fixed << std::setprecision(0) << summa
              << " " << vastaanottaja.nimi << ":lle\n";

    if (!kayttotili.withdraw(summa)) return false;
    vastaanottaja.kayttotili.deposit(summa);

    return true;
}
