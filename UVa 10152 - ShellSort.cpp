#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

map<string, int> position;

bool comp(const string &s1, const string &s2)
{
    return position[s1] > position[s2];
}

int main()
{  
    int K;
    cin >> K;
    while ( K-- )
    {
        int n;
        cin >> n;        
        cin.ignore();
        
        vector<string> turtles(n), ordering(n);
        for (int i = 0; i < n; ++i)
            getline(cin, turtles[i]);
        position.clear();
        for (int i = 0; i < n; ++i)
        {
            getline(cin, ordering[i]);
            position[ordering[i]] = i;
        }
        /** For example,
            original: 1 2 3 4 5
            desired:  2 3 1 4 5

            (1)ops.push_back(1), shift = 1
            Done.
        */
        int shift = 0;
        vector<string> ops;
        for (int i = n - 1; i >= 0; --i)
            if (i + shift != position[turtles[i]])
            {
                ops.push_back(turtles[i]);
                ++shift;
            }

        sort(ops.begin(), ops.end(), comp);
        copy(ops.begin(), ops.end(), ostream_iterator<string>(cout, "\n"));
        cout << endl;
    }
    return 0;
}