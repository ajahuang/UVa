#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{  
    int T, Case = 1;
    cin >> T;
    while ( T-- )
    {
        int n, P, Q;
        cin >> n >> P >> Q;
        vector<int> weight(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> weight[i];

        sort(weight.begin(), weight.end());

        int eggs = min(P, n);
        for (int i = 1; i <= min(P, n); ++i)
            if (accumulate(weight.begin() + 1, weight.begin() + 1 + i, 0) > Q)
            {
                eggs = i - 1;
                break;
            }

        cout << "Case "
             << Case++
             << ": "
             << eggs
             << endl;
    }
    return 0;
}