#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, cost; 
};

bool comp(const Edge &e1, const Edge &e2)
{
    return e1.cost < e2.cost;
}

int getGroup(const vector<int> &groups, int u)
{
    return groups[u] == u? 
        u : getGroup(groups, groups[u]);
}

int main()
{  
    int T = 0, N;
    while (cin >> N)
    {
        int cost1 = 0, cost2 = 0;
        for (int i = 1; i <= N - 1; ++i)
        {
            int u, v, c;
            cin >> u >> v >> c;
            cost1 += c;
        }
        
        vector<Edge> lines;
        vector<int> groups;
        int K, M;

        cin >> K;
        for (int i = 1; i <= K; ++i)
        {
            Edge e;
            cin >> e.u >> e.v >> e.cost;
            lines.push_back(e);
        }
        cin >> M;
        for (int i = 1; i <= M; ++i)
        {
            Edge e;
            cin >> e.u >> e.v >> e.cost;
            lines.push_back(e);
        }

        sort(lines.begin(), lines.end(), comp);

        for (int i = 0; i <= N; ++i)
            groups.push_back(i);

        // Kruskal's algorithm.
        for (size_t i = 0; i < lines.size(); ++i)
        {
            Edge &e = lines[i];
            int uGroup = getGroup(groups, e.u);
            int vGroup = getGroup(groups, e.v);

            // Skip the edge if it forms a cycle.
            if (uGroup == vGroup)
                continue;

            cost2 += e.cost;
            // Set v to u's group.
            groups[vGroup] = uGroup;
        }
        if (T++)
            cout << endl;
        cout << cost1 << endl
             << cost2 << endl;
    }
    return 0;
}