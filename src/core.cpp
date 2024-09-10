#include "../include/core.hpp"
#include "../include/factory.hpp"
#include "../include/Error.hpp"
#include <unistd.h>
#include <functional>
#include <bits/stdc++.h>
#include <iomanip>
#include <regex>

std::string epur(std::string base);

Core::Core()
{
    for (size_t i = 0; i != 16; i++)
    {
        this->_registers[i] = NULL;
    }
    this->_factory = std::make_unique<Factory>();
    this->_parser = std::make_unique<Parser>();
    _methods["push"] = &Core::stackPush;
    _methods["pop"] = &Core::stackPop;
    _methods["clear"] = &Core::stackClear;
    _methods["dup"] = &Core::stackDup;
    _methods["swap"] = &Core::stackSwap;
    _methods["dump"] = &Core::stackDump;
    _methods["assert"] = &Core::stackAssert;
    _methods["add"] = &Core::stackAdd;
    _methods["sub"] = &Core::stackSub;
    _methods["mul"] = &Core::stackMul;
    _methods["div"] = &Core::stackDiv;
    _methods["mod"] = &Core::stackMod;
    _methods["load"] = &Core::regLoad;
    _methods["store"] = &Core::regStore;
    _methods["print"] = &Core::stackPrint;
    _methods["exit"] = &Core::pExit;
    _exit = false;
}

Core::~Core()
{

}

int Core::stackSwap(const eOperandType type, const std::string &val)
{
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on swap");
        return (-1);;
    }
    IOperand *first = this->_stack.front();
    this->_stack.pop_front();
    IOperand *second = this->_stack.front();
    this->_stack.pop_front();
    this->_stack.push_front(first);
    this->_stack.push_front(second);
    return (0);
}

int Core::stackPop(const eOperandType type, const std::string &val)
{
    if (this->_stack.empty() == true)
    {
        throw Error("Empty stack on pop");
        return (-1);
    }
    this->_stack.pop_front();
    return (0);
}

int Core::stackClear(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    while (this->_stack.empty() == false)
        this->_stack.pop_front();
    return (0);
}

int Core::stackPush(const eOperandType type, const std::string &val)
{
    eOperandType newType = type;
    IOperand *newOp = this->_factory->createOperand(newType, std::ref(val));
    this->_stack.push_front(newOp);
    return (0);
}

int Core::stackDup(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    if (this->_stack.empty() == false)
    {
        IOperand *newOp = this->_stack.front();
        this->_stack.push_front(newOp);
    }
    return (0);
}

int Core::stackDump(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    std::string tmp;
    std::size_t tmpPos;
    double tmpDouble;
    float tmpFloat;

    if (this->_stack.empty() == false)
    {
        std::list<IOperand *>::const_iterator it = this->_stack.begin();
        for (; it != this->_stack.end(); it++)
        {
            tmp = (*it)->toString();
            tmpPos = tmp.find(".");
            if (tmpPos != std::string::npos)
                tmp = epur(tmp);
            switch ((*it)->getType())
            {
                case eOperandType::Float:
                    std::cout << std::setprecision(7) << std::stof(tmp) << std::endl;
                    break;
                case eOperandType::Double:
                    std::cout << std::setprecision(15) << std::stod(tmp) << std::endl;
                    break;
                default:
                    std::cout << tmp << std::endl;
                    break;
            }
        }
    }
    return (0);
}

int Core::stackAssert(const eOperandType type, const std::string &val)
{
    std::list<IOperand *>::const_iterator it = this->_stack.begin();

    if ((*it)->getType() != type)
        throw Error(("Wrong type on assert"));
    if (std::stod((*it)->toString()) != std::stod(val)) {
        throw Error("Wrong value on assert");
    }
    return (0);
}

int Core::stackAdd(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    IOperand *tmp1;
    IOperand *tmp2;
    IOperand *res = NULL;

    std::list<IOperand *>::iterator it = this->_stack.begin();
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on add op");
        return (-1);
    }
    tmp1 = *(++it);
    tmp2 = *(--it);
    if (tmp1->getType() > tmp2->getType())
        res = *(tmp1) + *(tmp2);
    else
        res = *(tmp2) + *(tmp1);
    this->stackPop(Int8, "");
    this->stackPop(Int8, "");
    this->_stack.push_front(res);
    return (0);
}

