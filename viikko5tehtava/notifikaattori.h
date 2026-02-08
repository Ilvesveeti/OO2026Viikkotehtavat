#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <string>
#include <iostream>
#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();

    void lisaa(Seuraaja* seuraaja);
    void poista(Seuraaja* seuraaja);
    void tulosta() const;
    void postita(const std::string& viesti) const;

private:
    Seuraaja* seuraajat = nullptr;
};

#endif
