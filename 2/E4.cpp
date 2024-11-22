#include <iostream>
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
    AList(int max = 10){
        used = 0;
        cursor = 0;
        adress = new E[max]
    }
    ~AList() {delete [] adress;}

    Upsize(){
        max *= 2;
        E* temp = new E[max];
        int i = 0;
        for (E item:adress)
        {
            temp[i] = item
            i++;
        }
        adress = temp;
        delete [] temp;
    }

    Downsize(){//might cause some issues with memory cuz idk if the for each will stop when there are no more items to be read
        max = (max/2);
        E* temp = new E[max];
        int i = 0;
        for (E item:adress)
        {
            temp[i] = item
            i++;
        }
        adress = temp;
        delete [] temp;
    }

    
};


int main(){

    return 0;
}