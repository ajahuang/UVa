#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

static const int N = 20;
static const int INF = N * N;

int main()
{    
    int TEST = 1, n;
    while (cin >> n)
    {
        // sp: shortest path.
        vector<vector<int> > sp(N + 1, vector<int>(N + 1, INF));
        for (int i = 1; i <= N; ++i)
            sp[i][i] = 0;

        int u = 1;
        do
        {
            for (int i = 1; i <= n; ++i)
            {
                int v;
                cin >> v;
                sp[u][v] = 1;
                sp[v][u] = 1;
            }
            if (++u > 19)
                break;
        } while (cin >> n);

        // Floyd¡VWarshall algorithm.
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);

        cout << "Test Set #" << TEST++ <<endl;
        cin >> n;
        while ( n-- )
        {
            int s, t;
            cin >> s >> t;
            cout << right << setw(2)
                 << s
                 << " to "
                 << right << setw(2)
                 << t
                 << ": "
                 << left
                 << sp[s][t]
                 << endl;
        }
        cout << endl;
    }
    return 0;
}