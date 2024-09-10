#include "../../include/Type_Variable/double.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include <iostream>
#include <string>
#include <float.h>


DoubleClass::DoubleClass(const std::string &value) : ZOperand(value, eOperandType::Double)
{
}

DoubleClass::~DoubleClass() {}
