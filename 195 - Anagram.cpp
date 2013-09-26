#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 'A' < 'a' < 'b'
bool comp(char c1, char c2)
{
    return ::tolower(c1) == ::tolower(c2)?
           c1 < c2 : tolower(c1) < tolower(c2);
}

int main()
{  
    size_t T;
    cin >> T;
    while ( T-- )
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), comp);
        do
        {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), comp));
    }
    return 0;
}