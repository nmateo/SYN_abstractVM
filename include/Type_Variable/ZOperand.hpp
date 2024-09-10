#ifndef _ZOPERAND_HPP_
#define _ZOPERAND_HPP_

#include "../definition.hpp"
#include "../../interface/IOperand.hpp"

template <typename T>
class ZOperand : public IOperand {
    public:
        ZOperand(std::string const &value, eOperandType type);
        ~ZOperand ();

        virtual std::string toString() const;
        virtual eOperandType  getType () const;
        virtual IOperand* operator+(const IOperand &rhs) const;
        virtual IOperand* operator-(const IOperand &rhs) const;
        virtual IOperand* operator*(const IOperand &rhs) const;
        virtual IOperand* operator/(const IOperand &rhs) const;
        virtual IOperand* operator%(const IOperand &rhs) const;

    private:
        std::string valeur;
        eOperandType type;
};

#endif
