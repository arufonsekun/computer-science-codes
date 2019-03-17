#include <iostream>
#include <cmath>

using namespace std;
long long int r;

long long int search(long long int vR[], long long int b, long long int e, long double n){
    if (n == vR[r-1]) return r-1;
    if (n == 0) return 0;
    if(e==b) return (n > vR[e] ? e+1 : e);

    if(e >= b){
        long long int mid = b + (e-b)/2;
        if (vR[mid] == n) return mid;
        if (vR[mid] > n) return search(vR, b, mid-1, n);
        return search(vR, mid+1, e, n);
    }

}

int main() {
  long long int s, x, y, rVal;
  long long int p = 0;
  long double d = 0.0;

  scanf("%lld %lld", &r, &s);

  long long int vR[r];

  for (int i = 0; i < r; i++){
    scanf("%lld", &rVal);
    vR[i] = rVal;
  }

  for (long int i = 0; i < s; i++){
    scanf("%lld %lld", &x, &y);
    d = sqrt(x*x + y*y);
    p += r - search(vR, 0, r-1, d);
  }
  printf("%lld\n", p);

  return 0;
}
