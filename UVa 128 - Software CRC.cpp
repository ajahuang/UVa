#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

static const int g = 34943;

int main()
{    
    string m;
    while (getline(cin, m), m != "#")
    {
        // Horner's method.
        int n = 0;
        for (size_t i = 0; i < m.length(); ++i)
            n = (m[i] + (n << 8)) % g;

        // (n << 16) might be larger than 2^31 - 1.
        n = ((long long)n << 16) % g;
        int CRC = (g - n) % g;
        cout << hex << uppercase << setw(2) << setfill('0')
             << (CRC >> 8) 
             << " " 
             << hex << uppercase << setw(2) << setfill('0')
             << (CRC & 255) 
             << endl;
    }
    return 0;
}