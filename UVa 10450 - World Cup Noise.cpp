#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    unsigned long long pattern[51];
    pattern[1] = 2;
    pattern[2] = 3;
    for (int i = 3; i < 51; ++i)
        pattern[i] = pattern[i - 1] + pattern[i - 2];

    int T, Case = 1;
    cin >> T;
    while ( T-- )
    {
        cout << "Scenario #" << Case++ << ":" << endl;
        
        int n;
        cin >> n;
        cout << pattern[n] << endl << endl;
    }
    return 0;
}