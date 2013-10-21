#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{  
    int k, m;
    while (cin >> k, k > 0)
    {
        cin >> m;
        map<string, int> courses;
        // Freddie's chosen courses.
        for (int i = 0; i < k; ++i)
        {
            string course;
            cin >> course;
            ++courses[course];
        }
        // Check each category.
        bool graduate = true;
        for (int i = 0; i < m; ++i)
        {
            int c, r;
            cin >> c >> r;
            for (int j = 0; j < c; ++j)
            {
                string course;
                cin >> course;
                if (courses.find(course) != courses.end())
                    --r;
            }
            if (r > 0)
                graduate = false;
        }
        cout << (graduate? "yes" : "no") << endl;
    }
    return 0;
}