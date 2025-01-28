#include <iostream>
#include <algorithm>
#include "bigint.h"
using namespace std;

Bigint::Bigint()
{
    negative = false;
    digits = "0";
}

Bigint::Bigint(int n)
{
    negative = n < 0;
    digits = std::to_string(negative ? -n : n);
}

Bigint::Bigint(string s)
{
    negative = s[0] == '-';
    digits = negative ? s.substr(1) : s;
}

std::string Bigint::to_string() const
{
    return (negative ? "-" : "") + digits;
}
Bigint Bigint::operator+(Bigint const& obj)
{
    std::string result;
    int digitsize1 = digits.size() - 1;
    int digitsize2 = obj.digits.size() - 1;
    if (negative == obj.negative){
        result = addition_loop(digitsize1, digitsize2, obj);
    }
    else{
        result = substraction_loop(digitsize1, digitsize2, obj);
    }
    return Bigint(result);
  
}
std::string  Bigint::substraction_loop(int i, int j, Bigint const& obj)
{
    std::string result;
    int carry = 0;
    if (negative == obj.negative) {
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? digits[i--] - '0' : 0;
            int digit2 = (j >= 0) ? obj.digits[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
            std::reverse(result.begin(), result.end());
            result = (negative ? "-" : "") + result;
            return result;
        }
}
std::string Bigint::addition_loop(int i, int j, Bigint const& obj)
{   
    std::string result;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? digits[i--] - '0' : 0;
        int digit2 = (j >= 0) ? obj.digits[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
        std::reverse(result.begin(), result.end());
        result = (negative ? "-" : "") + result;
        return result;

    return result;
}