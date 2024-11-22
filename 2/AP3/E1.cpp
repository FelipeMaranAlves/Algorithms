#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "As time by ...";
    string s2 = " goes";
    cout << s1 << endl;
    s1.insert(s1.find("by")-1,s2);
    cout << s1 << endl;
    s1.resize(s1.size()-3);
    cout << s1 << endl;
    //  V---- where to input, the size of the input, the substring, the first segment of the substring, the last segument of the substring
    s1.replace(s1.find("time"), 4, "Billy", 0,5 );
    cout << s1 << endl;
    return 0;
}