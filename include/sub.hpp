#ifndef _SUBINF_HPP_
#define _SUBINF_HPP_

#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include "add.hpp"

class Sub {
    public:
        Sub();
        ~Sub() {};
        std::string subinf(std::string number_one, std::string number_two);

    protected:
    private:
        std::string decimalHandler(std::string &number_one, std::string &number_two, std::size_t &decimalMax);
        std::string processing(std::string &number_one, std::string &number_two);
        bool checkSign(std::string &number_one, std::string &number_two);
        bool isNegativ(std::string number_one, std::string number_two);

        std::string _addResult;
        bool _isAdd;
        Add addFactory;
};

#endif
