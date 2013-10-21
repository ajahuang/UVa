#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

static map<string, string> memo;

// Check if s contains the phrases of memo starting from iterStart.
// For example, ABCDEFG contains ACG.
// Arguments:
//   phrases  -- The original input phrases.
//   anagrams -- Stores the matched phrases (of the directory) so far.
//   matched  -- Matched[i] = true if s[i] was matched; false, otherwise.
void searchAnagrams(const vector<string>                &phrases, 
                    const map<string, string>::iterator &iterStart,
                    vector<string>                      &anagrams, 
                    const string                        &s, 
                    vector<bool>                        &matched)
{
    // All elements of s were matched.
    if (count(matched.begin(), matched.end(), false) == 0)
    {
        copy(phrases.begin(), phrases.end(), ostream_iterator<string>(cout, " "));
        cout << "=";
        for (size_t i = 0; i < anagrams.size(); ++i)
            cout << " " << anagrams[i];
        cout << endl;
        return;
    }
    map<string, string>::iterator iter = iterStart;
    for (; iter != memo.end(); ++iter)
    {
        vector<size_t> markPosition;
        for (size_t i = 0, j = 0; i < s.size(); ++i)
        {
            if (!matched[i] && s[i] == iter->second[j])
            {
                markPosition.push_back(i);
                // Matched! But.. "Do not include the set consisting of the original words."
                if (j == iter->second.size() - 1
                    && find(phrases.begin(), phrases.end(), iter->first) == phrases.end())
                {
                    // Mark the matched elements.
                    for (size_t k = 0; k < markPosition.size(); ++k)
                        matched[markPosition[k]] = true;
                    // Store the matched anagram.
                    anagrams.push_back(iter->first);
                    searchAnagrams(phrases, iter, anagrams, s, matched);
                    anagrams.pop_back();
                    // Unmark.
                    for (size_t k = 0; k < markPosition.size(); ++k)
                        matched[markPosition[k]] = false;
                    break;
                }
                else
                    ++j;
            }
        }
    }
}

int main()
{  
    string input;
    // Get the dictionary.
    while (getline(cin, input), input != "#")
    {
        string word = input;
        sort(word.begin(), word.end());
        memo[input] = word;
    }
    // Get the phrases.
    while (getline(cin, input), input != "#")
    {
        string s = input;
        // Store the phrases to a vector.
        vector<string> phrases;
        stringstream ss(input);
        while (ss >> input)
            phrases.push_back(input);
        // Remove empty spaces then sort s.
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        sort(s.begin(), s.end());
        // For marking the matched positions of s.
        vector<bool> matched(s.size(), false);
        // Store the matched anagrams.
        vector<string> anagrams;
        searchAnagrams(phrases, memo.begin(), anagrams, s, matched);
    }

    return 0;
}