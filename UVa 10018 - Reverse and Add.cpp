#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int reverseAndAdd(string &n)
{
    string rn(n);
    reverse(rn.begin(), rn.end());
    unsigned int n_i, rn_i;
    stringstream ss(n);
    ss >> n_i;
    ss.clear();
    ss.str(rn);
    ss >> rn_i;
    ss.clear();
    ss << n_i + rn_i;
    string sum = ss.str();
    string r_sum(sum);
    reverse(r_sum.begin(), r_sum.end());

    n = sum;
    // If the sum is a palindrome.
    if (sum == r_sum)
        return 1;
    else      
        return 1 + reverseAndAdd(n);

}

int main()
{  
    size_t N;
    cin >> N;
    while ( N-- )
    {
        string number;
        cin >> number;
        cout << reverseAndAdd(number) 
             << " "
             << number 
             << endl;    
    }
    return 0;
}