#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int T = 1;
    int S;
    while (cin >> S, S >= 0)
    {
        vector<int> problems(13);
        for (int m = 1; m <= 12; ++m)
            cin >> problems[m];
        vector<int> reqProblems(13);
        for (int m = 1; m <= 12; ++m)
            cin >> reqProblems[m];

        cout << "Case " << T++ << ":" << endl;
        for (int m = 1; m <= 12; ++m)
        {
            if (reqProblems[m] > S)
                cout << "No problem. :(" << endl;
            else
            {
                cout << "No problem! :D" << endl;
                S -= reqProblems[m];
            }
            S += problems[m];
        }
    }
    return 0;
}