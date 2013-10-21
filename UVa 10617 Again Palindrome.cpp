#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<long long> > vvi_t;

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        string s;
        cin >> s;
        // dp[i][j] stores the number of subsequences of s[i..j] 
        // that are palidromes.
        vvi_t dp(s.size(), vector<long long>(s.size(), 1));
        // Initialize Base cases.
        for (size_t i = 0; i < s.size() - 1; ++i)
            dp[i][i + 1] = (s[i] == s[i + 1]? 3 : 2);

        // Bottom-up DP.
        for (size_t len = 2; len < s.size(); ++len)
            for (size_t i = 0; i + len < s.size(); ++i)
            {
                size_t j = i + len;
                //  1. i              j
                //  2. i [i+1... j-1] j <= cancelled out with 3 + 4.
                //  3.[i ....... j-1]      
                //  4.   [i+1 ....... j]
                if (s[i] == s[j])
                    dp[i][j] = 1 + dp[i][j - 1] + dp[i + 1][j];
                //  1.[i ............ j-1]
                //  2.  [i+1 ............ j]
                //      [i+1 ........ j-1]  <= added twice
                else
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }

        cout << dp[0][s.size() - 1] << endl;
    }
    return 0;
}