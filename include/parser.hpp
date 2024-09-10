#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include "definition.hpp"

class Parser
{
    public:
        Parser(){}
        ~Parser(){}
        std::vector<std::string> getInstruction(std::string &);
        std::vector<std::string> readFile(char *);
        std::vector<std::string> readPrompt(void);
        eOperandType getOpType(std::vector<std::string> &);
        std::string getValue(std::vector<std::string> &);
};

#endif