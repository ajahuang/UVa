#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int BITSET_SIZE = 20000000;
bitset<BITSET_SIZE> isPrime;

int main()
{    
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);

    // Maximal int is 2,147,483,647, larger than 20,000,000.
    vector<pair<int, int> > twinPrimes;
    int lastPrime = 2;

    for (unsigned n = 2; n < BITSET_SIZE; ++n)
    {
        if (isPrime[n])
        {
            // Need to handle n * n carefully.
            if ((unsigned long long)n * n < BITSET_SIZE)
            {
                for (int m = n * n; m < BITSET_SIZE; m += n)
                    isPrime.reset(m);
            }

            if (n - lastPrime == 2)
                twinPrimes.push_back(pair<int, int>(lastPrime, n));
            
            lastPrime = n;
        }
    }

    int S;
    while (cin >> S)
    {
        cout << "("
             << twinPrimes[S - 1].first
             << ", "
             << twinPrimes[S - 1].second
             << ")"
             << endl;
    }
    return 0;
}