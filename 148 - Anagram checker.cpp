#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

static map<string, string> memo;

void searchAnagrams(const vector<string>                &phrases, 
                    const map<string, string>::iterator &iterStart,
                    vector<string>                      &anagrams, 
                    const string                        &s, 
                    vector<bool>                        &marks)
{
    // All chars are marked, meaning all matched.
    if (count(marks.begin(), marks.end(), false) == 0)
    {
        copy(phrases.begin(), phrases.end(), ostream_iterator<string>(cout, " "));
        cout << "=";
        for (size_t i = 0; i < anagrams.size(); ++i)
            cout << " " << anagrams[i];
        cout << endl;
        return;
    }
    // Check if s contains the string iter->second.
    // For example, ABCDEFG contains ACG
    // Check in alphabetic order, startin from iterStart. 
    map<string, string>::iterator iter = iterStart;
    for (; iter != memo.end(); ++iter)
    {
        vector<size_t> markPosition;
        for (size_t i = 0, j = 0; i < s.size(); ++i)
        {
            if (!marks[i] && s[i] == iter->second[j])
            {
                markPosition.push_back(i);
                // "Do not include the set consisting of the original words."
                if (j == iter->second.size() - 1
                    && find(phrases.begin(), phrases.end(), iter->first) == phrases.end())
                {
                    for (size_t k = 0; k < markPosition.size(); ++k)
                        marks[markPosition[k]] = true;
                    // Store the matched anagram.
                    anagrams.push_back(iter->first);
                    searchAnagrams(phrases, iter, anagrams, s, marks);
                    anagrams.pop_back();
                    // Undo the marks.
                    for (size_t k = 0; k < markPosition.size(); ++k)
                        marks[markPosition[k]] = false;
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
    // Check the phrases.
    while (getline(cin, input), input != "#")
    {
        string s = input;
        // Store the phrases to a vector.
        vector<string> phrases;
        stringstream ss(input);
        while (ss >> input)
            phrases.push_back(input);
        // Remove empty spaces and sort s.
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        sort(s.begin(), s.end());
        // Mark the matched positions of s.
        vector<bool> marks(s.size(), false);
        // Store the matched anagrams.
        vector<string> anagrams;
        searchAnagrams(phrases, memo.begin(), anagrams, s, marks);
    }

    return 0;
}