#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_N = 35;

int main()
{    
    int Case = 0, n;
    while (cin >> n)
    {
        vector<vector<int> > streets(MAX_N, vector<int>(MAX_N, 0));
        int N = 0;

        for (int i = 1; i <= n; ++i)
        {
            int u, v;
            cin >> u >> v;
            streets[u][v] = 1;
            N = max(max(u, v), N);
        }

        for (int k = 0; k <= N; ++k)
            for (int i = 0; i <= N; ++i)
                for (int j = 0; j <= N; ++j)
                    if (streets[i][k] && streets[k][j])
                        streets[i][j] += streets[i][k] * streets[k][j];

        for (int k = 0; k <= N; ++k)
            // If k -> k is a cycle, then i -> k -> j must have infinite paths.
            if (streets[k][k])
                for (int i = 0; i <= N; ++i)
                    for (int j = 0; j <= N; ++j)
                        if (streets[i][k] && streets[k][j])
                            streets[i][j] = -1;

        cout << "matrix for city " << Case++ << endl;
        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j <= N; ++j)
            {
                cout << (j > 0? " " : "") 
                     << streets[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}