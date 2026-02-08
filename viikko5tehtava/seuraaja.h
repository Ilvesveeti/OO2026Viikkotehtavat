#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>
#include <iostream>

class Seuraaja
{
public:
    explicit Seuraaja(const std::string& nimi);
    std::string getNimi() const;
    void paivitys(const std::string& viesti) const;

    Seuraaja* next = nullptr;

private:
    std::string nimi;
};

#endif
