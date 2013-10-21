#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

static const int MAX_VALUE = 300;

int main()
{  
    // dp[i][j] stores the number of ways i dollars can be
    // paid using 0..j coins.
    typedef unsigned long long ull_t;
    vector<vector<ull_t> > dp(MAX_VALUE + 1, 
                              vector<ull_t>(MAX_VALUE + 1, 0));
    // Base cases.
    for (int j = 0; j <= MAX_VALUE; ++j)
        dp[0][j] = 1;
    for (int i = 1; i <= MAX_VALUE; ++i)
        for (int j = 1; j <= MAX_VALUE; ++j)
            dp[i][j] = dp[i][j - 1] + (i >= j? dp[i - j][j] : 0);
        
    string s;
    while (getline(cin, s))
    {
        vector<int> N;
        stringstream ss(s);
        int input;
        while (ss >> input)
            N.push_back(input);

        int L1, L2;
        switch(N.size())
        {
        case 1:
            L1 = 0;
            L2 = N[0];
            break;
        case 2:
            L1 = 0;
            L2 = N[1];
            break;
        default:
            L1 = N[1];
            L2 = N[2];
        }
        // Can be improved by checking cases like 
        // 0 100 200
        if (N[0] == 0)
            cout << "1" << endl;
        else
            cout << dp[N[0]][min(300, L2)] - dp[N[0]][min(300, max(0, L1 - 1))] << endl;
    }
    return 0;
}