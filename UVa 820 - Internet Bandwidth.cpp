#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const int MAX_BANDWIDTH = 1000;

// Return the minimal bandwidth of the path from s to v.
int augment(vector<vector<int> >       &adjMatrix,
            const vector<int>          &prev,
            int                         minBandwidth,
            int                         v, 
            int                         s)
{
    int u = prev[v];
    minBandwidth = min(minBandwidth, adjMatrix[u][v]);

    if (u != s)
        minBandwidth = augment(adjMatrix, prev, minBandwidth, u, s);

    adjMatrix[u][v] -= minBandwidth;
    adjMatrix[v][u] += minBandwidth;
    return minBandwidth;
}

int main()
{    
    int Case = 1, n;
    while (cin >> n, n != 0)
    {
        vector<vector<int> > adjMatrix(n + 1, vector<int>(n + 1, 0));
        
        int s, t, c;
        cin >> s >> t >> c;
        for (int i = 1; i <= c; ++i)
        {
            int u, v, bandwidth;
            cin >> u >> v >> bandwidth;
            // "There might be more than one connection between a pair of nodes."
            adjMatrix[u][v] += bandwidth;
            adjMatrix[v][u] += bandwidth;
        }

        int maxFlow = 0;
        while (maxFlow == maxFlow)
        {
            // Do BFS to find a path from s to t.
            // Each edge in the path must have bandwidth > 0.
            vector<int> prev(n + 1, -1); // The path.
            queue<int> q;
        
            prev[s] = s;
            q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= n; ++v)
                    if (adjMatrix[u][v] > 0 && prev[v] == -1)
                    {
                        prev[v] = u;
                        q.push(v);
                    }
            }
            if (prev[t] == -1)
                break;

            maxFlow += augment(adjMatrix, prev, MAX_BANDWIDTH, t, s);
        }
        cout << "Network " << Case++ << endl;
        cout << "The bandwidth is " << maxFlow << "." << endl << endl;
    }
    return 0;
}