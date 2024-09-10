#include "../include/definition.hpp"

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

class  IOperand
{
    public:
        virtual  std:: string  toString ()  const = 0;
        virtual  eOperandType  getType ()  const = 0;
        virtual  IOperand* operator +( const  IOperand &rhs) const = 0;
        virtual  IOperand* operator -( const  IOperand &rhs) const = 0;
        virtual  IOperand* operator *( const  IOperand &rhs) const = 0;
        virtual  IOperand* operator /( const  IOperand &rhs) const = 0;
        virtual  IOperand* operator %( const  IOperand &rhs) const = 0;
        virtual   ~IOperand () {}
};

#endif
