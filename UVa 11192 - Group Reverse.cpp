#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    size_t G;
    while (cin >> G, G > 0)
    {
        string s;
        cin >> s;

        string::iterator iter(s.begin());
        size_t groupSize = s.size() / G;

        for ( ; iter != s.end(); iter += groupSize)
            reverse(iter, iter + groupSize);

        cout << s << endl;
    }
    return 0;
}