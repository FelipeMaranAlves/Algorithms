// Reads integral decimal values and
// generates octal, decimal, and hexadecimal output.
#include <iostream> // Declarations of cin, cout and
using namespace std; // manipulators oct, hex, ...
int main()
{
    int number;
    cout << "Please enter an integer: ";
    cin >> number;
    cout << uppercase // for hex-digits
    << " octal \t decimal \t hexadecimal\n "
    << oct << number << " \t "
    << dec << number << " \t "
    << hex << number << endl;
    return 0;
}

//manipulators call the methods setf() and unsetf() by themselves
/*
manipulator

oct             - Octal base
hex             - Hexadecimal base
dec             - Decimal base (by default)
showpos         - Generates a + sign in non-negative numeric output.
noshowpos       - Generates non-negative numeric output without a + sign (by default).
uppercase       - Generates capital letters in hexadecimal output.
nouppercase     - Generates lowercase letters in hexadecimal output (by default).

*/