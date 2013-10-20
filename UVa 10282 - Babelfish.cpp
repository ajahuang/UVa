#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{  
    map<string, string> memo;
    string line;
    while (getline(cin, line), line != "")
    {
        stringstream ss(line);
        string foreignWord, englishWord;
        ss >> englishWord >> foreignWord;;
        memo[foreignWord] = englishWord;
    }
    while (getline(cin, line))
    {
        if (memo.find(line) == memo.end())
            cout << "eh" << endl;
        else
            cout << memo[line] << endl;
    }
    return 0;
}