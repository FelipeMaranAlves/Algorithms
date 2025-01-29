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
    double units;
    float unitprice;
public:
    prePackedFood() : unitprice(-1), units(-1)
    {}
    prePackedFood(long code, string name, long uprice,long nUnits) 
    : product(code,name) , unitprice(uprice), units(nUnits)
    {}
    ~prePackedFood() = default;

    void setUnitPrice(long a){unitprice = a;}
    long getUnitPrice(void){return unitprice;}
    void setNumberOfUnits(long a) {units = a;}
    long getnUnits(void) {return units;}
    void scanner(){ //wtf, i do what im told tho...
        product::scanner();
        cout << "Input the price per unit: ";
        cin >> unitprice;
        cout << endl;
        cout << "Input the number of units: ";
        cin >> units;
        cout << endl;
    }
    void printer(){
        product::printer();
        fout << "Price per unit: " << unitprice << endl;
        fout << "Total price: " << unitprice * units << endl;
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
    freshfood(): kiloprice(-1), weight(-2)
    {}
    freshfood(long a, string b, double c, double d)
    : product(a,b), kiloprice(c), weight(d)
    {}
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


product& isLowerCode(product& a,product& b){
    if (a.getCode() < b.getCode()){
        return a;}
    return b;
}

product* isLowerCode(product* a,product* b){
    if (a->getCode() < b->getCode()){
        return a;}
    return b;
}

int main(){
    product* array[3];
    array[0] = new product(1,"tire");
    array[1] = new freshfood(2,"banana",2,0.76);
    array[2] = new prePackedFood(3,"tuna",4.8,3);
    isLowerCode(array[2],array[2])->printer();
    return 0;
}


