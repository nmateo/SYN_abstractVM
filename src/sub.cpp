#include "../include/sub.hpp"

Sub::Sub() {
    this->_isAdd = false;
}

bool Sub::isNegativ(std::string number_one, std::string number_two)
{
    if (number_one.size() < number_two.size())
        return true;
    if (number_two.size() < number_one.size())
        return false;
    for (size_t i = 0; i < number_one.size(); i++) {
        if (number_one.at(i) < number_two.at(i))
            return true;
        else if (number_one.at(i) > number_two.at(i))
            return false;
    }
    return false;
}

bool Sub::checkSign(std::string &number_one, std::string &number_two)
{
    std::size_t signCounter = 0;

    if (number_one.at(0) == '-')
        signCounter++;
    if (number_two.at(0) == '-')
        signCounter++;
    if (signCounter == 1) {
        this->_isAdd = true;
        this->_addResult = this->addFactory.add(number_one, number_two);
        return false;
    }
    else if (signCounter == 2) {
        std::reverse(number_one.begin(), number_one.end());
        number_one.pop_back();
        std::reverse(number_one.begin(), number_one.end());

        std::reverse(number_two.begin(), number_two.end());
        number_two.pop_back();
        std::reverse(number_two.begin(), number_two.end());

        return true;
    }
    return false;
}

std::string Sub::processing(std::string &number_one, std::string &number_two)
{
    std::string::const_iterator it1 = number_one.end() - 1;
    std::string result = "";
    int detention = 0;

    for (std::string::const_iterator it2 = number_two.end() - 1; it2 != number_two.begin() - 1; it1--, it2--) {
        if ((( *it1 - '0') - ( *it2 -'0' ) - detention) < 0) {
            result.push_back((10 + ( *it1 - '0') - ( *it2 -'0' ) - detention) + '0');
            detention = 1;
        } else {
            result.push_back((( *it1 - '0') - ( *it2 -'0' ) - detention) + '0');
            detention = 0;
        }
    }

    for (; it1 != number_one.begin() - 1; it1--) {
        if ( *it1 =='0' && detention == 1)  {
            result.push_back('9');
            continue;
        }
        if (it1 != number_one.begin() || ((*it1 - '0') - detention) > 0)
            result.push_back(((*it1 - '0') - detention) + '0');
        detention = 0;
    }

    return result;
}

std::string Sub::decimalHandler(std::string &number_one, std::string &number_two, std::size_t &decimalMax)
{
    std::string decimal1 = "";
    std::string decimal2 = "";
    std::string decimalResult = "";

    std::size_t found1 = number_one.find(".");
    if (found1 != std::string::npos)
        decimal1 = number_one.substr(found1 + 1);

    std::size_t found2 = number_two.find(".");
    if (found2 != std::string::npos)
        decimal2 = number_two.substr(found2 + 1);

    if (found2 != std::string::npos && found1 != std::string::npos) {
        for (size_t i = decimal1.length(); i < decimal2.length(); i++)
            number_one.push_back('0');
        for (size_t i = decimal2.length(); i < decimal1.length(); i++)
            number_two.push_back('0');
        if (decimal1.length() > decimal2.length())
            decimalMax = decimal1.length();
        else
            decimalMax = decimal2.length();
    }
    if (found2 != std::string::npos && found1 == std::string::npos) {
        decimalResult = decimal2;
        number_two = number_two.substr(0, found2);
    }
    if (found1 != std::string::npos && found2 == std::string::npos) {
        decimalResult = decimal1;
        number_one = number_one.substr(0, found1);
    }

    return decimalResult;
}

std::string Sub::subinf(std::string number_one, std::string number_two)
{
    int len1 = number_one.length();
    int len2 = number_two.length();
    bool negativ = false;
    bool inverseSign = false;
    std::string result = "";
    std::string decimalResult = "";
    std::size_t decimalMax = 0;

    inverseSign = checkSign(number_one, number_two);
    if (this->_isAdd == true)
        return this->_addResult;
    decimalResult = decimalHandler(number_one, number_two, decimalMax);
    negativ = isNegativ(number_one, number_two);
    if (negativ)
        std::swap(number_one, number_two);
    result = processing(number_one, number_two);
    if (inverseSign)
        negativ = !negativ;
    if (negativ && *result.end() != '0')
        result.push_back('-');
    std::reverse(result.begin(), result.end());
    if (decimalMax != 0)
        result.at(result.size() - decimalMax - 1) = '.';
    if (decimalResult != "")
        result += '.' + decimalResult;

    return result;
}
