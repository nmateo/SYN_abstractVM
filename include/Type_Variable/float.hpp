#ifndef _FLOAT_HPP_
#define _FLOAT_HPP_

#include "../../interface/IOperand.hpp"
#include "ZOperand.hpp"

class FloatClass : public ZOperand<float> {
    public:
        FloatClass(const std::string &value);
        ~FloatClass();
};

#endif
