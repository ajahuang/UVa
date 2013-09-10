#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

static const int LEFT = 0;
static const int RIGHT = 1;

int main()
{   
    int c;
    cin >> c;
    while ( c-- )
    {
        int n, t, m;
        cin >> n >> t >> m;

        // Use two queues to store the cars.
        vector<queue<pair<int, int> > > cars(2);
        vector<int> uploadedTime(m);
        for (int i = 0; i < m; ++i)
        {
            int arrivalTime;
            string bank;
            cin >> arrivalTime >> bank;
            if (bank == "left")
                cars[LEFT].push(pair<int, int>(i, arrivalTime));
            else
                cars[RIGHT].push(pair<int, int>(i, arrivalTime));
        }

        int time = 0;
        // "The ferry is initially on the left bank."
        int index = LEFT;
        while (! (cars[LEFT].empty() && cars[RIGHT].empty()))
        {
            // "If there are no cars waiting on either bank, 
            // the ferry waits until one arrives,.."
            int earliest_car = numeric_limits<int>::max();
            if (! cars[LEFT].empty())
                earliest_car = cars[LEFT].front().second;
            if (! cars[RIGHT].empty())
                earliest_car = min(earliest_car, cars[RIGHT].front().second);

            time = max(time, earliest_car);

            int carCount = 0;
            while (! cars[index].empty()
                   && carCount < n 
                   && cars[index].front().second <= time)
            {
                uploadedTime[cars[index].front().first] = time + t;
                cars[index].pop();
                ++carCount;
            }
            time += t;
            index ^= 1;
        }

        for (int i = 0; i < m; ++i)
            cout << uploadedTime[i] << endl;
        // "Output an empty line between cases."
        if (c)
            cout << endl;
    }
    return 0;
}