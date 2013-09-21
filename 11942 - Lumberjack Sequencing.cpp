#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    // Get N.
    string s;
    getline(cin, s);
    istringstream ss(s);
    size_t N;
    ss >> N;
    cout << "Lumberjacks:" << endl;
    while ( N-- )
    {
        // Get workers.
        getline(cin, s);
        ss.clear();
        ss.str(s);
        int worker;
        vector<int> workers;
        while (ss >> worker)
            workers.push_back(worker);
        // If workers is sorted either increasing or decreasing order.
        if (adjacent_find(workers.begin(), workers.end(), 
                          greater<int>()) == workers.end()
            || adjacent_find(workers.begin(), workers.end(), 
                             less<int>()) == workers.end()
            )
        {
            cout << "Ordered" << endl;
        }
        else
            cout << "Unordered" << endl;
    }
    return 0;
}