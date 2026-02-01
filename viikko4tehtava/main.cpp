#include "asiakas.h"
#include <iostream>

int main() {
    Asiakas aapeli("Aapeli", 1000);
    aapeli.showSaldo();
    std::cout << "\n";

    aapeli.talletus(250);
    aapeli.luotonNosto(150);
    aapeli.showSaldo();
    std::cout << "\n";

    Asiakas bertta("Bertta", 1000);
    bertta.showSaldo();
    std::cout << "\n\n";

    
    std::cout << aapeli.getNimi() << "\n";
    aapeli.showSaldo();

 
    aapeli.tiliSiirto(50, bertta);

   
    std::cout << "\n" << bertta.getNimi() << "\n";
    bertta.showSaldo();

    return 0;
}

