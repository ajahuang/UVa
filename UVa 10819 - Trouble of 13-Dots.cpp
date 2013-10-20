#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int m, n;
    while (cin >> m >> n)
    {
        vector<int> P(n), F(n); 
        for (size_t i = 0; i < n; ++i)
            cin >> P[i] >> F[i];

        int U = m;
        if (U > 1800)
            U += 200;

        // dp[i] stores the maximum favour value of spending exactly 
        // $i. Consider the case:
        //  1900 3 
        //  2000 5 
        //  1950 1 *
        //  101  1 *
        // The answer is 2 not 5 because even if 13-Dots has $1900
        // she must spend more than $2000 to get the $200 refund.
        vector<int> dp(U + 1, 0); 
        for (int i = 0; i < n; ++i)
            for (int j = U; j >= P[i]; --j) 
            {
                if (dp[j - P[i]] > 0 || j == P[i])
                    dp[j] = max(dp[j], dp[j - P[i]] + F[i]);
            }

        int maxF = 0; 
        // If 13-Dots has money between $1801 and $2000, check $2001
        // up to U.
        if (m >= 1801 && m <= 2000)
        {
            maxF = *max_element(dp.begin(), dp.begin() + m);
            for (int j = 2001; j <= U; ++j)
                maxF = max(maxF, dp[j]);
        }
        else
            maxF = *max_element(dp.begin(), dp.end());

        cout << maxF << endl;
    }
    return 0;
}