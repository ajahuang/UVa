#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string, int> L; 

int main()
{
    int maxLength = 0;
    string w2;
    while (cin >> w2)
    {
        int length = 1;
        // Insert c before w2[i].
        for (int i = 0; i <= w2.size(); ++i)
            for (char c = 'a'; c <= 'z'; ++c)       
            {
                string w1(w2);
                w1.insert(i, 1, c);
                if (w1 > w2)
                    break;
                if (L.count(w1))
                    length = max(length, L[w1] + 1);
            }
        // Delete w2[i].
        for (int i = 0; i < w2.size(); ++i)
        {
            string w1(w2);
            w1.erase(i, 1);
            if (L.count(w1))
                length = max(length, L[w1] + 1);
        }
        // Change w2[i].
        for (int i = 0; i < w2.size(); ++i)
            for (char c = 'a'; c <= 'z' && c != w2[i]; ++c)
            {
                string w1(w2);
                w1[i] = c;
                if (w1 > w2)
                    break;
                if (L.count(w1))
                    length = max(length, L[w1] + 1);
            }
        L[w2] = length;
        maxLength = max(maxLength, length);
    }
    cout << maxLength << endl;
}
