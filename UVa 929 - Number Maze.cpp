#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Edge
{
    int r, c;
    int cost;
    // For std::priority_queue.
    bool operator>(const Edge &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{    
    int T;
    cin >> T;
    while ( T-- )
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int> > maze(N, vector<int>(M));

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < M; ++c)
                cin >> maze[r][c];

        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        vector<vector<int> > cost(N, vector<int>(M, -1));

        // Dijkstra's algorithm using min-heap.
        Edge e;
        e.r = 0;
        e.c = 0;
        e.cost = maze[0][0];
        pq.push(e);
        cost[0][0] = e.cost;
        while (!pq.empty())
        {
            Edge u = pq.top();
            pq.pop(); 
            for (int i = 0; i < 4; ++i)
            {
                int r = u.r + dx[i];
                int c = u.c + dy[i];
                if (r < 0 || r >= N || c < 0 || c >= M)
                    continue;
                if (cost[r][c] == -1
                    || cost[u.r][u.c] + maze[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[u.r][u.c] + maze[r][c];
                    e.r = r;
                    e.c = c;
                    // Store cost[r][c] rather than maze[r][c].
                    e.cost = cost[r][c];
                    pq.push(e);
                }
            }
        }
        cout << cost[N - 1][M - 1] << endl;
    }
    return 0;
}