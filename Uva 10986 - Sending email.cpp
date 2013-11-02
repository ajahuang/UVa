#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;

struct Cable
{
    int u, v;
    int latency;
  
    // For std::priority_queue.
    bool operator>(const Cable &c) const
    {
        return this->latency > c.latency;
    }
};

int main()
{  
    int Case = 1, N;
    cin >> N;
    while ( N-- )
    {
        int n, m, S, T;
        map<int, vector<Cable> > cables;
        map<int, int> dist;

        cin >> n >> m >> S >> T;
        for (int i = 0; i < m; ++i)
        {
            Cable cable;
            cin >> cable.u >> cable.v >> cable.latency;
            cables[cable.u].push_back(cable);
            swap(cable.u, cable.v);
            cables[cable.u].push_back(cable);
        }

        // Dijkstra's algorithm using min-heap.
        priority_queue<Cable, vector<Cable>, greater<Cable> > pq;

        Cable s;
        s.u = S;
        s.v = S;
        s.latency = 0;
        pq.push(s);
        dist[S] = 0;
        while (!pq.empty())
        {
            Cable e1 = pq.top();
            pq.pop();
            // Lazy deletion: if dist[e1.v] is smaller, that means e1.v 
            // has been visited already. 
            if (dist[e1.u] + e1.latency > dist[e1.v])
                continue;
            for (size_t i = 0; i < cables[e1.v].size(); ++i)
            {
                Cable e2 = cables[e1.v][i];
                // Push the edge.
                if (!dist.count(e2.v)
                    || dist[e2.u] + e2.latency < dist[e2.v])
                {
                    dist[e2.v] = dist[e2.u] + e2.latency;
                    pq.push(e2);
                }
            }
        }
        cout << "Case #"
             << Case++
             << ": ";
        if (dist.count(T))
            cout << dist[T] << endl;
        else
            cout << "unreachable" << endl;
    }
    return 0;
}