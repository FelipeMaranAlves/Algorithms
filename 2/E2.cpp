#include <iostream>
#include <string>

using namespace std;
int main() {
  string ch;
  string word;
  cout<< "Let's go! Press the return key: ";
  getline(cin, ch);
  cout << "Enter a word containing three characters at most: " << endl;
  cin >> word;
  cout << "Your input: " << word << endl;
  return 0;
}
