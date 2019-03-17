#include <iostream>
#include <algorithm>    // for lower_bound, upper_bound and sort
#include <vector>       // for vector

using namespace std;

int main ()
{
    int gfg[] = {5,6,7,7,6,5,5,6};

    vector<int> v(gfg,gfg+8);    // 5 6 7 7 6 5 5 6

    sort (v.begin(), v.end());  // 5 5 5 6 6 6 7 7

    double p;
    cin >> p;

    vector<int>::iterator lower,upper;
    lower = lower_bound (v.begin(), v.end(), p);
    upper = upper_bound (v.begin(), v.end(), p);

    cout << "lower_bound for " << p << " at position " << (lower- v.begin()) << '\n';
    cout << "upper_bound for " << p <<  " at position " << (upper - v.begin()) << '\n';

    return 0;
}
