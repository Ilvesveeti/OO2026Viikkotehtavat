#include "seuraaja.h"

Seuraaja::Seuraaja(const std::string& nimi) : nimi(nimi)
{
    std::cout << "Luodaan seuraaja " << this->nimi << std::endl;
}

std::string Seuraaja::getNimi() const
{
    return nimi;
}

void Seuraaja::paivitys(const std::string& viesti) const
{
    std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << std::endl;
}
