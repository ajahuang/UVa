#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum flag_t { UNVISITED, VISITED };

void dfs(map<char, vector<char> >       &adjList,
         map<char, flag_t>              &flags,
         vector<char>                   &order,
         char                            c)
{
    flags[c] = VISITED;
    for (int i = 0; i < adjList[c].size(); ++i)
    {
        char v = adjList[c][i];
        if (flags[v] == UNVISITED)
            dfs(adjList, flags, order, v);
    }
    order.push_back(c);
}

int main()
{  
    string ps, s;
    map<char, vector<char> > adjList;
    map<char, flag_t> flags;
    cin >> ps;
    while (cin >> s, s != "#")
    {
        // pad ps and s with spaces. 
        ps.append(20 - ps.size(), ' ');
        s.append(20 - s.size(), ' ');
        for (int i = 0; i < 20; ++i)
            if (s[i] != ps[i])
            {
                adjList[ps[i]].push_back(s[i]);
                flags[ps[i]] = UNVISITED;
                flags[s[i]] = UNVISITED;
                break;
            }
        ps = s;
    }

    // Topological sort.
    vector<char> order;
    map<char, vector<char> >::iterator iter(adjList.begin());
    for (; iter != adjList.end(); ++iter)
        if (flags[iter->first] == UNVISITED)
            dfs(adjList, flags, order, iter->first);
        
    for (int i = (int)order.size() - 1; i >= 0; --i)
        if (order[i] != ' ')
            cout << order[i];
    cout << endl;
    return 0;
}