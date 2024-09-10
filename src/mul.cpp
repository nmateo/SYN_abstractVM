#include "../include/mul.hpp"

std::string Mul::multiply(std::string num1, std::string num2)
{
    int len1 = num1.size(), len2 = num2.size();
    int i_n1 = 0, i_n2 = 0;
    std::vector<int> result(len1 + len2, 0);
    int carry, n1, n2, sum;
    std::string resultFinal = "";

    for (int i = len1 - 1; i >= 0; i--) {
        carry = 0;
        n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >=0; j--) {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";
    while (i >= 0)
        resultFinal += std::to_string(result[i--]);
    return resultFinal;
}



std::string Mul::mult(std::string str1, std::string str2)
{
    //On enlève les "-" pour ne pas fausser les calc de decimal et de connaitre le signe du resultat.
    if ((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-' ))
        std::cout << "-";
    if (str1.at(0) == '-' && str2.at(0) != '-')
            str1 = str1.substr(1);
    else if(str1.at(0) != '-' && str2.at(0) == '-')
        str2 = str2.substr(1);
    else if(str1.at(0) == '-' && str2.at(0) == '-') {
        str1 = str1.substr(1);
        str2 = str2.substr(1);
    }

    std::size_t nbrDec1 = 0, nbrDec2 = 0;
    std::size_t found = str1.find(".");
	std::size_t found2 = str2.find(".");
    bool decimal1;
    bool decimal2;
	if (found != std::string::npos) {
		decimal1 = true;
        nbrDec1 = str1.size() - found - 1;
        str1 = str1.substr(0,found) + str1.substr(found + 1);
    }
	if (found2 != std::string::npos) {
		decimal2 = true;
        nbrDec2 = str1.size() - found - 1;
        str2= str2.substr(0,found2) + str2.substr(found2 + 1);
    }
    std::string final = multiply(str1, str2);
    std::size_t finalDec = nbrDec1 + nbrDec2;
    final = final.substr(0, final.size() - finalDec) + "." + final.substr(final.size() - finalDec);

    return 0;
}
