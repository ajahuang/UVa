#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int n;
    while (cin >> n, n != 0)
    {
        vector<int> original(n), target(n);
        for (int i = 0; i < n; ++i)
            cin >> original[i] >> target[i];

        sort(original.begin(), original.end());
        sort(target.begin(), target.end());
 
        if (original == target)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}