#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    size_t Case = 1;
    string bitString;
    while (cin >> bitString)
    {
        size_t n;
        cin >> n;
        cout << "Case "
             << Case++
             << ":" 
             << endl;
        while ( n-- )
        {
            size_t i, j;
            cin >> i >> j;
            if (i > j)
                swap(i, j);
            // Get the sub-string between position i and j.
            string subString = bitString.substr(i, j - i + 1);
            if (subString.size() <= 1 
                || unique(subString.begin(), subString.end()) == 
                   subString.begin() + 1
                )
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
    return 0;
}