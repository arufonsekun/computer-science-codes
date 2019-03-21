#include <iostream>
#include <algorithm>    // for lower_bound, upper_bound and sort
#include <vector>       // for vector

using namespace std;

int search(int v[8], int b, int e, double k){
    if (b == e){
        if (k <= v[e]) return e;
        else return e+1;
    }
    int mid = b + (e - b) / 2;
    if (v[mid] == k) return mid;
    else if (v[mid] > k) return search(v, b, mid-1, k);
    else return search(v, mid+1, e, k);
}

int main ()
{
    int gfg[] = {5, 6, 7, 8, 9, 10, 11, 12};

    vector<int> v(gfg,gfg+8);    // 5 6 7 7 6 5 5 6

    //sort (v.begin(), v.end());  // 5 5 5 6 6 6 7 7

    double p;
    cin >> p;

    vector<int>::iterator lower,upper;
    lower = lower_bound (v.begin(), v.end(), p);
    upper = upper_bound (v.begin(), v.end(), p);

    cout << "lower_bound for " << p << " at position " << (lower- v.begin()) << '\n';
    cout << "upper_bound for " << p <<  " at position " << (upper - v.begin()) << '\n';
    cout << "search(p) : " << p <<  " at position " << search(gfg, 0, 7, p) << '\n';


    return 0;
}
