#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction
{
private:
    long numerator;
    long denominator;
public:

    class DivisionByZero
    {};

    Fraction(long a = 0,long b =1) throw(DivisionByZero)ç
    Fraction(long a = 0, long b = 1) {
        if (b == 0){throw "nuh uh";}
        
        if (b < 0){a = -a;b = -b;}
        this->numerator = a;
        this->denominator = b;
    }

    ~Fraction() = default;
    // double to_double() const{// meu jeito feio
    //     return ((double)this->numerator)/((double)this->denominator);
    // }
    
    double to_double() const { //jeito bonito do gpt
        return static_cast<double>(numerator)/denominator;
    }

    Fraction operator-() const {return Fraction(-numerator,denominator);}
    Fraction& operator++(){numerator += denominator; return *this;}
    Fraction& operator--(){numerator -= denominator; return *this;}   
    Fraction& operator+=(const Fraction& a){
        numerator = (numerator*a.denominator + a.numerator*denominator);
        denominator = a.denominator*denominator;
        return *this;
    }
        Fraction& operator-=(const Fraction& a){
        *this += (-a);
        return *this;
    }
        Fraction& operator*=(const Fraction& a){
        numerator *= a.numerator;
        denominator *= a.denominator;
        return *this;
    }
        Fraction& operator/=(const Fraction& a){
        numerator *= a.denominator;
        denominator *= a.numerator;
        return *this;
    }

    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& obj1);
    friend std::istream& operator>>(std::istream& in,Fraction& obj1);
};

// Fraction operator+(Fraction& obj1,Fraction& obj2){ MEU JEITO
//     Fraction temp = obj1;
//     temp += obj2;
//     return temp;
// }
Fraction operator+(const Fraction& a, const Fraction& b) //intended way
{
Fraction temp;
temp.denominator = a.denominator * b.denominator;
temp.numerator = a.numerator*b.denominator + b.numerator * a.denominator;
return temp;
}

Fraction operator-(const Fraction& a, const Fraction& b) //intended way
{
Fraction temp;
temp.denominator = a.denominator * b.denominator;
temp.numerator = a.numerator*b.denominator - b.numerator * a.denominator;
return temp;
}

Fraction operator*(const Fraction& obj1, const Fraction& obj2){
    long numerator,denominator;
    numerator = obj1.numerator*obj2.numerator;
    denominator = obj1.denominator*obj2.denominator;
    return Fraction(numerator,denominator);
}

Fraction operator/(const Fraction& obj1, const Fraction& obj2){
    long numerator,denominator;
    numerator = obj1.numerator*obj2.denominator;
    denominator = obj1.denominator*obj2.numerator;
    return Fraction(numerator,denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj1){
    os << obj1.numerator << "/" << obj1.denominator;
    return os;
}

std::istream& operator>>(std::istream& is,Fraction& obj1){
    std::cout << "Enter a fraction:\n"
    " Numerator: "; is >> obj1.numerator;
    std::cout << " Denominator != 0: "; is >> obj1.denominator;
    if( !is) return is;
    if( obj1.denominator == 0)
    {
    std::cout << "\nError: The denominator is 0\n"
    " New denominator != 0: ";
    is >> obj1.denominator;
    if( obj1.denominator == 0)
    {
    std::cerr << "\nError: Division by zero!\n"; exit(1);
    }
    }
    if( obj1.denominator < 0 )
    obj1.numerator = -obj1.numerator,
    obj1.denominator= -obj1.denominator;
    return is;
}

#endif
