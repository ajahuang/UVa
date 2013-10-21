#include <iostream>
#include <string>
using namespace std;

int main()
{  
    size_t n;
    cin >> n;
    while ( n-- )
    {
        string s;
        cin >> s;
        
        // Negative result.
        if (s.size() >= 2 && s.substr(s.size() - 2, 2) == "35")
            cout << "-" << endl;
        // Experiment failed.
        else if (s[0] == '9' && s[s.size() - 1] == '4')
            cout << "*" << endl;
        // Experiment not completed.
        else if (s.size() >= 3 && s.substr(0, 3) == "190")
            cout << "?" << endl;
        // Positive result.
        else
            cout << "+" << endl;
    }
    return 0;
}