#ifndef DEFINITION_HPP_
#define DEFINITION_HPP_

// STL INCLUDE
#include <string>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <array>

// ABSTRACT VM INCLUDE


// ABSTRACTVM DEFINE
#define FLOAT_PRECISION 7
#define DOUBLE_PRECISION 15
#define BIGDECIMAL_PRECISION 200

// ABSTRACTVM ENUM
enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
};

#endif
