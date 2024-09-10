#include "../include/add.hpp"
#include "../include/sub.hpp"

std::string Add::findSum(std::string str1, std::string str2)
{
    int n1;
    int n2;
	int carry = 0;

	if (str1.size() > str2.size())
		std::swap(str1, str2);
	std::string str = "";
	n1 = str1.size();
    n2 = str2.size();
	std::reverse(str1.begin(), str1.end());
	std::reverse(str2.begin(), str2.end());

	for (int i = 0; i < n1; i++) {
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}
	for (int i = n1; i < n2; i++) {
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum/10;
	}
	if (carry)
		str.push_back(carry + '0');
	std::reverse(str.begin(), str.end());
	return str;
}


std::string Add::findSumforOneDec(std::string str1, std::string str2, bool decimal1, bool decimal2)
{
	std::string result;
	std::string entier;
	std::string decimal;
	std::string after_decimal;

	if (decimal1 == true) {
		entier = str2;
		decimal = str1;
	}
	else {
		decimal = str2;
		entier = str1;
	}
	after_decimal = decimal.substr(decimal.find("."));
	decimal = decimal.substr(0, decimal.find("."));
	result = findSum(decimal, entier);
	result = result + after_decimal;
	return result;
}

std::string Add::add0(std::string toChange, std::size_t nbr)
{
	size_t nbrof0 = nbr - toChange.size();

	while (nbrof0 != 0) {
		toChange += "0";
		nbrof0--;
	}
	return toChange;
}

std::string Add::findSumDec(std::string str1, std::string str2)
{
	std::string entier1, entier2, decimal1, decimal2;
	std::string sum, sumDec;
	std::size_t savePlaceDec;

	entier1 = str1.substr(0, str1.find("."));
	decimal1 = str1.substr(str1.find(".") + 1);
	entier2 = str2.substr(0, str2.find("."));
	decimal2 = str2.substr(str2.find(".") + 1);
	if (decimal1.size() > decimal2.size())
		decimal2 = add0(decimal2, decimal1.size());
	else if (decimal1.size() < decimal2.size())
		decimal1 = add0(decimal1, decimal2.size());
	savePlaceDec = decimal1.size();
	sum = findSum(entier1, entier2);
	sumDec = findSum(decimal1, decimal2);
	if (sumDec.size() == savePlaceDec)
		return (sum + "." + sumDec);
	else {
		sum = findSum(sum, "1");
		return (sum + "." + sumDec.substr(1, sumDec.size()));
	}
}

std::string Add::epur(std::string base)
{
	while (base.back() == '0' && base.back() != '.') {
		base = base.substr(0, base.size() - 1);
	}
	if (base.back() == '.')
		base = base.substr(0, base.size() - 1);
	return base;
}

std::string Add::soustraction(bool menus1, bool menus2, std::string str1, std::string str2)
{
	Sub *sub = new Sub();
	std::string result;
	if (menus1 == true && menus2 == false) {
		result = sub->subinf(str2, str1);
		delete sub;
		return result;
	}
	else if (menus1 == false && menus2 == true) {
		result = sub->subinf(str1, str2);
		delete sub;
		return result;
	}
	return "";
}

std::string Add::add(std::string str1, std::string str2)
{
	std::string result;
	bool menus1 = false, menus2 = false;
	bool decimal1 = false, decimal2 = false;

	if (str1.front() == '-')
		menus1 = true;
	if (str2.front() == '-')
		menus2 = true;
	if ((menus1 == true && menus2 == false) || (menus1 == false && menus2 == true))
		return epur(soustraction(menus1, menus2, str1, str2));
	std::size_t found = str1.find(".");
	std::size_t found2 = str2.find(".");
	if (found!=std::string::npos)
		decimal1 = true;
	if (found2!=std::string::npos)
		decimal2 = true;
	if (decimal1 == false && decimal2 == false)
		result = findSum(str1, str2);
	else if ((decimal1 == false && decimal2 == true) || (decimal1 == true && decimal2 == false))
		result = findSumforOneDec(str1, str2, decimal1, decimal2);
	else
		result = findSumDec(str1, str2);
	result = epur(result);
	if (menus1 == true && menus2 == true)
		return ("-" + result);
    return result;
}
