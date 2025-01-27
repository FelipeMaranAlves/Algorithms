#include <string>
#ifndef OPERAND
#define OPERAND

class Operand
{
private:
    std::string value;
public:
    Operand(std::string a){
        this->value = a;
    };
    ~Operand();

    std::string get_operand(void){
        return this->value;
    }
};
#endif
