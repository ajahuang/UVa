#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    size_t Case = 1, N;
    while (cin >> N)
    {
        vector<long long> seq(N);
        for (size_t i = 0; i < N; ++i)
            cin >> seq[i];

        // Try all possibilities.
        long long product = 0;
        for (size_t i = 0; i < seq.size(); ++i)
            for (size_t j = i; j < seq.size(); ++j)
            {
                long long temp = 1;
                for (size_t k = i; k <= j; ++k)
                    temp *= seq[k];

                product = max(product, temp);
            }
        
        cout << "Case #"
             << Case++
             << ": The maximum product is "
             << product
             << "."
             << endl
             << endl;
    }
    return 0;
}