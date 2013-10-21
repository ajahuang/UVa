#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main()
{    
    ull N;
    while (cin >> N, N != 0)
    {
        // Backup N since we are going to work on N directly.
        ull NBackUp = N;

        vector<ull> factors;
        vector<int> powers;
        for (ull f = 2; f * f <= N; ++f)
        {
            int p = 0;
            while (N % f == 0)
            {
                ++p;
                N /= f;
            }
            // If f is N's prime factor, its power p must be larger than 0.
            if (p > 0)
            {
                factors.push_back(f);
                powers.push_back(p);
            }
        }
        // If N is a prime number itself.
        if (N > 1)
        {
            factors.push_back(N);
            powers.push_back(1);
        }

        /**
            Loop over each factor to compute N's LCM cardinality.
            For example,

            Suppose N = 12 = 2^2 * 3
            Then C = (2 * 3) + (1 * 1) + 1 = 8

            where the last 1 is the pair (12, 12).
            Refer to the explanation at http://www.algorithmist.com/index.php/UVa_10892.
        */
        ull C = 0;
        for (size_t i = 0; i < factors.size(); ++i)
        {
            ull sum = powers[i];
            for (size_t j = i + 1; j < factors.size(); ++j)
            {
                sum *= 2 * powers[j] + 1;
            }
            C += sum;
        }
        C += 1;
        
        cout << NBackUp << " " << C << endl;
    }
    return 0;
}