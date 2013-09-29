#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum { NO_INSERT, INSERT_RIGHT, INSERT_LEFT };
typedef vector<vector<int> > vvi_t;

string palindrome(const string  &s, 
                  const vvi_t   &path,
                  size_t         i,
                  size_t         j)
{
    string str;
    switch (path[i][j])
    {
    case (-1):
        str = s.substr(i, j - i + 1);
        break;

    case NO_INSERT:
        str = s[i] 
              + palindrome(s, path, i + 1, j - 1) 
              + s[j];
        break;

    case INSERT_RIGHT:
        str =  s[i] 
               + palindrome(s, path, i + 1, j) 
               + s[i];
        break;

    default: // INSERT_LEFT.
        str =  s[j] 
               + palindrome(s, path, i, j - 1) 
               + s[j];
        break;
    }
    return str;
}

int main()
{  
    string s;
    while (cin >> s)
    {
        // dp[i][j] stores the minimum number of characters required to make 
        // s[i..j] a palindrome.
        // Initialize Base cases.
        vvi_t dp(s.size(), vector<int>(s.size(), 0));
        vvi_t path(s.size(), vector<int>(s.size(), -1));
        for (size_t i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 0;
                path[i][i + 1] = NO_INSERT;
            }
            else
            {
                dp[i][i + 1] = 1;
                path[i][i + 1] = INSERT_RIGHT;
            }
        }
        // Bottom-up DP.
        for (size_t len = 2; len < s.size(); ++len)
            for (size_t i = 0; i + len < s.size(); ++i)
            {
                size_t j = i + len;
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                    path[i][j] = NO_INSERT;
                }
                else
                {
                    int insRight = dp[i + 1][j];
                    int insLeft = dp[i][j - 1];
                    if (insRight <= insLeft)
                    {
                        dp[i][j] = 1 + insRight;
                        path[i][j] = INSERT_RIGHT;
                    }
                    else
                    {
                        dp[i][j] = 1 + insLeft;
                        path[i][j] = INSERT_LEFT;
                    }
                }
            }

        cout << dp[0][s.size() - 1]  
             << " "
             << palindrome(s, path, 0, s.size() - 1)
             << endl;
    }
    return 0;
}