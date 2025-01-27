#include <iostream>
#include "fraction.h"

int main() {
    try {
        // Testando o construtor Fraction(int, int)
        Fraction frac1(3, 4);
        Fraction frac2(7, 2);

        // Convertendo Fraction para double
        std::cout << "Fraction frac1: 3/4 = " << frac1.to_double() << "\n";
        std::cout << "Fraction frac2: 7/2 = " << frac2.to_double() << "\n";

        // Atribuindo int para Fraction usando o construtor
        Fraction frac3 = 5; // Deve criar a fração 5/1
        std::cout << "Fraction frac3: 5 = " << frac3.to_double() << "\n";

        // Operações aritméticas com Fraction
        Fraction frac4 = Fraction(1, 2) + Fraction(1, 3); // Supondo que você tenha um operador +
        std::cout << "Addition (1/2 + 1/3): " << frac4.to_double() << " as double\n";

        Fraction frac5 = Fraction(2, 5) * Fraction(3, 7); // Supondo que você tenha um operador *
        std::cout << "Multiplication (2/5 * 3/7): " << frac5.to_double() << " as double\n";

        // Testando divisão
        Fraction frac6 = Fraction(5, 6) / Fraction(1, 3); // Supondo que você tenha um operador /
        std::cout << "Division (5/6 / 1/3): " << frac6.to_double() << " as double\n";

        // Testando erro de denominador zero
        Fraction frac7(1, 0); // Deve lançar exceção
    }
    catch (const char* e) {
        std::cerr << "Erro: " << e << "\n";
    }

    return 0;
}
