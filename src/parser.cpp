#include "../include/parser.hpp"
#include "../include/definition.hpp"
#include "../include/core.hpp"
#include <regex>
#include <fstream>
#include <iostream>
#include <functional>
#include "../include/Error.hpp"
#include <string.h>

void eraseComments(std::string &str);
const eOperandType strOp(std::string str);


std::vector<std::string> Parser::readFile(char *filename)
{
    std::vector<std::string> lines;
    std::fstream myFile;
    std::string line;
    myFile.open(filename, std::fstream::in);
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            eraseComments(std::ref(line));
            if (line.empty() == true)
                continue;
            lines.push_back(line);
        }
        myFile.close();
    } else
    {
        throw Error("Filepath isn't readable");
    }
    return (lines);    
}


std::vector<std::string> Parser::readPrompt(void)
{
    std::vector<std::string> lines;
    std::string command;

    while (std::getline(std::cin, command) && command.compare(";;"))
    {
        eraseComments(std::ref(command));
        if (command.empty() == true)
            continue;
        lines.push_back(command);
        fflush(stdin);
    }
    if (command.compare(";;"))
        throw Error("Double semicolon missing");
    return (lines);
}

std::vector<std::string> Parser::getInstruction(std::string &command)
{
    std::vector<std::string> parsed;
	std::regex syn_reg("([ \t]+)?((add|pop|dump|sub|mul|div|mod|print|exit|swap|clear|dup)|((push|assert|load|store)-?[ \t]+((int(8|16|32)[(]-?[0-9]+[)])|(float|double|bigdecimal)[(]-?[0-9]+(.[0-9]+)?[)])))([ \t]+)?");
    char *toks;

    if (!regex_match(command, syn_reg))
        throw Error("Syntax error");
    toks = strtok((char *)command.c_str(), " \t()");
    while (toks != NULL)
    {
        parsed.push_back((std::string)toks);
        toks = strtok(NULL, " \t()");
    }
    return (parsed);
}

eOperandType Parser::getOpType(std::vector<std::string> &parsed)
{
    int j = 0;
    eOperandType op;

    for (auto it_p = parsed.begin(); it_p != parsed.end(); it_p++, j++)
    {
        if (j == 1)
        {
            op = strOp(*it_p);
            return (op);
        }
    }
    return (eOperandType(0));
}

std::string Parser::getValue(std::vector<std::string> &parsed)
{
    int j = 0;
    std::string value;

    for (auto it_p = parsed.begin(); it_p != parsed.end(); it_p++, j++)
    {
        if (j == 2)
        {
            value = *it_p;
            return (value);
        }
    }
    return (std::string(""));
}
