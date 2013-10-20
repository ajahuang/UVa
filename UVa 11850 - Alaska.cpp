#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{  
    size_t n;
    while (cin >> n, n > 0)
    {
        // Delta Juntion has no charing station, so make Brenda have 100 more
        // miles to drive for the last distance.
        vector<int> stations(1, 1422 + 100);
        for (size_t i = 0; i < n; ++i)
        {
            int dist;
            cin >> dist;
            stations.push_back(dist);
        }
        // Using sort() and adjacent_difference() would solve this problem easily.
        sort(stations.begin(), stations.end());
        vector<int> diffs(stations.size());
        adjacent_difference(stations.begin(), stations.end(), diffs.begin());

        if (*max_element(diffs.begin(), diffs.end()) > 200)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << "POSSIBLE" << endl;
    }
    return 0;
}