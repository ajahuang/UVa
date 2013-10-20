#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
using namespace std;

struct comp
{
    bool operator()(const int &n1, const int &n2)
    {
        int mod_n1 = n1 % M;
        int mod_n2 = n2 % M;
        if (mod_n1 < mod_n2)
            return true;
        else if (mod_n1 == mod_n2)
        {
            if (abs(n1 % 2) == 1)
            {
                if (n2 % 2 == 0)
                    return true;
                // "larger odd number will precede the smaller odd number."
                return n1 > n2;
            }
            else if (n1 % 2 == 0)
            {
                // "smaller even number will precede the larger even number."
                if (n2 % 2 == 0)
                    return n1 < n2;
            }
        }
        return false;
    }
    static int M;
};
int comp::M;

int main()
{  
    size_t N;
    while (cin >> N >> comp::M, N > 0 && comp::M > 0)
    {
        vector<int> numbers(N);
        for (size_t i = 0; i < N; ++i)
            cin >> numbers[i];

        sort(numbers.begin(), numbers.end(), comp());
        cout << N << " " << comp::M << endl;
        copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "\n"));
    }
    cout << "0 0" << endl;
    return 0;
}