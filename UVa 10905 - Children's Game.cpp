#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

bool comp(const string &s1, const string &s2)
{
    // Suppose s1 = 900, s2 = 9, then it compares
    // 9900 with 9009.
    return s2 + s1 < s1 + s2;
}

int main()
{  
    size_t N;
    while (cin >> N, N > 0)
    {
        vector<string> integers(N);
        for (size_t i = 0; i < N; ++i)
            cin >> integers[i];
        
        sort(integers.begin(), integers.end(), comp);
        cout << accumulate(integers.begin(), integers.end(), static_cast<string>("")) << endl;
    }
    return 0;
}