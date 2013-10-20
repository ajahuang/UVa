#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{   
    int set = 1;
    int n;
    while (cin >> n, n > 0)
    {
        vector<int> stacks;
        for (int i = 0; i < n; ++i)
        {
            int stack;
            cin >> stack;
            stacks.push_back(stack);
        }
        // Compute the average height.
        int average = accumulate(stacks.begin(), stacks.end(), 0) / n;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            if (stacks[i] > average)
                k += stacks[i] - average;
        }
        cout << "Set #" << set++ << endl;
        cout << "The minimum number of moves is "
             << k 
             << "."
             << endl    
             << endl; // Output a blank line after each set
    }
    return 0;
}