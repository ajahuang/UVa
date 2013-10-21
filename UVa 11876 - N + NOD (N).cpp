#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
using namespace std;

const int MAX_VALUE = 1000000;
int NOD[MAX_VALUE + 1];

int main()
{  
    // Scan and compute NOD[] by all factors <= MAX_VALUE.
    memset(NOD, 0, sizeof NOD);
    for (int factor = 1; factor <= MAX_VALUE; ++factor)
        for (int i = factor; i <= MAX_VALUE; i += factor)
            ++NOD[i];

    // Compute seq[] by the equations.
    vector<int> seq(MAX_VALUE + 1, 0);
    seq[0] = 1;
    for (int i = 1; i <= MAX_VALUE; ++i)
        seq[i] = seq[i - 1] + NOD[seq[i - 1]];

    int Case = 1;
    int T;
    cin >> T;
    while ( T-- )
    {
        int A, B;
        cin >> A >> B;
        cout << "Case " << Case++ << ": "; 
        cout << distance(lower_bound(seq.begin(), seq.end(), A), 
                         upper_bound(seq.begin(), seq.end(), B))
             << endl;        
    }
    return 0;
}