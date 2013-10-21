#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool isPalindrome(const string &s)
{
    string r_s(s);
    reverse(r_s.begin(), r_s.end());
    return s == r_s;
}

int main()
{  
    string s;
    while (cin >> s)
    {
        map<string, int> memo;
        int c = 0;
        for (size_t i = 0; i < s.size(); ++i)
            for (size_t j = i; j < s.size(); ++j)
            {
                string subString = s.substr(i, j - i + 1);
                if (!memo.count(subString)
                    && isPalindrome(subString))
                {
                    ++c;
                    ++memo[subString];
                }
            }
        cout << "The string '"
             << s
             << "' contains "
             << c
             << " palindromes."
             << endl;
    }
    return 0;
}