#include <unistd.h>
#include <functional>
#include <bits/stdc++.h>
#include <iomanip>
#include <regex>
#include "../include/definition.hpp"

const eOperandType strOp(std::string str)
{
	if (!str.compare("int8"))
		return (eOperandType::Int8);
	if (!str.compare("int16"))
		return (eOperandType::Int16);
    if (!str.compare("int32"))
        return (eOperandType::Int32);
	if (!str.compare("float"))
		return (eOperandType::Float);
	if (!str.compare("double"))
		return (eOperandType::Double);
	if (!str.compare("bigdecimal"))
		return (eOperandType::BigDecimal);
	return ((eOperandType)0);
}

void eraseComments(std::string &str)
{
    if (str.size() > 2 && str[0] == ';' && str[1] == ';')
        return;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ';')
        {
            str.erase(i, str.size());
            break;
        }
    }
}

std::string epur(std::string base)
{
	while (base.back() == '0' && base.back() != '.') {
		base = base.substr(0, base.size() - 1);
	}
	if (base.back() == '.')
		base = base.substr(0, base.size() - 1);
	return base;
}