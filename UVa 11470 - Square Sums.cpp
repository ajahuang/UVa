#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int n, Case = 1;
    while (cin >> n, n != 0)
    {
        cout << "Case " << Case++ << ":";

        vector<vector<int> > grid(n, vector<int>(n));
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                cin >> grid[r][c];

        for (int i = 0; i < n / 2; ++i)
        {
            int sum = 0;
            for (int j = i; j < n - 1 - i; ++j)
            {
                sum += grid[i][j] 
                       + grid[j][n - 1 - i]
                       + grid[n - 1 - i][n - 1 - j]
                       + grid[n - 1 - j][i];
            }
            cout << " " << sum; 
        }
        if (n % 2 == 1)
            cout << " " << grid[n / 2][n / 2];
        cout << endl;
    }
    return 0;
}