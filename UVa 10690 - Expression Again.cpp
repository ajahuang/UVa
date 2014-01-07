#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool dp[100 + 5][100 * 100 + 5];

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<int> ints(N + M + 1);
        int sum = 0;
        for (int i = 1; i <= N + M; ++i)
        {
            cin >> ints[i];
            sum += ints[i];
            // Shift all integers by +50.
            ints[i] += 50;
        }
        
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        // If dp[i][j] is true, that means it is possible to
        // use i out of the N + M integers to sum to j.
        for (int i = 1; i <= N + M; ++i)
            for (int k = min(i, N); k >= 1; --k)
                for (int j = 0; j <= 10000; ++j)
                    if (dp[k - 1][j])
                        dp[k][j + ints[i]] = true;
 
        int maximum = -5000;
        int minimum = 5000;
        for (int i = 0; i <= 10000; ++i)
            if (dp[N][i])
            {
                int nSum = i - 50 * N;
                maximum = max(maximum, nSum * (sum - nSum));
                minimum = min(minimum, nSum * (sum - nSum));
            }
        
        cout << maximum << " " << minimum << endl;
    }
}