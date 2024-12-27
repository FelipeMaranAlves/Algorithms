#include "Article.hpp"
#include <iostream>
using namespace std;

    static int Article::article_count = 0;

Article::Article(long int a, string b , double c){
    this->article_name = b;
    this->article_number = a;
    this->article_sales_price = c;
    article_count++;
    cout << "Um objeto do tipo Article "<< article_name << " foi criado."
    << "        "<< "Este e o " << article_number <<" artigo." << endl;
}
Article::~Article(){
    article_count--;
    cout << "Um objeto do tipo Article "<< article_name << " foi destruido."
    << "        " << "Este e o " << article_number <<" artigo." << endl; 
}

void Article::print(){
    cout << "this is the article" << this->article_name << endl;
}

int Article::getCount(){
    return article_count;
}
Article::Article(const Article& original) //made in line
    : article_number(original.article_number),
      article_name(original.article_name),
      article_sales_price(original.article_sales_price){
    article_count++;
    cout << "estou sendo chamado sou o construtor de copia";
    cout << "This is the " << article_count << " Article.\n";
}

void test(Article a){
    Article artigo3(31,"dentrofunc1",3);
    const Article artigo4(21,"dentrofunc2",4);
}

Article artigo1(12,"global",1);
int main(){
    Article artigo2(13,"main",2);
    Article artigo5 = artigo1;
    test(artigo2);
    test(artigo2);
    return 0;
}