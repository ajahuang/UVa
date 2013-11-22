#include <iostream>
#include <cmath>
using namespace std;

int main()
{   
    unsigned long long n, k;
    while (cin >> n >> k)
    {
        // log(C(n, k)) = log(n!/(n - k)!k!)
        //              = log(n!) - log((n - k)!k!)
        long double logSum = 0;
        for (unsigned long long i = n - k + 1; i <= n; ++i)
            logSum += log10((double)i);
        for (unsigned long long i = 1; i <= k; ++i)
            logSum -= log10((double)i);

        cout << (int)logSum + 1 << endl;
    }
    return 0;
}