#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        size_t r;
        cin >> r;
        vector<int> streets(r);
        for (size_t i = 0; i < r; ++i)
            cin >> streets[i];

        sort(streets.begin(), streets.end());
        
        int median = streets[streets.size() / 2];
        int distance = 0;
        for (size_t i = 0; i < r; ++i)
            distance += (median >= streets[i]? 
                         median - streets[i] : streets[i] - median);

        cout << distance << endl;
    }
    return 0;
}