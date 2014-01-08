/** 
    struct BigInt for big integers using std::string.

    @author Aja Huang
    @date   2013
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BigInt
{
public:
    // Contruct from a long integer. 
    BigInt(long long n);
    // Contruct from a string.
    BigInt(const string &s);
    // Contruct by filling a number.
    BigInt(size_t size, int n);

    // Operators.
    BigInt operator*(BigInt &rhs);
    BigInt operator*(int rhs);
    BigInt operator/(BigInt &rhs);
    BigInt operator/(int rhs);
    bool operator<(const BigInt &rhs) const;
    bool operator==(const BigInt &rhs) const;

    friend BigInt operator*(BigInt &bI, long long n);
    friend BigInt operator*(long long n, BigInt &bI);
    friend BigInt operator/(BigInt &bI, long long n);
    friend BigInt operator/(long long n, BigInt &bI);
    friend ostream &operator<<(ostream &os, BigInt bI);

private:
    const int PLUS  =  1;
    const int MINUS = -1;
    
    init();
    
    int     sign;
    string  digits;
};
  
BigInt::BigInt(long long n)
{
    stringstream ss;
    ss << n;
    digits = ss.str();
    init();
}

BigInt::BigInt(const string &s)
    : digits(s)
{
    init();
}

void BigInt::init()
{
    if (digits[0] == '-')
    {
        sign = MINUS;
        digits = digits.substr(1);
    }
    else
        sign = PLUS;

    reverse(digits.begin(), digits.end());
}

    bool operator==(const BigInt &a) const
    {
        return (digits == a.digits
                && sign == a.sign);
    }
};

ostream &operator<<(ostream &os, BigInt a)
{
    reverse(a.digits.begin(), a.digits.end());
    os << (a.sign == MINUS? "-" : "")
       << a.digits;
    return os;
}

// Return a * b;
BigInt bigIntMultiPly(const BigInt &a, const BigInt &b)
{
    // c = a * b.
    BigInt c(a.digits.size() + b.digits.size(), '0');
    c.sign = (a.sign == b.sign? PLUS : MINUS);
    size_t i = 0, j = 0;
    for (; i < a.digits.size(); ++i)
    {
        int carry = 0;
        for (j = 0; j < b.digits.size(); ++j)
        {
            int sum = (a.digits[i] - '0') * (b.digits[j] - '0') 
                      + (c.digits[i + j] - '0') + carry;
            c.digits[i + j] = '0' + (sum % 10);
            carry = sum / 10;
        }
        c.digits[i + j] = static_cast<char>('0' + carry);
    }
    // Remove c's leading 0s.
    while (c.digits.size() > 1
           && c.digits[c.digits.size() - 1] == '0')
    {
        c.digits.erase(c.digits.size() - 1);
    }
    return c;
}

struct bigIntCompare
{
    // Return if a < b.
    bool operator()(const BigInt &a, const BigInt &b) const
    {
        // If a or b is "", then they are not comparable.
        if (a.digits == "" || b.digits == "") return false;

        if (a.sign == MINUS && b.sign == PLUS) return true;
        if (a.sign == PLUS && b.sign == MINUS) return false;

        if (a.digits.size() > b.digits.size()) return a.sign == MINUS;
        if (b.digits.size() > a.digits.size()) return a.sign == PLUS;

        BigInt c(a);
        BigInt d(b);
        reverse(c.digits.begin(), c.digits.end());
        reverse(d.digits.begin(), d.digits.end());
        for (size_t i = 0; i < c.digits.size(); ++i)
        {
            if (c.digits[i] > d.digits[i]) 
                return c.sign == MINUS;
            if (d.digits[i] > c.digits[i]) 
                return c.sign == PLUS;
        }
        return false;
    }
};
