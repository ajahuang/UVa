#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int N;
int W[100 + 5];
long long dp[450 * 100 + 5];

void solve()
{
    int sum = accumulate(W + 1, W + N + 1, 0);
    
    // If (dp[i] << j) & 1 is 1, that means it is possible
    // to select j out of the N people so that the sum of
    // their weight is i.
    memset(dp, 0, sizeof(dp));
    dp[0] = 1 << 0;
        
    for (int i = 1; i <= N; ++i)
        for (int j = sum; j >= 0; --j)
            if (dp[j])
                dp[j + W[i]] |= dp[j] << 1;
    
    int minDiff = 450 * 100;
    int teamOneWeight = 0, teamTwoWeight = 0;
    for (int i = 0; i <= sum; ++i)
        if (dp[i] & (1ll << (N / 2)))
        {
            int diff = abs(i - (sum - i));
            if (diff < minDiff)
            {
                minDiff = diff;
                teamOneWeight = min(i, sum - i);
                teamTwoWeight = max(i, sum - i);
            }
        }
    cout << teamOneWeight << " " << teamTwoWeight << endl;
}

int main()
{
    int T, Case = 0;
    cin >> T;
    while ( T-- )
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> W[i];
        
        if (++Case > 1)
            cout << endl;
        solve();
    }
}