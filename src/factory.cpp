#include "../include/factory.hpp"
#include "../include/Error.hpp"
#include "../include/Type_Variable/int8.hpp"
#include "../include/Type_Variable/int16.hpp"
#include "../include/Type_Variable/int32.hpp"
#include "../include/Type_Variable/float.hpp"
#include "../include/Type_Variable/double.hpp"
#include "../include/Type_Variable/bigdecimal.hpp"
#include <memory>
#include <limits>
#include <float.h>

using methodPtr_t = IOperand *(Factory::*)(const std::string &);

Factory::Factory()
{
    _methods[Int8] = &Factory::createInt8;
    _methods[Int16] = &Factory::createInt16;
    _methods[Int32] = &Factory::createInt32;
    _methods[Float] = &Factory::createFloat;
    _methods[Double] = &Factory::createDouble;
    _methods[BigDecimal] = &Factory::createBigDecimal;
}

Factory::~Factory()
{

}

IOperand* Factory::createInt8(const std::string &value)
{
    long long int tmp = std::stoll(value);

    if (tmp < INT8_MIN || tmp > INT8_MAX)
        throw Error("Value exceeded capacity of int8");
    return (new int8(value));
}

IOperand* Factory::createInt16(const std::string &value)
{
    long long int tmp = std::stoll(value);

    if (tmp < INT16_MIN || tmp > INT16_MAX)
        throw Error("Value exceeded capacity of int16");
    return (new int16(value));
}

IOperand* Factory::createInt32(const std::string &value)
{
    long long int tmp = std::stoll(value);

    if (tmp < INT32_MIN || tmp > INT32_MAX)
        throw Error("Value exceeded capacity of int32");
    return (new int32(value));
}

IOperand* Factory::createFloat(const std::string &value)
{
    long double tmp = std::stold(value);

    if (tmp < -FLT_MAX || tmp > FLT_MAX)
        throw Error("Value exceeded capacity of float");
    return (new FloatClass(value));
}

IOperand* Factory::createDouble(const std::string &value)
{
    long double tmp = std::stold(value);

    if (tmp < -DBL_MAX || tmp > DBL_MAX)
        throw Error("Value exceeded capacity of double");
    return (new DoubleClass(value));
}

IOperand* Factory::createBigDecimal(const std::string &value)
{
    IOperand *newOne = new Bigdecimal(value);
    return (newOne);
}

IOperand* Factory::retOperand(eOperandType type, const std::string &value)
{
    methodPtr_t mfPtr;
    mfPtr = this->_methods[type];
    return (this->*mfPtr)(value);
}

IOperand* Factory::createOperand(eOperandType type, const std::string &value)
{
    std::unique_ptr<Factory> tmp = std::make_unique<Factory>();
    return (tmp->retOperand(type, value));
}

