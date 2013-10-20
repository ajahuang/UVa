#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int time;
    int fine;
    int id;
};

bool comp(const Job &j1, const Job&j2)
{
    return j1.time * j2.fine < j2.time * j1.fine;
}

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;

        vector<Job> job(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> job[i].time >> job[i].fine;
            job[i].id = i + 1;
        }
        
        // Greedily pick a next job imposing the minimum fine.
        // Keep lexicographical order for equivalent jobs.
        stable_sort(job.begin(), job.end(), comp);

        cout << job[0].id;
        for (int i = 1; i < N; ++i)
            cout << " " << job[i].id;
        cout << endl;
        
        if (T)
            cout << endl;
    }
    return 0;
}