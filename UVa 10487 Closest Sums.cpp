#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist(int n1, int n2)
{
    return n1 >= n2? n1 - n2 : n2 - n1;
}

int main()
{  
    size_t Case = 1, n;
    while (cin >> n, n > 0)
    {
        cout << "Case " << Case++ << ":" << endl;

        vector<int> numbers(n);
        for (size_t i = 0; i < n; ++i)
            cin >> numbers[i];

        sort(numbers.begin(), numbers.end());

        size_t m;
        cin >> m;
        while ( m-- )
        {
            int query;
            cin >> query;
            size_t L = 0, U = numbers.size() - 1;

            int sum = 0;
            if (numbers[0] != numbers.back())
            {
                sum = numbers[0] + numbers.back();
                // Find a sum as close to query as possible.
                while (L < U)
                {    
                    // "a sum of two distinct numbers"
                    if (numbers[L] != numbers[U]
                        && dist(query, numbers[L] + numbers[U]) 
                           < dist(query, sum))
                    {
                        sum = numbers[L] + numbers[U];
                    }
                    if (numbers[L] + numbers[U] == query)
                        break;
                    else if (numbers[L] + numbers[U] < query)
                        ++L;
                    else 
                        --U;
                }
            }
            cout << "Closest sum to " 
                 << query 
                 << " is "
                 << sum
                 << "."
                 << endl;
        }
    }
    return 0;
}