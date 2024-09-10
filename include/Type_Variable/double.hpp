#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_

#include "../../interface/IOperand.hpp"
#include "ZOperand.hpp"

class DoubleClass : public ZOperand<double> {
    public:
        DoubleClass(const std::string &value);
        ~DoubleClass();
};

#endif
