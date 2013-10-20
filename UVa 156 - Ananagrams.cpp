#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{  
    string s;
    multimap<string, string> memo;
    while (cin >> s, s != "#")
    {
        string t(s);
        transform(s.begin(), s.end(), t.begin(), ::tolower);
        sort(t.begin(), t.end());
        memo.insert(pair<string, string>(t, s));
    }
    // An ananagram has only 1 mapping.
    multimap<string, string>::iterator iter(memo.begin());
    vector<string> ananagrams;
    for (; iter != memo.end(); ++iter)
        if (memo.count(iter->first) == 1)
            ananagrams.push_back(iter->second);

    sort(ananagrams.begin(), ananagrams.end());
    copy(ananagrams.begin(), ananagrams.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}