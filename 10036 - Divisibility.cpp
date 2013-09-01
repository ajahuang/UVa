#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_K = 100;
 
int main()
{   
    int M;
    cin >> M;
    while ( M-- )
    {
        int N, K;
        cin >> N >> K;

        // remainders[indexAnswer][remainder] is true if the sequence is divisble 
        // by remainder.
        vector<vector<bool> > remainders(2, vector<bool>(MAX_K, false));
        int indexTemp = 0, indexAnswer = 1;
        // 0 is reachable for empty sequence.
        remainders[indexTemp][0] = remainders[indexAnswer][0] = true;
        for (int i = 1; i <= N; ++i)
        {
            swap(indexTemp, indexAnswer);
            remainders[indexAnswer].assign(MAX_K, false);

            int integer;
            cin >> integer;

            /** If the current sequence is divisible by remainder, then adding integer 
                or -integer will reach two new remainders. So, for each integer, scan
                remainder from 0 to K - 1 and set reachable remainders accordingly. */
            for (int remainder = 0; remainder < K; ++remainder)
            {
                if (remainders[indexTemp][remainder])
                {
                    remainders[indexAnswer][(remainder + (integer % K) + K) % K] = true;  
                    remainders[indexAnswer][(remainder + (-integer % K) + K) % K] = true;  
                }
            }
        }
        cout << (remainders[indexAnswer][0]? "Divisible" : "Not divisible") 
             << endl;
    }
    return 0;
}