/*
methods
int width() const;      - Returns the minimum field width used
int width(int n);       - Sets the minimum field width to n
int fill() const;       - Returns the fill character used
int fill(int ch);       - Sets the fill character to ch

manipulators
setw(int n)             - Sets the minimum field width to n
setfill(int ch)         - Sets the fill character to ch
left                    - Left-aligns output in fields
right                   - Right-aligns output in fields
internal            <---- Left-aligns output of the sign and right-aligns output of the numeric value <-------
*/

#include <iostream> // Declaration of cin, cout
#include <iomanip> // For manipulators being called with arguments.
#include <string>
using namespace std;
int main()
{
    int number = ' ';
    cout << "The white space code is as follows: "
    << number << endl;
    char ch;
    string prompt =
    "\nPlease enter a character followed by "
    " <return>: ";
    cout << prompt;
    cin >> ch; // Read a character
    number = ch;
    cout << "The character " << ch
    << " has code" << number << endl;
    cout << uppercase // For hex-digits
    << " octal decimal hexadecimal\n "
    << oct << setw(8) << number
    << dec << setw(8) << number
    << hex << setw(8) << number << endl;
    return 0;
}