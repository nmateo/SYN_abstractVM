#ifndef CORE_HPP_
#define CORE_HPP_

#include "../interface/IOperand.hpp"
#include "factory.hpp"
#include "parser.hpp"
#include <vector>
#include <array>
#include <memory>
#include <regex>
#include <list>

class Core
{

    public:
        Core();
        ~Core();
        int stackSwap(const eOperandType, const std::string &);
        int stackPop(const eOperandType, const std::string &);
        int stackClear(const eOperandType, const std::string &);
        int stackPush(const eOperandType, const std::string &);
        int stackDup(const eOperandType, const std::string &);
        int stackDump(const eOperandType, const std::string &);
        int stackAssert(const eOperandType, const std::string &);
        int stackAdd(const eOperandType, const std::string &);
        int stackSub(const eOperandType, const std::string &);
        int stackMul(const eOperandType, const std::string &);
        int stackDiv(const eOperandType, const std::string &);
        int stackMod(const eOperandType, const std::string &);
        int regLoad(const eOperandType, const std::string &);
        int regStore(const eOperandType, const std::string &);
        int stackPrint(const eOperandType, const std::string &);
        int pExit(const eOperandType, const std::string &);
        int execInstructions(std::string);
        void setMode(int);
        bool isExited();

    private:
        using methodCmdPtr_t = int (Core::*)(const eOperandType, const std::string &);

        std::list<IOperand *> _stack;
        std::array<IOperand *, 16> _registers;
        std::unique_ptr<Factory> _factory;
        std::unique_ptr<Parser> _parser;
        std::map<std::string, methodCmdPtr_t> _methods;
        bool _exit;
        int _mode;
};

std::string epur(std::string base);

#endif
