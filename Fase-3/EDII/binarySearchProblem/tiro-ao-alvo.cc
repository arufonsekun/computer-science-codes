#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long int> vR;
long long int r = 0;

long long int search(long long int b, long long int e, long double k){
    if (b == e+1){//avoid out_of_range error
        return b;
    }
    long long int mid = b + (e - b) / 2;
    if (vR[mid] == k) return mid;
    if (vR[mid] > k) return search(b, mid-1, k);
    return search(mid+1, e, k);
}

int main() {
  long long int s = 0, r = 0, x = 0;
  long long int y = 0, rVal = 0, p = 0;
  long double d = 0.0;

  scanf("%lld %lld", &r, &s);

  for (long long int i = 0; i < r; i++){
    scanf("%lld", &rVal);
    vR.push_back(rVal);
  }

  for (long int i = 0; i < s; i++){
    scanf("%lld %lld", &x, &y);
    d = sqrt(x*x + y*y);
    p += r - search(0, r-1, d);
  }
  printf("%lld\n", p);

  return 0;
}
