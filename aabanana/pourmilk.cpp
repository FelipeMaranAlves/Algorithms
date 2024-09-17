#include <fstream>
using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int c1,c2,c3,m1,m2,m3;
    fin >> c1 >> m1;
    fin >> c2 >> m2;
    fin >> c3 >> m3;
    for (int i = 0; i < 100; i++) // 0(1->2) 1(2->3) 2(3->1)
    {
        if (i%3 == 0){
            if (m1+m2 >c2){
                int temp = m2;
                m2 = c2;
                m1 = m1+temp-c2;
            } else {
                m2 += m1;
                m1 = 0;
            }
        } else if (i%3 == 1) {
            if (m2+m3 >c3){
                int temp = m3;
                m3 = c3;
                m2 = m2+temp-c3;
            } else {
                m3 += m2;
                m2 = 0;
            }
        } else {
            if (m3+m1 >c1){
                int temp = m1;
                m1 = c1;
                m3 = m3+temp-c1;
            } else {
                m1 += m3;
                m3 = 0;
            }
        }
    }
    fout << m1 << "\n" << m2 << "\n" << m3 << endl;
    return 0;
}