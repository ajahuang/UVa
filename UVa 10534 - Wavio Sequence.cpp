#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LIS[i] stores the maximum length of S's LIS ending at i.
void doLIS(const vector<size_t> &S, vector<size_t> &LIS)
{
    vector<size_t> L(S.size());
    size_t lisCount = 0;
    for (size_t i = 0; i < S.size(); ++i)
    {
        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, S[i])
                     - L.begin();
        L[pos] = S[i];
        if (pos == lisCount)
            ++lisCount;
        LIS[i] = pos + 1;
    }
}

int main()
{  
    size_t N;
    while (cin >> N)
    {
        vector<size_t> S(N);
        for (int i = 0; i < N; ++i)
            cin >> S[i];
        
        vector<size_t> LIS(N), LDS(N);
        doLIS(S, LIS);
        reverse(S.begin(), S.end());
        doLIS(S, LDS);
        reverse(LDS.begin(), LDS.end());

        size_t maxLIS = 0;
        for (size_t i = 0; i < LIS.size(); ++i)
        {
            /** Suppose S[] = 1 3 6 5
                      LIS[] = 1 2 3 3
                      LDS[] = 1 1 2 1
                then we can pick 1 6 5 or 3 6 5.
            */
            maxLIS = max(maxLIS, 2 * min(LIS[i], LDS[i]) - 1);
        }
        cout << maxLIS << endl;
    }
    return 0;
}