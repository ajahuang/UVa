#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Return true if all c's neighbors were never visited.
bool isOrdered(char                           c,
               const vector<vector<char> >   &adjList,
               map<char, bool>               &visited)
{
    for (int i = 0; i < adjList[c].size(); ++i)
        if (visited[adjList[c][i]])
            return false;
    return true;
}

void printOrderings(const vector<char>            &vars,
                    const vector<vector<char> >   &adjList,
                    map<char, bool>               &visited,
                    const string                  &ordering)
{
    if (ordering.length() == vars.size())
        cout << ordering << endl;

    for (int i = 0; i < (int)vars.size(); ++i)
    {
        char c = vars[i];
        if (! visited[c] && isOrdered(c, adjList, visited))
        {
            visited[c] = true;
            printOrderings(vars, adjList, visited, ordering + c);
            visited[c] = false;
        }
    }
}

int main()
{  
    int T = 0;
    string s;
    while (getline(cin, s))
    {
        vector<char> vars;
        vector<vector<char> > adjList(sizeof(char) * (1 << 8));
        map<char, bool> visited;
        stringstream ss(s);
        char c;
        while (ss >> c)
            vars.push_back(c);

        // "Orderings are printed in lexicographical (alphabetical) order."
        sort(vars.begin(), vars.end());

        getline(cin, s);
        ss.clear();
        ss.str(s);
        char x, y;
        while (ss >> x >> y)
           adjList[x].push_back(y);

        if (T++)
            cout << endl;
        printOrderings(vars, adjList, visited, ""); 
    }
    return 0;
}