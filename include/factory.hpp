#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "../interface/IOperand.hpp"
#include "definition.hpp"
#include <map>

class Factory {
    public:
        Factory();
        ~Factory();
        static IOperand* createOperand(eOperandType type, const std::string &value);
        IOperand* retOperand(eOperandType type, const std::string &value);

    protected:

    private:
        using methodPtr_t = IOperand *(Factory::*)(const std::string &);

        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);
        std::map<eOperandType, methodPtr_t> _methods;
};

#endif
