#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{  
    string s;
    getline(cin, s);
    size_t T;
    istringstream ss(s);
    ss >> T;
    // Skip the first empty line.
    getline(cin, s);
    while ( T-- )
    {       
        vector<string> fragments;
        while (getline(cin, s) && !s.empty())
        {
            ss.clear();
            ss.str(s);
            string fragment;
            ss >> fragment;
            fragments.push_back(fragment);
        }
        
        // Consider all concatenations of any two strings.
        map<string, int> memo;
        for (size_t i = 0; i < fragments.size(); ++i)
            for (size_t j = i + 1; j < fragments.size(); ++j)
            {
                ++memo[fragments[i] + fragments[j]];
                ++memo[fragments[j] + fragments[i]];
            }
        
        // Search for the string of highest count.
        map<string, int>::iterator iter(memo.begin());
        map<string, int>::iterator file(memo.begin());
        for (; iter != memo.end(); ++iter)
        {
            if (iter->second > file->second)
                file = iter;
        }
        cout << file->first << endl;
        if (T)
            cout << endl;
    }
    return 0;
}