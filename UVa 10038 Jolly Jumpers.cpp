#include <iostream>
#include <string>
#include <vector>
#include <cmath> 
#include <map> 
using namespace std;

int main()
{   
    int n;
    while (cin >> n)
    {
        vector<int> sequence;
        for (int i = 1; i <= n; ++i)
        {
            int integer;
            cin >> integer;
            sequence.push_back(integer);
        }
        vector<int>::iterator iter(sequence.begin() + 1);
        map<int, int> memo;
        bool jolly = true;
        for ( ; iter != sequence.end(); ++iter)
        {
            // "absolute values of the difference between successive elements.."
            int diff  = abs(*iter - *(iter - 1));
            if (diff > n - 1)
            {
                jolly = false;
                break;
            }
            ++memo[diff];
        }
        // "..take on all the values 1 through n-1."
        if (jolly && memo.size() == n - 1)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}