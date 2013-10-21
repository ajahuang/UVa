#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int X;
    vector<int> values;
    while (cin >> X)
    {
        values.push_back(X);
        nth_element(values.begin(), 
                    values.begin() + values.size() / 2, 
                    values.end());

        // Using values[values.size() / 2] would be wrong if values.size() is 1.
        int m1 = *(values.begin() + values.size() / 2);
        int m2 = m1;
        // If size is even, then call nth_element to find the other middle number.
        if (values.size() % 2 == 0)
        {
            nth_element(values.begin(), 
                        values.begin() + values.size() / 2 - 1, 
                        values.end());
            m2 = *(values.begin() + values.size() / 2 - 1);
        }
        // "you have to print only the integer part, not the fractional."
        cout << (m1 + m2) / 2 << endl;
    }
    return 0;
}