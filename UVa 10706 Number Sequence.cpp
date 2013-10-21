#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Return the number of digits of k.
size_t nDigits(size_t k)
{
    return static_cast<size_t>(log10(static_cast<double>(k)) + 0e-9) + 1;
}

int main()
{  
    vector<size_t> S(1, 0);
    S.push_back(1);
    size_t digitCount = 1;
    for (size_t k = 2; ; ++k)
    {
        digitCount += nDigits(k);
        S.push_back(S.back() + digitCount);
        // "1 <= i <= 2147483647"
        if (S.back() + digitCount >= 2147483647)
            break;
    }

    size_t t;
    cin >> t;
    while ( t-- )
    {
        size_t i;
        cin >> i;

        size_t L = 0, U = S.size() - 1, d = 1;
        while (L <= U)
        {
            size_t m = (L + U) / 2; 
            if (S[m] < i)
            {
                d = i - S[m];
                L = m + 1;
            }
            else
                U = m - 1;
        }
        // Locate the integer where the dth digit resides.
        size_t integer = 1;
        while (d > nDigits(integer))
            d -= nDigits(integer++);
        // Get the value of the digit.
        d = nDigits(integer) - d + 1;
        size_t value = 0;
        while (d--)
        {
            value = integer % 10;
            integer /= 10;
        }
        cout << value << endl;
    }
    return 0;
}