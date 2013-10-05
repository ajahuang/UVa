#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int k;
    while (cin >> k)
    {
        /** 1/k = 1/x + 1/y
            When x and y are equal, they are both 2k.
            
            1/k = 1/(2k) + 1/(2k)
            
            if x is larger than 2k, then y must be smaller than 2k.
            Since y can't be k, we only need to check y in [k+1, 2k]. 
            But how to compute x?

            1/x = 1/k - 1/y
                = (y-k) / (k*y)
            
            So if y-k divides k*y, then x = (k*y) / (y-k).
        */
        vector<pair<int, int> > solutions;
        for (int y = k + 1; y <= 2 * k; ++y)
        {
            if ((k * y) % (y - k) == 0)
                solutions.push_back(make_pair((k * y) / (y - k), y));
        }
        cout << solutions.size() << endl;
        for (size_t i = 0; i < solutions.size(); ++i)
            cout << "1/"
                 << k
                 << " = 1/"
                 << solutions[i].first
                 << " + 1/"
                 << solutions[i].second
                 << endl;    
    }
    return 0;
}