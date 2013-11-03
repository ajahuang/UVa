#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

static const int V = 100;

struct Elevator
{
    int id;   // Elevator id;
    int from;
    int to;
    int cost;
    // For std::priorty_queue.
    bool operator>(const Elevator &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{    
    int n, k;
    while (cin >> n >> k)
    {
        vector<vector<Elevator> > elevators(V);
        vector<int> time(n + 1);

        for (int id = 1; id <= n; ++id)
            cin >> time[id];

        cin.ignore();
        for (int id = 1; id <= n; ++id)
        {
            string s;
            vector<int> floors;
            int floor;

            getline(cin, s);
            stringstream ss(s);
            while (ss >> floor)
                floors.push_back(floor);
            // Enumerate all pairs of different floors.
            for (size_t j = 0; j < floors.size(); ++j)
                for (size_t k = j + 1; k < floors.size(); ++k)
                {
                    Elevator e;
                    e.id = id;
                    e.cost = 0;
                    // floors[j] to floors[k].
                    e.from = floors[j];
                    e.to = floors[k];      
                    elevators[floors[j]].push_back(e);
                    // floors[k] to floors[j].
                    e.from = floors[k];
                    e.to = floors[j];
                    elevators[floors[k]].push_back(e);
                }
        }

        // Dijkstra's algorithm using min-heap.
        priority_queue<Elevator, vector<Elevator>, greater<Elevator> > pq;
        vector<int> shortest(V, - 1);
        vector<int> id(V, -1);
   
        Elevator e;
        e.from = 0;
        e.to = 0;
        e.cost = 0;
        shortest[0] = 0;
        pq.push(e);
        while (!pq.empty())
        {
            Elevator u = pq.top();
            pq.pop();
            // Lazy deletion.
            if (shortest[u.to] != u.cost)
                continue;
            // Expand the floor.
            for (size_t i = 0; i < elevators[u.to].size(); ++i)
            {
                Elevator v = elevators[u.to][i];
                int alt = shortest[v.from] + abs(v.to - v.from) * time[v.id];
                // Switch to another elevator.
                if (id[v.from] != -1 
                    && id[v.from] != v.id)
                {
                    alt += 60;
                }
                if (shortest[v.to] == -1
                    || alt < shortest[v.to])
                {
                    shortest[v.to] = alt;
                    v.cost = alt;
                    id[v.to] = v.id;
                    pq.push(v);
                }
            }
        }
        if (shortest[k] == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << shortest[k] << endl;
    }
    return 0;
}