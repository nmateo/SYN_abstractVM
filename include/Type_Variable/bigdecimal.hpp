#ifndef _BIGDECIMAL_HPP_
#define _BIGDECIMAL_HPP_

#include <iostream>
#include <string>
#include <float.h>
#include "../../interface/IOperand.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include "../../include/add.hpp"
#include "../../include/sub.hpp"
#include "../../include/mul.hpp"

class Bigdecimal : public IOperand {
    private:
        std::string value;
        std::string print;
    public:
        Bigdecimal(const std::string &value);
        ~Bigdecimal();

        eOperandType getType() const; // returns the type of instance
        std::string getValue() const; // return value

        std::string toString() const; // string that represents the instance
        IOperand *operator +(const IOperand &rhs) const;

        IOperand *operator -( const IOperand & rhs ) const; // difference
        IOperand *operator *( const IOperand & rhs ) const; // product
        IOperand *operator /( const IOperand & rhs ) const; // quotient
        IOperand *operator %( const IOperand & rhs ) const; // modulo

};

#endif
