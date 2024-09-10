#ifndef _INT8_HPP_
#define _INT8_HPP_

#include "../../interface/IOperand.hpp"
#include "../../include/Type_Variable/ZOperand.hpp"

class int8 : public ZOperand<int8_t> {
    public:
        int8(const std::string &value);
        ~int8();
};

#endif
