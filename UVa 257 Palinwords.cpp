#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalinword(const string &s)
{
    // dp[i][j] = true if s[i..j] is a palindrome; 0, otherwise.
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), true));

    for (size_t i = 0; i < s.size() - 1; ++i)
        dp[i][i + 1] = (s[i]== s[i + 1]? true : false);

    // Store the found palindrome s[l..r]. 
    string candidate;
    size_t l = 0, r = s.size() - 1;
    for (size_t len = 2; len < s.size(); ++len)
        for (size_t i = 0; i + len < s.size(); ++i)
        {
            size_t j = i + len;
            // If s[i..j] is a palindrome.
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if (candidate == "")
                {
                    candidate = s.substr(i, len + 1);
                    r = i;
                    l = j;
                }
                // "Neither of these 2 palindromes may be embedded in the other palindrome"
                // Since it loops from smaller lengths, this string must be no shorter than candidate.
                else if (i > r || j < l)
                    if (s.substr(i, len + 1).find(candidate) == string::npos)
                        return true;
            }
            else
                dp[i][j] = false;
        }
    return false;
}

int main()
{  
    string s;
    while (cin >> s)
        if (isPalinword(s))
            cout << s << endl;
        
    return 0;
}