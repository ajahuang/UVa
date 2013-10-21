#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

static const int MAX_K = 100;

int main()
{  
    int Case = 1, M;
    double unitPrice;
    while (cin >> unitPrice >> M)
    {
        // Get the schemes.
        typedef pair<int, double> scheme_t;
        vector<scheme_t> schemes(M);
        for (int i = 0; i < M; ++i)
            cin >> schemes[i].first >> schemes[i].second;

        // dp[k] stores the the lowest price to get k items.
        vector<double> dp(MAX_K + 1, 0);
        // Base cases.
        for (int k = 1; k <= MAX_K; ++k)
            dp[k] = unitPrice * k;
        for (int i = 0; i < M; ++i)
        {
            int n = schemes[i].first;
            double p = schemes[i].second;
            for (int k = 0; k <= MAX_K - n; ++k)
                // Consider the case
                // 2 22.00
                // 4 40.00
                // For K = 3, $40 is the best deal.
                for (int m = 1; m <= n; ++m)
                    dp[k + m] = min(dp[k + m], dp[k] + p);
        }

        cin.ignore();

        string s; 
        int K;
        getline(cin, s);
        stringstream ss(s);
        cout << "Case " << Case++ << ":" << endl;
        while (ss >> K)
        {
            cout << "Buy " 
                 << K
                 << " for $"
                 << setprecision(2)
                 << fixed
                 << dp[K]
                 << endl;
        }
    }
    return 0;
}