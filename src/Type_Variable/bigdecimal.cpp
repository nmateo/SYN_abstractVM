#include "../../include/Type_Variable/bigdecimal.hpp"

Bigdecimal::Bigdecimal(const std::string &value)
{
    this->print = value;
    this->value = value;
}

Bigdecimal::~Bigdecimal() {}

eOperandType Bigdecimal::getType() const
{
    return eOperandType::BigDecimal;
}

std::string Bigdecimal::toString() const
{
    return print;
}

std::string Bigdecimal::getValue() const
{
    return this->value;
}

IOperand *Bigdecimal::operator +(const IOperand &rhs) const
{
    Factory *factory = new Factory();
    IOperand *added;
    Add *addition = new Add();
    added = factory->createOperand(eOperandType::BigDecimal, addition->add(value, rhs.toString()));
    delete factory;
    delete addition;
    return added;
}

IOperand *Bigdecimal::operator -(const IOperand &rhs) const
{
    Factory *factory = new Factory();
    IOperand *menus;
    Sub *soustract = new Sub();

    menus = factory->createOperand(eOperandType::BigDecimal, soustract->subinf(this->toString(), rhs.toString()));
    delete factory;
    return menus;
}

IOperand *Bigdecimal::operator /(const IOperand &rhs) const
{
    /*
    if (std::stoi(rhs.toString()) == 0)
        throw Error("Error: Divide by 0");
    int result = value / std::stod(rhs.toString());
    if (result > DBL_MAX || result < DBL_MIN)
        throw Error("Value not allowed for type : Double.");
    Factory *factory = new Factory();
    IOperand *divided;
    divided = factory->createOperand(eOperandType::Double, (std::to_string(result)));
    delete factory;
    return (divided);
    */
       throw Error("Lucas il a pas fini");

}

IOperand *Bigdecimal::operator *(const IOperand &rhs) const
{
    IOperand *mul;
    Factory *factory = new Factory();
    Mul *multiply = new Mul();
    mul = factory->createOperand(eOperandType::BigDecimal , multiply->mult(this->toString(), rhs.toString()));
    delete factory;
    delete multiply;
    return mul;
}

IOperand *Bigdecimal::operator %(const IOperand &rhs) const
{
    throw Error("Modulo not possible for bigdecimal");
}
