#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>
#include "pankkitili.h"
#include "luottotili.h"

class Asiakas {
public:
    Asiakas(const std::string& nimi, double luottoRaja);

    std::string getNimi() const;

    void showSaldo() const;

    bool talletus(double summa);
    bool nosto(double summa);
    bool luotonNosto(double summa);
    bool luotonMaksu(double summa);

    bool tiliSiirto(double summa, Asiakas& vastaanottaja);

private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif
