#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{  
    string s;
    getline(cin, s);
    istringstream ss(s);
    size_t T;
    ss >> T;
    while ( T-- )
    {
        getline(cin, s);
        ss.clear();
        ss.str(s);
        map<char, int> pieces;
        while (ss >> s)
        {
            for (int i = 0; i <= 1; ++i)
                ++pieces[s[i]];
        }
        // If the number of male connectors equals that of female,
        // then the pieces can form a simple loop.
        if (pieces['M'] > 1 && pieces['M'] == pieces['F'])
            cout << "LOOP" << endl;
        else
            cout << "NO LOOP" << endl;
    }
    return 0;
}