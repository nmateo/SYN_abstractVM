#include "../../include/Type_Variable/ZOperand.hpp"
#include "../../include/definition.hpp"
#include "../../include/factory.hpp"
#include <limits>
#include "../../include/Error.hpp"

std::string getNametype(eOperandType enume)
{
    switch (enume)
    {
    case eOperandType::Int8 :
        return ("Int8");
        break;
    case eOperandType::Int16 :
        return ("Int16");
        break;
    case eOperandType::Int32 :
        return ("Int32");
        break;
    case eOperandType::Float :
        return ("Float");
        break;
    case eOperandType::Double :
        return ("Double");
        break;
    default :
        return ("");
        break;
    }
}

template <typename T>
ZOperand<T>::ZOperand(std::string const &valu, eOperandType type)
{
    this->valeur = valu;
    this->type = type;
}

template <typename T>
ZOperand<T>::~ZOperand()
{
}

template<typename T>
std::string ZOperand<T>::toString() const
{
    return valeur;
}

template<typename T>
eOperandType ZOperand<T>::getType() const
{
    return type;
}

template<typename T>
IOperand* ZOperand<T>::operator+(const IOperand &rhs) const
{
    Factory *factory = new Factory();
    IOperand *added;
    double value = static_cast<double>(stod(this->valeur));
    if ((value + std::stof(rhs.toString())) >= -std::numeric_limits<T>::max() - 1 && value + std::stof(rhs.toString()) <= std::numeric_limits<T>::max()) {
        added = factory->createOperand(getType(), (std::to_string((value + std::stof(rhs.toString())))));
        delete factory;
        return added;
    }
    else
        throw Error("Value not allowed for type : " + getNametype(getType()));
}

template<typename T>
IOperand* ZOperand<T>::operator-(const IOperand &rhs) const
{
    Factory *factory = new Factory();
    IOperand *menus;
    double value = static_cast<double>(stod(this->valeur));
    if (value - std::stof(rhs.toString()) >= -std::numeric_limits<T>::max() - 1 && value - std::stof(rhs.toString()) <= std::numeric_limits<T>::max()) {
        menus = factory->createOperand(getType(), (std::to_string((value - std::stof(rhs.toString())))));
        delete factory;
        return menus;
    }
    else
        throw Error("Value not allowed for type :" + getNametype(getType()));
}

template<typename T>
IOperand* ZOperand<T>::operator*(const IOperand &rhs) const
{
    IOperand *mul;
    Factory *factory = new Factory();
    double value = static_cast<double>(stod(this->valeur));
    if (value * std::stof(rhs.toString()) >= -std::numeric_limits<T>::max() - 1 && value * std::stof(rhs.toString()) <= std::numeric_limits<T>::max()) {
        mul = factory->createOperand(getType() ,std::to_string((value * std::stof(rhs.toString()))));
        delete factory;
        return mul;
    }
    else
        throw Error("Value not allowed for type :" + getNametype(getType()));
}

template<typename T>
IOperand* ZOperand<T>::operator/(const IOperand &rhs) const
{
    if (std::stod(rhs.toString()) == 0)
        throw Error("Error: Divide by 0");
    double value = static_cast<double>(stod(this->valeur));
    double result = value / std::stod(rhs.toString());
    if (result < -std::numeric_limits<T>::max() - 1 || result > std::numeric_limits<T>::max()) {
        throw Error("Value not allowed for type :" + getNametype(getType()));
    }
    Factory *factory = new Factory();
    IOperand *divided;
    divided = factory->createOperand(getType(), (std::to_string(result)));
    delete factory;
    return (divided);
}

template<typename T>
IOperand* ZOperand<T>::operator%(const IOperand &rhs) const
{
    int result;
    int value = std::stoi(valeur);
    if (rhs.getType() == eOperandType::Double || rhs.getType() == eOperandType::Float)
        throw Error("Error Modulo with Double or Float");
    if (std::stoi(rhs.toString()) == 0)
        throw Error("Error: Modulo with 0");
    result = value % std::stoi(rhs.toString());
    if (result < -std::numeric_limits<T>::max() - 1 || result > std::numeric_limits<T>::max())
        throw Error("Value not allowed for type :" + getNametype(getType()));
    Factory *factory = new Factory();
    IOperand *modulo;
    modulo = factory->createOperand(getType() ,std::to_string(result));
    delete factory;
    return modulo;
}


template ZOperand<int8_t>::ZOperand(const std::string &value, eOperandType type);
template ZOperand<int16_t>::ZOperand(const std::string &value, eOperandType type);
template ZOperand<int32_t>::ZOperand(const std::string &value, eOperandType type);
template ZOperand<float>::ZOperand(const std::string &value, eOperandType type);
template ZOperand<double>::ZOperand(const std::string &value, eOperandType type);
