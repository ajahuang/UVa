#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int S[10];
int D;
int dp[10][1 << 10][1024];

int search(int idx, int bitMask, int sum)
{
    if (idx == N)
        return sum % D == 0? 1 : 0;

    // Key ideas:
    // 1. 123 % 10 = 100 % 10 + 20 % 10 + 3 % 10
    // 2. Suppose S is 123456 and we got 10 permutations for 
    //    123400. Then 432100 has also 10 permutations if
    //    432100 % D has the same value with 123400 % D.
    if (sum < 1024 
        && dp[idx][bitMask][sum] != -1)
        return dp[idx][bitMask][sum];

    int nPermu = 0;
    bool used[10] = {0};
    for (int i = 0; i < N; ++i)
    {
        if (bitMask & (1 << i))
            continue;
        if (used[S[i]])
            continue;
        used[S[i]] = true;

        nPermu += search(idx + 1,
                         bitMask | (1 << i),
                         (sum + (long long)(pow(10.0, idx) + 1e-9) * S[i]) % D);
    }

    if (sum < 1024)
        dp[idx][bitMask][sum] = nPermu;

    return nPermu;
}

int solve()
{
    memset(dp, -1, sizeof(dp));
    return search(0, 0, 0);
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        string s;
        cin >> s >> D;
        
        N = (int)s.size();
        for (int i = 0; i < s.size(); ++i)
            S[i] = s[i] - '0';

        cout << solve() << endl;
    }
    return 0;
} 