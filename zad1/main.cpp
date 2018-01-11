#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::fstream plik;
    std::string dane;
    std::ofstream out;
    std::vector<int> cyfry;
    int a;
    plik.open( "in1.txt", std::ios::in | std::ios::out );
    std::fstream plik( "out1.txt", std::ios::out );
    if( plik.good() == true )
    {
        getline( plik, dane );
        if (dane=="==") {}
        else
        {
            a=dane[0];
            if (a<=57 && a>=49) cyfry.push_back(a);
            


        }

    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}