#ifndef Arti
#define Arti

#include <string>
using namespace std;

class Article
{
private:
    long int article_number;
    double article_sales_price;
    string article_name;
public:
    Article(long int, string,double);
    ~Article();
    void print();
    
    void set_number(long int a){
        this->article_number = a;
    }

    int get_number(void){
        return this->article_number;
    }

    void set_price(double a){
        if (a < 0) {a == 0;}
        this->article_sales_price = a;
    }

    double get_price(void){
        return this->article_number;
    }

    void set_name(string a){
        this->article_name = a;
    }
    string get_name(void){
        return this->article_name;
    }

    void print();
};

#endif