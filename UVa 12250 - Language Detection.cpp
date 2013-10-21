#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{  
    map<string, string> memo;
    memo["HELLO"] = "ENGLISH";
    memo["HOLA"] = "SPANISH";
    memo["HALLO"] = "GERMAN";
    memo["BONJOUR"] = "FRENCH";
    memo["CIAO"] = "ITALIAN";
    memo["ZDRAVSTVUJTE"] = "RUSSIAN";

    size_t T = 1;
    string s;
    while (cin >> s, s != "#") 
    {
        cout << "Case "
             << T++
             << ": "
             << (memo.find(s) != memo.end()? memo[s] : "UNKNOWN")
             << endl;
    }
    return 0;
}