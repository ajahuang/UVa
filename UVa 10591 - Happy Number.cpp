#include <iostream>
#include <map>
using namespace std;

int f(int n)
{
    int sum = 0;
    while (n)
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int main()
{
    int T, Case = 1;
    cin >> T;
    while ( T-- )
    {
        int N, n;
        cin >> N;
        n = N;

        map<int, int> memo;
        while (memo.count(n) == 0
               && n != 1)
        {
            memo[n] = 1;
            n = f(n);
        }
        cout << "Case #" << Case++ << ": " << N;
        if (n == 1)
            cout << " is a Happy number." << endl;
        else
            cout << " is an Unhappy number." << endl;
    }
    return 0;
}
