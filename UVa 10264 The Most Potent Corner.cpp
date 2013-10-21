#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int N;
    while (cin >> N)
    {
        vector<int> weights;
        for (int corner = 0; corner < 1 << N; ++corner)
        {
            int weight;
            cin >> weight;
            weights.push_back(weight);
        }
        // Compute each corner's potency.
        vector<int> potencies;
        for (int corner = 0; corner < 1 << N; ++corner)
        {
            int potency = 0;
            // "Potency of the corner is the sum of weights of all neighbouring corners."
            for (int digit = 0; digit < N; ++digit)
                potency += weights[corner ^ (1 << digit)] ;
            potencies.push_back(potency);
        }
        // Find the maximum potencies sum.
        int maxPotencySum = 0;
        for (int corner = 0; corner < 1 << N; ++corner)
        {
            for (int digit = 0; digit < N; ++digit)
                maxPotencySum = max(maxPotencySum, potencies[corner] + potencies[corner ^ (1 << digit)]);
        }
        cout << maxPotencySum << endl;
    }
    return 0;
}