#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

static const int LEFT = 0;
static const int RIGHT = 1;

int main()
{   
    int c;
    cin >> c;
    while ( c-- )
    {
        int l, m;
        cin >> l >> m;
        l *= 100;

        // Use two queues to store the cars.
        vector<queue<int> > cars(2);
        for (int i = 0; i < m; ++i)
        {
            int length;
            string bank;
            cin >> length >> bank;
            if (bank == "left")
                cars[LEFT].push(length);
            else
                cars[RIGHT].push(length);
        }

        // "The ferry is initially on the left bank"
        int index = LEFT;
        int crossRiver = 0;
        while (! (cars[LEFT].empty() && cars[RIGHT].empty()))
        {
            int totalLength = 0;
            while (! cars[index].empty()
                   && totalLength + cars[index].front() <= l)
            {
                totalLength += cars[index].front();
                cars[index].pop();
            }
            ++crossRiver;
            index ^= 1;
        }
        cout << crossRiver << endl;
    }
    return 0;
}