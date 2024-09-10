#include "../../include/Type_Variable/float.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <float.h>


FloatClass::FloatClass(const std::string &value) :  ZOperand(value, eOperandType::Float)
{
}

FloatClass::~FloatClass() {}
