#include <iostream>
#include <string>
using namespace std;

static const int P = 131071;

int main()
{    
    string n;
    int v = 0;
    while (getline(cin, n))
    {
        // Horner's method.
        for (size_t i = 0; i < n.length(); ++i)
        {
            if (n[i] == '#')
            {
                cout << (v == 0? "YES" : "NO") << endl;
                v = 0;
            }
            else if (n[i] >= '0' && n[i] <= '9')
                v = ((n[i] - '0') + (v << 1)) % P;
        }
    }
    return 0;
}