#ifndef _MUL_HPP_
#define _MUL_HPP_

#include <string>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

class Mul {
    public:
        Mul() {};
        ~Mul() {};
        std::string mult(std::string str1, std::string str2);
    private:
        std::string multiply(std::string num1, std::string num2);
};

#endif
