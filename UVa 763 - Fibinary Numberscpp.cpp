#include <iostream>
#include <string>
using namespace std;

int main()
{    
    int Case = 1;
    string n1, n2;
    while (cin >> n1 >> n2)
    {
        if (n2.length() > n1.length())
            swap(n1, n2);

        for (int i = (int)n1.size() - 1, j = (int)n2.size() - 1
                 ; i >= 0 && j >= 0
                 ; --i, --j)
        {
            n1[i] += n2[j] - '0';  
        }

        n1.insert(0, "000");
        bool hasModification = false;
        // Loop until there is no changing n1.
        do
        {
            hasModification = false;
            for (size_t i = 1; i < n1.size(); ++i)
            {
                //    0200
                // -> 1001
                while (n1[i] > '1')
                {
                    hasModification = true;
                    if (i == n1.size() - 2)
                    {
                        ++n1[i + 1];
                        ++n1[i - 1];
                    }
                    else if (i == n1.size() - 1)
                        ++n1[i - 1];
                    else
                    {
                        ++n1[i - 1];
                        ++n1[i + 2];
                    }
                    n1[i] -= 2;
                }
                //    100 
                // -> 011
                while (i < n1.size() - 1 && n1[i] > '0' && n1[i + 1] > '0')
                {
                    hasModification = true;
                    ++n1[i - 1];
                    --n1[i];
                    --n1[i + 1];
                }
            }
        } while (hasModification);

        // Erase leading zeros.
        while (n1[0] == '0' && n1.size() > 1)
            n1.erase(0, 1);

        if (Case++ > 1)
            cout << endl;
        cout << n1 << endl;
    }
    return 0;
}