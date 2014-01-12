#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

int N;
int F[250 + 5];
int sum[250 + 5][250 + 5];
int dp[250 + 5][250 + 5];;

int solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            dp[i][j] = numeric_limits<int>::max();

    for (int interval = 1; interval < N; ++interval)
        for (int i = 1; i + interval <= N; ++i)
        {
            // Try to take each node between i and j as the root
            // and store the minimum cost in dp[i][j].
            int j = i + interval;
            for (int root = i; root <= j; ++root)
                dp[i][j] = min(dp[i][j],
                               dp[i][root - 1] + dp[root + 1][j] 
                                   + sum[i][j] - F[root]);
        }

    return dp[1][N];
}

int main()
{
    while (cin >> N)
    {
        for (int i = 1; i <= N; ++i)
        {
            cin >> F[i];
            sum[i][i] = F[i];
            for (int j = 1; j <= i - 1; ++ j)
                sum[j][i] = sum[j][i - 1] + F[i];
        }
        cout << solve() << endl;
    }
    return 0;
} 