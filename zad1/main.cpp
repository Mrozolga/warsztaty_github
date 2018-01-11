#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

int main() {
    std::fstream plik;
    std::fstream out;
    std::string dane;
    std::vector<int> cyfry;
    int a, wynik = 0;
    plik.open("in1.txt", std::ios::in | std::ios::out);
    out.open("out1.txt", std::ios::out);
    while (plik.good() == true) {
        getline(plik, dane);

        a = dane[0] - 48;
        if (dane == "==") {
            return 0;
        } else if (a <= 9 && a >= 0) cyfry.push_back(a);
        else if (dane == "=") {
            out << wynik;
            std::cout << wynik;
            wynik = 0;
        } else {
            switch (dane[0]) {
                case '+':
                    if (cyfry.size()==1) cyfry.push_back(0);
                    wynik = cyfry[cyfry.size() - 2] + cyfry[cyfry.size() - 1];
                    cyfry.pop_back();
                    cyfry.pop_back();
                    cyfry.push_back(wynik);
                    break;
                case '-':
                    if (cyfry.size()==1) cyfry.push_back(0);
                    wynik = cyfry[cyfry.size() - 2] - cyfry[cyfry.size() - 1];
                    cyfry.pop_back();
                    cyfry.pop_back();
                    cyfry.push_back(wynik);
                    break;
            }
        }
    }
}