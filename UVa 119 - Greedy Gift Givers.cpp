#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{  
    size_t T = 1;
    size_t N;
    while (cin >> N)
    {
        map<string, int> balance;
        vector<string> names;
        for (size_t i = 0; i < N; ++i)
        {
            string name;
            cin >> name;
            balance[name] = 0;
            names.push_back(name);
        }
        for (size_t i = 0; i < N; ++i)
        {
            string name;
            cin >> name;
            int spentMoney, nPeople;
            cin >> spentMoney >> nPeople;
            if (nPeople == 0)
                continue;
            // "Each person gives the same integer amount of money to 
            // each friend to whom any money is given, and gives as 
            // much as possible."
            int gift = spentMoney / nPeople;
            balance[name] -= gift * nPeople;
            for (size_t j = 0; j < nPeople; ++j)
            {
                cin >> name;
                balance[name] += gift;
            }
        }
        // "The output for each group should be separated from other 
        // groups by a blank line."
        if (T++ > 1)
            cout << endl;
        for (size_t i = 0; i < N; ++i)
            cout << names[i] 
                 << " "
                 << balance[names[i]]
                 << endl;
    }
    return 0;
}