#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int N, M;
int dp[100 + 5][(1 << 10) + 5][10 + 5];

int search(int idx, int bitMask, int lastDigit)
{
    if (idx > M)
        return 0;

    if (dp[idx][bitMask][lastDigit] != -1)
        return dp[idx][bitMask][lastDigit];

    int nBeautifulNumbers = 0;

    // If all of the digits from 0 to N-1 are used.
    if (bitMask == ((1 << N) - 1))
        ++nBeautifulNumbers;

    for (int nextDigit = lastDigit - 1; nextDigit <= lastDigit + 1; nextDigit += 2)
    {
        if (nextDigit < 0 || nextDigit >= N)
            continue;

        nBeautifulNumbers += search(idx + 1, bitMask | (1 << nextDigit), nextDigit);
        nBeautifulNumbers %= MOD;
    }

    return dp[idx][bitMask][lastDigit] = nBeautifulNumbers;
}

int solve()
{
    memset(dp, -1, sizeof(dp));
    int nBeautifulNumbers = 0;
    for (int firstDigit = 1; firstDigit <= N - 1; ++firstDigit)
    {
        nBeautifulNumbers += search(1, 1 << firstDigit, firstDigit);
        nBeautifulNumbers %= MOD;
    }
    return nBeautifulNumbers;
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        cin >> N >> M;
        cout << solve() << endl;
    }
    return 0;
} 