#include "../../include/Type_Variable/int16.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include <iostream>
#include <string>

int16::int16(const std::string &value): ZOperand(value, eOperandType::Int16)
{
}

int16::~int16() {}
