#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;

const int BITSET_SIZE = 100000;
// Largest U - L = 1000000 so we need to hold 1000001 elements at most.
const int LARGEST_DIFFERENCE = 1000001;
bitset<BITSET_SIZE> isPrime;
bitset<LARGEST_DIFFERENCE> isComposite;
vector<int> primes;

int main()
{    
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);

    for (int n = 2; n < BITSET_SIZE; ++n)
    {
        if (isPrime[n])
        {
            // Need to handle n * n carefully.
            if ((unsigned long long)n * n < BITSET_SIZE)
            {
                for (int m = n * n; m < BITSET_SIZE; m += n)
                    isPrime.reset(m);
            }
            primes.push_back(n);
        }
    }

    int L, U;
    while (cin >> L >> U)
    {
        isComposite.reset();
        for (int i = 0; i < primes.size() && (ll)primes[i] * primes[i] <= U; ++i)
        {
            const int &prime = primes[i];
            ll start = L % prime == 0? L : (ll)L + (prime - L % prime);
            // n has to be a long long because it can be larger than U
            // and U's largest value is 2,147,483,647. 
            for (ll n = start; n <= U; n += prime)
            {
                // Need to check if n is the prime itself.
                if (n != prime)
                    isComposite.set(n - L);
            }
        }
        // 1 is not a prime.
        if (L == 1)
            isComposite.set(0);
     
        ll C1(0), C2(U), D1(0), D2(0);
        ll lastPrime = 0;
        for (ll n = L; n <= U; ++n)
        {
            if (! isComposite[n - L])
            {
                if (lastPrime != 0)
                {
                    if (n - lastPrime < C2 - C1)
                    {
                        C1 = lastPrime;
                        C2 = n;
                    }
                    if (n - lastPrime > D2 - D1)
                    {
                        D1 = lastPrime;
                        D2 = n;
                    }
                }
                lastPrime = n;
            }
        }
        if (C1 == 0)
            cout << "There are no adjacent primes." << endl;
        else 
            cout << C1
                 << ","
                 << C2
                 << " are closest, "
                 << D1
                 << ","
                 << D2
                 << " are most distant." 
                 << endl;
    }
    return 0;
}