#include "../../include/Type_Variable/int8.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include <iostream>
#include <string>

int8::int8(const std::string &value) : ZOperand(value, eOperandType::Int8)
{
}

int8::~int8() {}
