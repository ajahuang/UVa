#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

// A SLOW and LAZY version of division for string.
int SLOWstringMod(string s, int d)
{
    // Loop when the digits of s is more than d's.
    while (s.size() > static_cast<int>(log10(static_cast<double>(d))) + 1)
    {
        // Skip leading zeros.
        if (s[0] == '0')
        {
            s = s.substr(1);
            continue;
        }
        // Find the smallest substring which value is not smaller than d.
        for (size_t len = 1; len <= s.size(); ++len)
        {
            stringstream ss(s.substr(0, len));
            int number;
            ss >> number;
            if (number >= d)
            {
                int r = number % d;
                s = len < s.size()? s.substr(len) : "";
                // If the remainder is larger than 0, concatenate it 
                // to the front of s.
                if (r > 0)
                {
                    ss.str("");
                    ss.clear();
                    ss << r;
                    s = ss.str() + s;
                }
                break;
            }
        }
    }
    // Convert to int and do modulo directly.
    stringstream ss(s);
    int number = 0;
    if (ss.str() != "")
        ss >> number;

    return number % d;
}

bool isLeapYear(string year)
{
    if (SLOWstringMod(year, 400) == 0)
        return true;
    if (SLOWstringMod(year, 4) == 0 
        && SLOWstringMod(year, 100) != 0)
        return true;

    return false;
}

bool isHuluculu(string year)
{
    return SLOWstringMod(year, 15) == 0;
}

bool isBulukulu (string year)
{
    return SLOWstringMod(year, 55) == 0 
           && isLeapYear(year);
}

int main()
{  
    int Case = 1;
    string year;
    while (cin >> year)
    {
        // "A blank line should separate the output for each line of input."
        if (Case++ > 1)
            cout << endl;

        bool ordinary = true;
        if (isLeapYear(year))
        {
            cout << "This is leap year." << endl;
            ordinary = false;
        }
        if (isHuluculu(year))
        {
            cout << "This is huluculu festival year." << endl;
            ordinary = false;
        }
        if (isBulukulu(year))
        {
            cout << "This is bulukulu festival year." << endl;
            ordinary = false;
        }
        if (ordinary)
            cout << "This is an ordinary year." << endl;
    
    }
    return 0;
}