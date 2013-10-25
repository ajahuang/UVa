#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

static const int UNVISITED = 0;

vector<vector<int> > network;
// DFS
int dfsRoot;
int rootChildren;
int dfsCounter = 1;
vector<int> dfsNum;
vector<int> dfsLow;
vector<int> dfsParent;
// Articulation Vertices
vector<bool> artiVertices; 

void DFS(int u)
{
    dfsNum[u] = dfsLow[u] = dfsCounter++;
    for (int i = 0; i < network[u].size(); ++i)
    {
        int v = network[u][i];
        if (dfsNum[v] == UNVISITED)
        {
            dfsParent[v] = u;
            if (u == dfsRoot)
                ++rootChildren;
            DFS(v);

            // If u is not the root and its child v has no back edge
            // to reach u (meaning there is no cycle), then u is an
            // articulation vertex since it is able to isolate v.
            if (u != dfsRoot && dfsLow[v] >= dfsNum[u])
                artiVertices[u] = true;

            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        // Edge to the parent is not a back edge.
        else if (v != dfsParent[u]) 
            dfsLow[u] = min(dfsLow[u], dfsNum[v]); 
    }
}

int main()
{  
    int N;
    while (cin >> N, N != 0)
    {
        cin.ignore();

        network.clear();
        network.resize(N + 1);
        dfsNum.clear();
        dfsNum.resize(N + 1, UNVISITED);
        dfsLow.clear();
        dfsLow.resize(N + 1, UNVISITED);
        dfsParent.clear();
        dfsParent.resize(N + 1, UNVISITED);

        artiVertices.clear();
        artiVertices.resize(N + 1, false);

        string s;
        while (getline(cin, s), s != "0")
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v)
            {
                network[u].push_back(v);
                network[v].push_back(u);
            }
        }
        // Loop over all places.
        for (int p = 1; p < network.size(); ++p)
        {
            if (dfsNum[p] == UNVISITED)
            {
                dfsRoot = p;
                rootChildren = 0;
                DFS(p);
                if (rootChildren > 1)
                    artiVertices[dfsRoot] = true;
            }
        }
        cout << count(artiVertices.begin(), artiVertices.end(), true) << endl;
    }
    return 0;
}