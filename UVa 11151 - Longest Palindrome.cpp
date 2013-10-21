#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    cin.ignore();
    while ( T-- )
    {
        string s;
        getline(cin, s);

        if (s == "")
        {
            cout << "0" << endl;
            continue;
        }

        // dp[i][j] stores the length of the longest palindrome from 
        // string A[i..j].
        // Initialize base cases.
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 1));
        for (int i = 0; i < s.size() - 1; ++i)
            dp[i][i + 1] = (s[i] == s[i + 1]? 2 : 1); 

        // Bottom-up DP.
        for (int len = 2; len < s.size(); ++len)
            for (int i = 0; i + len < s.size(); ++i)
            {
                int j = i + len;
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        cout << dp[0][s.size() - 1] << endl;
    }
    return 0;
}