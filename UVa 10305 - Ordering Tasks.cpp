#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void DFS(vector<bool>               &tasks,
         const vector<vector<int> > &adjList,
         vector<int>                &order,
         int                         t)
{
    tasks[t] = true;
    for (int i = 0; i < adjList[t].size(); ++i)
    {
        int next = adjList[t][i];
        if (! tasks[next])
            DFS(tasks, adjList, order, next);
    }
    order.push_back(t);
}

int main()
{  
    int m, n;
    while (cin >> n >> m, !(n == 0 && m == 0))
    {
        vector<bool> tasks(n + 1, false);
        vector<vector<int> > adjList(n + 1);
        vector<int> order;
        for (int i = 0; i < m; ++i)
        {
            int t1, t2;
            cin >> t1 >> t2;
            adjList[t1].push_back(t2);
        }
        // Typical topological sort.
        for (int t = 1; t <= n; ++t)
            if (! tasks[t])
                DFS(tasks, adjList, order, t);

        copy(order.rbegin(), order.rend(), ostream_iterator<int>(cout, " "));
        cout << endl;     
    }
    return 0;
}