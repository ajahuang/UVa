#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second < p2.second;
}

int main()
{  
    size_t Case = 1;
    size_t T;
    cin >> T;
    while ( T-- )
    {
        vector<pair<string, int> > pages(10);
        for (size_t i = 0; i < 10; ++i)
            cin >> pages[i].first >> pages[i].second;

        sort(pages.begin(), pages.end(), comp);
        // Locate the first page of the highest relevance.
        vector<pair<string, int> >::iterator iter = 
            lower_bound(pages.begin(), pages.end(), pages.back(), comp);
        cout << "Case #"
             << Case++
             << ":"
             << endl;
        for (; iter != pages.end(); ++iter)
            cout << iter->first << endl;
    }
    return 0;
}