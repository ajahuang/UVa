#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int BLACK = 0;
static const int WHITE = 1;
static const int UNKNOWN = 2;

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int v, e;
        cin >> v >> e;
        
        vector<vector<int> > G(v);
        vector<int> color(v, UNKNOWN);
        bool isBipartite = true;
        
        while ( e-- )
        {
            int f, t;
            cin >> f >> t;
            G[f].push_back(t);
            G[t].push_back(f);
        }

        int totalCount = 0;
        for (int j = 0; j < G.size() && isBipartite; ++j)
        {
            if (color[j] != UNKNOWN)
                continue;

            queue<int> q;
            int count[2] = {0};
            color[j] = BLACK;
            ++count[color[j]];
            q.push(j);
            while (!q.empty() && isBipartite)
            {
                int u = q.front();
                q.pop();
                for (int i = 0; i < G[u].size(); ++i)
                {
                    int v = G[u][i];
                    if (color[v] == color[u])
                    {
                        isBipartite = false;
                        break;
                    }
                    else if (color[v] == UNKNOWN)
                    {
                        color[v] = 1 - color[u]; 
                        ++count[color[v]];
                        q.push(v);
                    }
                }
            }
            // Each connected component needs at least 1 guard.
            totalCount += max(1, min(count[BLACK], count[WHITE]));
        }

        if (isBipartite)
            cout << totalCount << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}