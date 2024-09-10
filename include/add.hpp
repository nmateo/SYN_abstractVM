#ifndef _ADD_HPP_
#define _ADD_HPP_

#include <string>
#include <algorithm>
#include <iostream>

class Add {
    public:
        Add() {};
        ~Add() {};
        std::string add(std::string str1, std::string str2);
    private:
        std::string soustraction(bool menus1, bool menus2, std::string str1, std::string str2);

        std::string epur(std::string base);
        std::string add0(std::string toChange, std::size_t nbr);

        std::string findSumDec(std::string str1, std::string str2);
        std::string findSumforOneDec(std::string str1, std::string str2, bool decimal1, bool decimal2);
        std::string findSum(std::string str1, std::string str2);
};

#endif
