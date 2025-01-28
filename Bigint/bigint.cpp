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

std::string Bigint::substraction_loop(int i, int j, Bigint const& obj)
{
    std::string result;
    int carry = 0;
    bool is_negative = false;

    // Determine if the result will be negative
    if (*this < obj) {
        is_negative = true;
        std::swap(i, j);
    }

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? digits[i--] - '0' : 0;
        int digit2 = (j >= 0) ? obj.digits[j--] - '0' : 0;
        int sum = digit1 - digit2 + carry;
        if (sum < 0) {
            carry = -1;
            sum += 10;
        } else {
            carry = 0;
        }
        result.push_back(sum + '0');
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    if (is_negative) {
        result = "-" + result;
    }
    return result;
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
    return result;
}

bool Bigint::operator<(const Bigint& other) const {
    // Compare lengths first
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }

    // Compare digit by digit
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }

    // They are equal
    return false;
}