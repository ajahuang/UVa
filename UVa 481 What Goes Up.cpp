#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int> &seq,
           const vector<int> &path,
           int                pos)
{
    if (pos == -1)
        return;
    print(seq, path, path[pos]);
    cout << seq[pos] << endl;
}

int main()
{  
    int n;
    vector<int> seq;
    while (cin >> n)
        seq.push_back(n);

    // L[i] stores the smallest ending value of seq's length-i LIS.
    vector<int> L(seq.size());
    vector<int> L_id(seq.size());
    vector<int> path(seq.size());
    int lisEnd = 0, lisCount = 0;
    // O(nlogk) greedy + D&C algorithm (where k is the length of the LIS).
    for (int i = 0; i < seq.size(); ++i)
    {
        // Find the insert position of L.
        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, seq[i]) 
                     - L.begin();
        L[pos] = seq[i];
        L_id[pos] = i;
        // Store seq[i]'s previous number.
        path[i] = pos? L_id[pos - 1] : -1;
        // If seq[i] was inserted to L's "end".
        if (pos == lisCount)
        {
            ++lisCount;
            lisEnd = i;
        }
    }
    
    cout << lisCount << "\n-\n";
    print(seq, path, lisEnd);

    return 0;
}