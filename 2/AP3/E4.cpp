#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename E>
class AList
{
private:
    int max;
    int used;
    int cursor;
    E* adress;
public:
    AList(int maxx = 10){
        max = maxx;
        used = 0;
        cursor = 0;
        adress = new E[max];
    }
    ~AList() {delete [] adress;}

    void Upsize(){ //used = max
        max *= 2;
        E* temp = new E[max];
        for (int i = 0; i < max/2; i++)
        {
            temp[i] = adress[i];
        }
        adress = temp;
        delete [] temp;
    }

    /*
    void Upsize(){ //used = max
        max *= 2;
        E* temp = this->adress;
        this->adress = new E[max];
        for (int i = 0; i < max/2; i++)
        {
            adress[i] = temp[i];
        }
        delete [] temp;
    }
    */

    void Downsize(){//might cause some issues with memory cuz idk if the for each will stop when there are no more items to be read
        max = (max/2);
        E* temp = new E[max];
        int i = 0;
        for (int i = 0; i < used; i++)
        {
            temp[i] = adress[i];
        }
        adress = temp;
        delete [] temp;
    }

    void clear(){
        adress = new E[max];
        used = 0;
        cursor = 0;
    }
    
    void insert(E item){ //cursor has it's position 0->(max-1)
        if (used == max) {this->Upsize();} // [a,a,a,a,a] -> [a,a,a,a,a,-,-,-,-,-]
        // this->print();      
        for (int i = used; i > cursor ; i--) //[a,-,-] -> [b,a,-]
        {
            adress[i]= adress[i-1];
            // this->print();
        }
        adress[cursor] = item;
        // this->print();
        used++;
    }

    void remove(){//[a,-,a,a,a] -> //[a,a,a,a,-]
        for (int i = cursor; i < used ; i++) 
        {
            adress[i]= adress[i+1];
        }
        if (used == (max/2)-1) {this->Downsize();} // [a,a,a,a,-,-,-,-,-,-] -> [a,a,a,a,-]
        used--;
    }

    int getCursorPosition(){
        return cursor;
    }

    void cursorMoveTo(int index){ //idk if I should limit the cursor to just "used" or "max", this way is easier for me if it's all left alined
        if (index > -1 && index <= used) {cursor = index;}
        else {cerr << "index out of range";}
    }

    int getUsed(){
        return used;
    }

    int getMax(){
        return max;
    }

    void print(){
        cout << "cursor: " << cursor << ", " << "used: " << used << ", " << "max: " << max << endl;
        cout << "[";
        for (int i = 0; i < used; i++)
        {
            cout << adress[i] << ", ";
        }
        for (int i = used; i < max; i++)
        {
            if (i != max-1){ cout << "-" << ", "; }
            else { cout << "-";}
        }
        cout << "]" << endl;
    }

    int find(E item){
        int equals = 0;
        for (int i = 0; i < used; i++)
        {
            if (adress[i] == item) {equals++;}
        }
        return equals;
    }
};


int main(){
    ifstream fin("input");
    ofstream fout("output");
    AList<int> lista;
    int entradaInt, c, n;
    string entradaString;
    fin >> c;
    for (int i = 0; i < c; i++)//casos de mecher em lista
    {
        fout << "Caso " << c+1 << ":" << endl;
        AList<int> lista;
        fin >> n;
        for (int i = 0; i < n; i++)//operacoes na lista
        {
            fin >> entradaString >> entradaInt; 
        }
        if (entradaString == "insert")
        {
            lista.insert(entradaInt);
        } else if (entradaString == "remove") {
            lista.remove();
        } else if (entradaString == "count") {
            fout << lista.find(entradaInt) << endl;
        } else if (entradaString == "prev") {
            lista.cursorMoveTo(lista.getCursorPosition()-1);
        } else if (entradaString == "next") {
            lista.cursorMoveTo(lista.getCursorPosition()+1);
        }
    }
    return 0;
}