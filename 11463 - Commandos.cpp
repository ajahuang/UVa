#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int INF = 1000;

int main()
{    
    int Case = 1, T;
    cin >> T;
    while ( T-- )
    { 
        int N, R;
        cin >> N >> R;

        vector<vector<int> > buildings(N, vector<int>(N, INF));
        for (int i = 0; i < N; ++i)
            buildings[i][i] = 0;
        for (int i = 0; i < R; ++i)
        {
            int u, v;
            cin >> u >> v;
            buildings[u][v] = 1;
            buildings[v][u] = 1;
        }
        
        // Floyd-Warshall algorithm.
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                   buildings[i][j] = min(buildings[i][j], buildings[i][k] + buildings[k][j]);

        int s, d;
        cin >> s >> d;

        int minTime = 0;
        for (int i = 0; i < N; ++i)
            if (buildings[s][i] != INF 
                && buildings[i][d] != INF)
            {
                minTime = max(minTime, buildings[s][i] + buildings[i][d]);
            }
        cout << "Case " << Case++ << ": " << minTime << endl;
    }
    return 0;
}