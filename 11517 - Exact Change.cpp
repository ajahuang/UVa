#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_PRICE = 10000;

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int p, n;
        cin >> p >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; ++i)
            cin >> coins[i];

        // dp[i] stores the total number of coins and bills used
        // for paying i cents.
        vector<int> dp(MAX_PRICE + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = MAX_PRICE; j >= 0; --j)
            {
                if (dp[j] 
                    && j + coins[i] <= MAX_PRICE)
                {
                    // Minimize the number of coins and bills.
                    dp[j + coins[i]] = (dp[j + coins[i]] == 0 ?
                                        dp[j] + 1 :
                                        min(dp[j + coins[i]], dp[j] + 1));
                }
            }
            if (dp[coins[i]] == 0)
                dp[coins[i]] = 1;
        }
        vector<int>::iterator iter(find_if(dp.begin() + p, 
                                           dp.end(),
                                           bind2nd(greater<int>(), 0)));
        cout << iter - dp.begin() << " " << *iter << endl;
    }
    return 0;
}