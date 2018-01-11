#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


int main() {
    std::fstream plik;
    std::fstream out;
    std::string dane;
    std::vector<long long> cyfry;
    std::vector<char> znak;

    long long a, wynik = 0;
    plik.open("in1.txt", std::ios::in | std::ios::out);
    out.open("out1.txt", std::ios::out);
    while (plik.good() == true) {
        getline(plik, dane);
        a = std::stoll(dane);
        if (dane == "==") {
            return 0;
        } else if (a <= 9 && a >= 0) cyfry.push_back(a);
        else if (dane[0] == 43 || dane[0] == 45) {
            znak.push_back(dane[0]);


        } else {
            while (znak.size() != 0) {
                switch (znak[znak.size() - 1]) {
                    case '+':
                        wynik = cyfry[cyfry.size() - 2] + cyfry[cyfry.size() - 1];
                        cyfry.pop_back();
                        cyfry.pop_back();
                        cyfry.push_back(wynik);
                        break;
                    case '-':
                        wynik = cyfry[cyfry.size() - 2] - cyfry[cyfry.size() - 1];
                        cyfry.pop_back();
                        cyfry.pop_back();
                        cyfry.push_back(wynik);
                        break;
                }
                znak.pop_back();
            }
            out << wynik << std::endl;
            std::cout << wynik;
            wynik = 0;

        }
    }
}
