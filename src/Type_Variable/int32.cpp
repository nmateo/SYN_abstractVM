#include "../../include/Type_Variable/int32.hpp"
#include "../../include/factory.hpp"
#include "../../include/Error.hpp"
#include <iostream>
#include <string>

int32::int32(const std::string &value) : ZOperand(value, eOperandType::Int32)
{
}

int32::~int32() {}
