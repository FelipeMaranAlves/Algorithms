#include "Article.hpp"
#include <iostream>
using namespace std;

int numArticle = 0;

Article::Article(long int a, string b , double c){
    this->article_name = b;
    this->article_number = a;
    this->article_sales_price = c;
    numArticle++;
    cout << "Um objeto do tipo Article "<< article_name << " foi criado."
    << "/n" << "Este é o" << numArticle <<"º artigo.";
}
Article::~Article(){
    numArticle--;
    cout << "Um objeto do tipo Article "<< article_name << " foi criado."
    << "/n" << "Este é o" << numArticle <<"º artigo."; 
}

void Article::print(){

}

void appProg(){

}

void test(){
    Article artigo3(31,"nome3",13.5);
    const Article artigo4(21,"nome4",14);
}

Article artigo1(12,"nome",12.5);
int main(){
    Article artigo2(13,"nome2",13);
    test();
    test();
    return 0;
}