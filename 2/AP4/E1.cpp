#include <iostream>
#include <fstream>
#include <ctime>
#include "Date.h"
using namespace std;

void Date::print(){
        cout << this->month << "/" << this->day << "/" << this->year;
    }

void Date::init(int month,int day,int year){
    this->month = month;
    this->day = day;
    this->year = year;  
}

void Date::init(void){
    time_t time(time_t *ptrSec);
    struct tm *localtime(const time_t *ptrSec);
    tm banana;
    this->month = banana.tm_mon;
    this->day = banana.tm_mday;
    this->year = banana.tm_year; 
}

int main(){
    ifstream fin("input");
    ofstream fout("output");
    Date a;
    a.print();
    return 0;
}