#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    size_t t;
    cin >> t;
    while ( t-- )
    {
        size_t n;
        cin >> n;
        vector<int> stores(n);
        for (size_t i = 0; i < n; ++i)
        {
            cin >> stores[i];
        }
        cout << 2 * (*max_element(stores.begin(), stores.end()) 
                     - *min_element(stores.begin(), stores.end()))
             << endl;
    }
    return 0;
}