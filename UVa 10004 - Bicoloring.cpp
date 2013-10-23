#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int BLACK = 0;
static const int WHITE = 1;
static const int UNKNOWN = 2;

int main()
{  
    int n;
    while (cin >> n, n != 0)
    {
        vector<vector<int> > G(n);
        vector<int> color(n, UNKNOWN);
        bool isBipartite = true;
        
        int l;
        cin >> l;
        while ( l-- )
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        queue<int> q;
        // Since the graph is strongly connected, we can reach all the
        // vertices starting from any vertex.
        color[0] = BLACK;
        q.push(0);
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
                    q.push(v);
                }
            }
        }
        if (isBipartite)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}