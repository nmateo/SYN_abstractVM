#ifndef _INT16_HPP_
#define _INT16_HPP_

#include "../../interface/IOperand.hpp"
#include "ZOperand.hpp"

class int16 : public ZOperand<int16_t> {
    public:
        int16(const std::string &value);
        ~int16();
};

#endif
