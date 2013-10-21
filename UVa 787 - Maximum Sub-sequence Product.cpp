#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

static const int PLUS  =  1;
static const int MINUS = -1;

struct BigInt
{
    int     sign;
    string  digits;
    // Contruct with a long integer.
    BigInt(long long i)
    {
        stringstream ss;
        ss << i;
        digits = ss.str();
        handleSignAndReverse();
    }
    // Contruct with a string.
    BigInt(const string &s): digits(s)
    {
        handleSignAndReverse();
    }
    // Contruct with filling c.
    BigInt(size_t size, char c): digits(size, c), sign(PLUS)
    {}
   
    void handleSignAndReverse()
    {
        // sign is default to MINUS.
        sign = MINUS;
        if (digits.size() > 0
            && digits[0] == '-')
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
    if (a.digits == "")
        return b;
    else if (b.digits == "")
        return a;

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

int main()
{  
    string s;
    while (cin >> s)
    {
        // pos and neg store current positive and negative products.
        BigInt pos("");
        BigInt neg("");
        BigInt ans("-999999");

        // O(n) linear scan, Similar to the spirit of Jay Kadane's algorithm.
        do
        {
            BigInt n(s);
            if (n.digits == "0")
            {
                if (bigIntCompare()(ans, BigInt("0")))
                    ans = BigInt("0");
                // Reset pos and neg.
                pos = BigInt("");
                neg = BigInt("");
                continue;
            }
            else if (n.sign == MINUS)
            {
                BigInt temp(neg);
                neg = pos == BigInt("")? 
                             n : bigIntMultiPly(pos, n);
                pos = temp == BigInt("")? 
                              BigInt("") : bigIntMultiPly(temp, n);
            }
            else
            {
                neg = neg == BigInt("")? 
                             BigInt("") : bigIntMultiPly(neg, n);
                pos = bigIntMultiPly(pos, n);
            }
            if (bigIntCompare()(ans, neg))
                ans = neg;
            if (bigIntCompare()(ans, pos))
                ans = pos;
        } while (cin >> s, s != "-999999");

        cout << ans << endl;
    }
    return 0;
}