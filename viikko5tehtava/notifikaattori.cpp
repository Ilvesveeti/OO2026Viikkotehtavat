#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    std::cout << "Luodaan notifikaattori" << std::endl;
}

void Notifikaattori::lisaa(Seuraaja* seuraaja)
{
    if (seuraaja == nullptr) return;

    std::cout << "Notifikaattori lisaa seuraajan " << seuraaja->getNimi() << std::endl;


    seuraaja->next = seuraajat;
    seuraajat = seuraaja;
}

void Notifikaattori::poista(Seuraaja* seuraaja)
{
    if (seuraaja == nullptr) return;

    Seuraaja* nykyinen = seuraajat;
    Seuraaja* edellinen = nullptr;

    while (nykyinen != nullptr)
    {
        if (nykyinen == seuraaja)
        {
            std::cout << "Notifikaattori poistaa seuraajan " << seuraaja->getNimi() << std::endl;

            if (edellinen != nullptr)
            {
                edellinen->next = nykyinen->next;
            }
            else
            {
                // poistetaan head
                seuraajat = nykyinen->next;
            }


            nykyinen->next = nullptr;
            return;
        }

        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }


    std::cout << "Notifikaattori ei loytanyt seuraajaa "
              << seuraaja->getNimi() << " listasta" << std::endl;
}

void Notifikaattori::tulosta() const
{
    std::cout << "Notifikaattorin seuraajat:" << std::endl;

    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr)
    {
        std::cout << "Seuraaja " << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(const std::string& viesti) const
{
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;

    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr)
    {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
