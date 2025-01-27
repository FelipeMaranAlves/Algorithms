#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input");
ofstream fout("output");


class product
{
private:
    long barcode;
    string name;
public:

    product(){barcode = -1;name = "";} //construtor padrao
    product(long a, string b) : barcode(a), name(b){}; //contrutor com  parametros (nao e o padrao)

    void setCode(long a) {barcode = a;}
    int getCode(void){return barcode;}
    void setName(string a) {name = a;}
    string getName(void) {return name;}
    void scanner(void){
        cout << "Input the code of the product: ";
        cin >> barcode;
        cout << endl;
        cout << "Input the name of the product: ";
        cin >> name;
        cout << endl;
    }
    void printer(void){
        fout << "Bar code: " << barcode << endl
        << "Name: " << name << endl;
    }
};

class prePackedFood : public product
{
private:
    float unitprice;
public:
prePackedFood(){
        setCode(-1);
        setName("null");
        unitprice = -1;
        }
    prePackedFood(long code, string name, long uprice){
        setCode(code);
        setName(name);
        unitprice = uprice;
        }
    ~prePackedFood() = default;

    void setUnitPrice(long a){unitprice = a;}
    long getUnitPrice(void){return unitprice;}
    void scanner(){ //wtf, i do what im told tho...
        product::scanner();
        cout << "Input the price per unit: ";
        cin >> unitprice;
        cout << endl;
    }
    void printer(){
        product::printer();
        fout << "Price per unit: " << unitprice << endl;
    }
    // double banana(long units){
    // double price = units*unitprice;
    // fout << "Total price of: " << getName() << " - " << price << endl;
    // return price;
    // }
};

class freshfood : public product
{
private:
    double kiloprice;
    double weight;
public:
    freshfood(){
        setCode(-1);
        setName("null");
        kiloprice = -1;
        }
    freshfood(long a, string b, double c){
        setCode(a);
        setName(b);
        kiloprice = c;
        }
    void setKiloPrice(long a){kiloprice = a;}
    long getKiloPrice(void){return kiloprice;}
    void setWeight(double a){weight =a;}
    double getWeight(void){return weight;}
    // double banana(double weight){
    //     double price = weight*kiloprice;
    //     fout << "Total price of: " << getName() << " - " << price << endl;
    //     return price;
    // }
    void scanner(){
        product::scanner();
        cout << "Input the price per kilo: ";
        cin >> kiloprice;
        cout<< endl;
        cout << "Input the Weight: ";
        cin >> weight;
        cout<< endl;
    }
    void printer(){
        product::printer();
        fout << "Price per kilo: " << kiloprice << endl;
        fout << "Weight: " << weight << endl;
        fout << "Total price: " << weight*kiloprice << endl;
    }
};




int main(){
    product produto1(001,"coca");
    freshfood produto2(002,"banana",2);
    prePackedFood produto3(003,"requeijao",9);
    produto1.printer();
    produto2.printer();
    produto3.printer();
    fout << "================================";
    product produto4;
    freshfood produto5;
    prePackedFood produto6;
    produto4.scanner();
    produto5.scanner();
    produto6.scanner();
    produto4.printer();
    produto5.printer();
    produto6.printer();
    fout << "================================";
    fout << "code do 4 era"<< produto4.getCode();
    cout << "o codigo do 4 ";
    produto4.setCode(cin.get());
    fout << "code do 4 agora e"<< produto4.getCode() << endl;
    fout << "name do 5 era"<< produto5.getName();
    cout << "o name do 5 ";
    char temp[21];
    cin.getline(temp,21);
    produto5.setName(temp);
    fout << "nome do 5 agora e"<< produto4.getName() << endl;
    fout<< "o preco unitario do 6 era: " << produto6.getUnitPrice()<<endl;
    fout << "unitprice do 6 ";
    produto6.setCode(cin.get());
    fout<< "o preco unitario do 6 agora e : " << produto6.getUnitPrice()<<endl;
    fout << "================================";
    return 0;
}


