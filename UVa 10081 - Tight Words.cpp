#include <iostream>
#include <cmath>
#include <cstring>
#include <numeric>
#include <iomanip>
using namespace std;

int K, N;
double dp[105][10];

double solve()
{
    memset(dp, 0, sizeof (dp));

    for (int i = 0; i <= K; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= N; ++i)
        for (int j = 0; j <= K; ++j)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            else if (j == K)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];;
        }

    
    return 100.0 * accumulate(dp[N], dp[N] + K + 1, 0.0) / pow((double)K + 1, N);
}

int main()
{   
    
    while (cin >> K >> N)
    {
        cout << setprecision(5) << fixed << solve() << endl;
    }
    return 0;
}
