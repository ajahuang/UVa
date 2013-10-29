#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

struct Stone
{
    int x, y;
};

struct Jump
{
    int u, v;
    double distance;
};

double dist(const Stone &s1, const Stone &s2)
{
    return sqrt((double)(s1.x - s2.x) * (s1.x - s2.x) 
                      + (s1.y - s2.y) * (s1.y - s2.y));
}

bool comp(const Jump &s1, const Jump &s2)
{
    return s1.distance < s2.distance;
}

int getGroup(const vector<int> &groups, int u)
{
    return groups[u] == u? 
        u : getGroup(groups, groups[u]);
}

int main()
{  
    int Case = 1, n;
    while (cin >> n, n != 0)
    {
        vector<Stone> stones(n + 1);
        vector<Jump> jumps;
        vector<int> groups(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> stones[i].x >> stones[i].y;

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                Jump jump;
                jump.u = i;
                jump.v = j;
                jump.distance = dist(stones[i], stones[j]);
                jumps.push_back(jump);
            }

        sort(jumps.begin(), jumps.end(), comp);
        for (int i = 1; i <= n; ++i)
            groups[i] = i;

        // Practice Kruskal's algorithm.    
        // Using Floyd Warshall's algorithm would be simpler to solve 
        // this problem.
        for (size_t i = 0; i < jumps.size(); ++i)
        {
            Jump &jump = jumps[i];
            int groupU = getGroup(groups, jump.u);
            int groupV = getGroup(groups, jump.v);
            if (groupU != groupV)
            {
                groups[groupV] = groupU;
                if (getGroup(groups, 1) == getGroup(groups, 2))
                {
                    cout << "Scenario #" << Case++ << endl;
                    cout << "Frog Distance = "
                         << setprecision(3)
                         << fixed
                         << jump.distance
                         << endl
                         << endl;
                    break;
                }
            }
        }
    }
    return 0;
}