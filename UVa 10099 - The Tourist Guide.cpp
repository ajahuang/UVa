#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bus
{
    int u, v, limit;
};

bool comp(const Bus &s1, const Bus &s2)
{
    return s1.limit > s2.limit;
}

int getGroup(const vector<int> &groups, int u)
{
    return groups[u] == u? 
        u : getGroup(groups, groups[u]);
}

int main()
{  
    int Case = 1, N, R;
    while (cin >> N >> R, !(N == 0 && R == 0))
    {
        vector<Bus> buses;
        vector<int> groups(N + 1);

        for (int i = 0; i < R; ++i)
        {
            Bus bus;
            cin >> bus.u >> bus.v >> bus.limit;
            // Mr. G. needs a seat for himself.
            --bus.limit;
            buses.push_back(bus);
        }

        int S, D, T;
        cin >> S >> D >> T;

        sort(buses.begin(), buses.end(), comp);
        for (int i = 1; i <= N; ++i)
            groups[i] = i;

        // Kruskal's algorithm.    
        for (int i = 0; i < R; ++i)
        {
            Bus &bus = buses[i];
            int groupU = getGroup(groups, bus.u);
            int groupV = getGroup(groups, bus.v);
            if (groupU != groupV)
            {
                groups[groupV] = groupU;
                if (getGroup(groups, S) == getGroup(groups, D))
                {
                    cout << "Scenario #" 
                         << Case++ 
                         << endl
                         << "Minimum Number of Trips = "
                         << (T + bus.limit - 1) / bus.limit
                         << endl << endl;
                    break;
                }
            }
        }
    }
    return 0;
}