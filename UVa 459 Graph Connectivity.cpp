#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi_t;
typedef vector<vi_t> vvi_t;

const int UNVISITED = 0;
const int VISITED = 1;

void dfs(const vvi_t &G, 
         vi_t        &dfsNum,
         int          u)
{
    dfsNum[u] = VISITED;
    for (int j = 0; j < (int)G[u].size(); ++j)
    {
        int v = G[u][j];
        if (dfsNum[v] == UNVISITED)
            dfs(G, dfsNum, v);
    }
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        char c;
        int nNodes;
        cin >> c;
        nNodes = c - 'A' + 1;
        cin.ignore();

        vvi_t G(nNodes);
        vi_t dfsNum(nNodes, UNVISITED);
        string s;
        while (getline(cin, s) && s != "")
        {
            // G is an undirected graph.
            G[s[0] - 'A'].push_back(s[1] - 'A');
            G[s[1] - 'A'].push_back(s[0] - 'A');
        }
        // Use DFS to find connected components.
        int nCC = 0;
        for (int i = 0; i < nNodes; ++i)
        {
            if (dfsNum[i] == UNVISITED)
            {
                ++nCC;
                dfs(G, dfsNum, i);
            }
        }
        cout << nCC << endl;
        if (T)
            cout << endl;
    }
    return 0;
}