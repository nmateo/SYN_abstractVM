#ifndef _INT32_HPP_
#define _INT32_HPP_

#include "../../interface/IOperand.hpp"
#include "ZOperand.hpp"

class int32 : public ZOperand<int32_t> {
    public:
        int32(const std::string &value);
        ~int32();
};

#endif
