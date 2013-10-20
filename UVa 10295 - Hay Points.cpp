#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{  
    size_t m, n;
    cin >> m >> n;
    map<string, int> memo;
    for (size_t i = 0; i < m; ++i)
    {
        string word;
        int value;
        cin >> word >> value;
        memo[word] = value;
    }
    for (size_t i = 0; i < n; ++i)
    {
        string word;
        int salary = 0;
        while (cin >> word, word != ".")
            salary += memo[word];
        
        cout << salary << endl;
    }
    return 0;
}