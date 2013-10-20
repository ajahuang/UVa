#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{  
    map<int, int> memo;
    vector<int> sequence;
    int integer;

    while (cin >> integer)
    {
        if (memo[integer] == 0)
            sequence.push_back(integer);

        ++memo[integer];
    }

    for (size_t i = 0; i < sequence.size(); ++i)
        cout << sequence[i] << " " << memo[sequence[i]] << endl;

    return 0;
}