#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        do
        {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }
    return 0;
}