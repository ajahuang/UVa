#include <iostream>
#include <cstring>
using namespace std;

/**
    memo[i][j] stores the number of symbols that the ith bar ends at 
    the jth unit.
*/
long long memo[64][64];

int main()
{
    int n, k, m;
    while (cin >> n >> k >> m)
    {
        memset(memo, 0, sizeof memo);
        // There is only 1 symbol that the 1st bar ends at any unit
        // equal or less than n and m.
        for (int unit = 1; unit <= n && unit <= m; ++unit)
            memo[1][unit] = 1;
        
        // Every memo[bar][unit] can be reached by adding one bar of
        // at most m units wide.
        for (int bar = 2; bar <= k; ++bar)
            for (int unit = bar; unit <= n; ++unit)
                for (int wide = 1; wide <= m && unit > wide; ++wide)
                    memo[bar][unit] += memo[bar - 1][unit - wide];
        
        cout << memo[k][n] << endl;
    }
    return 0;
}

