#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Street
{
    int u, v, length;
};

bool comp(const Street &s1, const Street &s2)
{
    return s1.length < s2.length;
}

int getGroup(const vector<int> &groups, int u)
{
    return groups[u] == u? 
        u : getGroup(groups, groups[u]);
}

int main()
{  
    int m, n;
    while (cin >> m >> n, !(m == 0 && n == 0))
    {
        vector<Street> streets;
        vector<int> groups(m);
        int streetCount = 0;
        int originalCost = 0, cost = 0;

        for (int i = 0; i < n; ++i)
        {
            Street st;
            cin >> st.u >> st.v >> st.length;
            streets.push_back(st);
            originalCost += st.length;
        }

        sort(streets.begin(), streets.end(), comp);
        for (int i = 0; i < m; ++i)
            groups[i] = i;

        // Kruskal's algorithm.    
        for (size_t i = 0; i < streets.size() && streetCount < m - 1; ++i)
        {
            Street &st = streets[i];
            int groupU = getGroup(groups, st.u);
            int groupV = getGroup(groups, st.v);
            if (groupU != groupV)
            {
                cost += st.length;
                groups[groupV] = groupU;
                ++streetCount;
            }
        }
        cout << originalCost - cost << endl;
    }
    return 0;
}