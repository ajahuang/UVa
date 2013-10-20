#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int n;
    while (cin >> n, n > 0)
    {
        vector<vector<int> > matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                int bit;
                cin >> bit;
                matrix[i][j] = bit;
            }

        vector<int> rowSum(n), columnSum(n);
        int oddRowCount = 0, oddColumnCount = 0;
        int oddRow, oddColumn;
        // Scan every row.
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < n; ++j)
            {
                sum += matrix[i][j];
            }
            if (sum % 2 == 1)
            {
                ++oddRowCount;
                oddRow = i;
            }
            rowSum[i] = sum;
        }
        // Scan every column.
        for (int j = 0; j < n; ++j)
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                sum += matrix[i][j];
            }
            if (sum % 2 == 1)
            {
                ++oddColumnCount;
                oddColumn = j;
            }
            columnSum[j] = sum;
        }
        if (oddRowCount == 0 && oddColumnCount == 0)
            cout << "OK" << endl;
        else if (oddRowCount == 1 && oddColumnCount == 1)
            cout << "Change bit (" 
                 << oddRow + 1
                 << "," 
                 << oddColumn + 1
                 << ")" 
                 << endl;
        else
            cout << "Corrupt" << endl;
    }
    return 0;
}