int Core::stackSub(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);

    std::list<IOperand *>::iterator it = this->_stack.begin();
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on sub op");
        return (-1);
    }
    IOperand *res =  **(++it) - **(--it);
    this->stackPop(Int8, "");
    this->stackPop(Int8, "");
    this->_stack.push_front(res);
    return (0);
}

int Core::stackMul(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    IOperand *tmp1;
    IOperand *tmp2;
    IOperand *res = NULL;

    std::list<IOperand *>::iterator it = this->_stack.begin();
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on mul op");
        return (-1);
    }
    tmp1 = *(++it);
    tmp2 = *(--it);
    if (tmp1->getType() > tmp2->getType())
        res = *(tmp1) * *(tmp2);
    else
        res = *(tmp2) * *(tmp1);
    this->stackPop(Int8, "");
    this->stackPop(Int8, "");
    this->_stack.push_front(res);
    return (0);
}

int Core::stackDiv(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);

    std::list<IOperand *>::iterator it = this->_stack.begin();
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on div op");
        return (-1);
    }
    IOperand *res =  **(++it) / **(--it);
    this->stackPop(Int8, "");
    this->stackPop(Int8, "");
    this->_stack.push_front(res);
    return (0);
}

int Core::stackMod(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);

    std::list<IOperand *>::iterator it = this->_stack.begin();
    if (this->_stack.size() < 2)
    {
        throw Error((std::string)"Less than 2 elements on mod op");
        return (-1);
    }
    IOperand *res =  **(++it) % **(--it);
    this->stackPop(Int8, "");
    this->stackPop(Int8, "");
    this->_stack.push_front(res);
    return (0);
}

int Core::regLoad(const eOperandType type, const std::string &val)
{
    (void)(type);
    int reg = stoi(val);

    if (reg > 15 || reg < 0)
        throw Error("This machine only have 0-15 registers");
    if (this->_registers[reg] == NULL)
    {
        throw Error("Register not occupied");
        return (-1);
    }
    this->_stack.push_front(this->_registers[reg]);
    return (0);
}

int Core::regStore(const eOperandType type, const std::string &val)
{
    (void)(type);

    IOperand *tmp;
    int reg = stoi(val);

    if (reg > 15 || reg < 0)
        throw Error("This machine only have 0-15 registers");
    if (this->_stack.size() >= 1)
    {
        tmp = *(this->_stack.begin());
        this->_registers[reg] = tmp;
        this->_stack.pop_front();
    }
    return (0);
}

int Core::stackPrint(const eOperandType type, const std::string &val)
{
	(void)(type);
	(void)(val);

    if (this->_stack.empty() == true)
        return (0);
	if ((*this->_stack.begin())->getType() != Int8)
		throw Error("Top of the stack isn't a Int8 print");
	printf("%c\n", std::stoi((*_stack.begin())->toString()));
    return (0);
}

int Core::pExit(const eOperandType type, const std::string &val)
{
    (void)(type);
    (void)(val);
    this->_exit = true;
    return (0);
}

int Core::execInstructions(std::string command)
{
    std::vector<std::string> parsed = this->_parser->getInstruction(command);
    methodCmdPtr_t mfPtr;
    eOperandType tmpOp;
    std::string tmpVal;

    if (parsed.empty() == true)
        return (0);
    tmpOp = this->_parser->getOpType(parsed);
    tmpVal = this->_parser->getValue(parsed);
    auto it_p = parsed.begin();
    auto it_m = _methods.begin();
    for (; it_m != _methods.end(); it_m++)
    {
        if (!(*it_p).compare((*it_m).first))
        {
            mfPtr = (*it_m).second;
            (this->*mfPtr)(tmpOp, tmpVal);
            break;
        }
    }
    return (0);
}

void Core::setMode(int mode)
{
    this->_mode = mode;
}

bool Core::isExited()
{
    return (this->_exit);
}
