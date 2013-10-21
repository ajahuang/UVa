#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{  
    size_t N;
    while (cin >> N, N > 0)
    {
        vector<int> coaches(N);
        for (int i = 0; i < N; ++i)
            coaches[i] = i + 1;
        
        vector<int> target(N);
        while (cin >> target[0], target[0] > 0)
        {
            for (size_t i = 1; i < N; ++i)
                cin >> target[i];

            stack<int> station;
            size_t coachesIndex = 0;
            size_t targetIndex = 0;
            while (targetIndex == targetIndex) // Avoid compiler's warning.
            {
                // Does the top coach in the station match the target coach?
                if (!station.empty() 
                    && station.top() == target[targetIndex])
                {
                    station.pop();
                    ++targetIndex;
                    continue;
                }
                if (coachesIndex >= N)
                    break;
                station.push(coaches[coachesIndex++]);
            }
            if (station.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}