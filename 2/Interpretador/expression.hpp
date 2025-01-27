#include <Operand.hpp>
#include <bits/stdc++.h>
#ifndef EXPRESSION
#define EXPRESSION

class Expression
{
private:
    bool isInt;
    bool isBool;
    int intValue;
    bool boolValue;
    std::string current_token;
public:
    Expression(/* args */);
    ~Expression();
    Expression parse_exp() {
	    return parse_or_exp();
    }

    Expression parse_or_exp() {
        Expression e1;
        e1 = parse_and_exp();
        if (current_token == "||") {
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_and_exp();
            return new BinaryExpression(e1, op, e2);		
        } else {
            return e1;
        }
    }

    Expression parse_and_exp(){
        Expression e1;
        e1 = parse_eq_exp();
        if (current_token == "&&"){
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_eq_exp();
            return new BinaryExpression(e1,op,e2);
        } else{
            return e1;
        }
    }

    Expression parse_eq_exp(){
        Expression e1;
        e1 = parse_rel_exp();
        if (current_token == "==" || current_token == "!=")
        {
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_rel_exp();
            return new Binary_Expression(e1,op,e2);
        }
        return e1;
    }

    Expression parse_rel_exp(){
        Expression e1;
        e1 = parse_add_exp();
        if (current_token == "<" || current_token == ">" || current_token == "<=" || current_token == ">="){
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_add_exp();
            return new Binary_Expresion(e1,op,e2);
        }
        return e1;
    }
    Expression parse_add_exp(){
        Expression e1;
        e1 = parse_mul_exp(); //if precisa ser modificado
        if (current_token == "+" || current_token == "-")
        {
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_mul_exp();
            return new Binary_Expression(e1,op,e2);
        }
        return e1;
    }

    Expression parse_mul_exp(){
        Expression e1;
        e1 = parse_unary_exp();
        if (current_token == "*" || current_token == "/")
        {
            Operand op = new Operand(current_token);
            read_next_token();
            Expression e2;
            e2 = parse_unary_exp();
        }
        return e1;
    }

    Expression parse_unary_exp(){
    Expression e1;
    e1 = parse_primary_exp();
    if (current_token == "-")
    {
        return e1; //make it's value  negative or something NEED A METHOD
    }
    return e1;
    }

    Expression parse_primary_exp(){
        Expression e1;
        if (current_token == "(")
        {
            e1 = parse_exp();
            return e1;
        }
        //e1 = literal
        return e1; //FAZER RETORNAR UM INT OU BOOL
        //pode ser um expression ou um literal
    }
} //Expression

Expression::Expression(/* args */)
{
}

Expression::~Expression()
{
}


#endif