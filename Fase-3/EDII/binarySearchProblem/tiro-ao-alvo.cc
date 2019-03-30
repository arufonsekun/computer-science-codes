#include <iostream>
#include <cmath>

using namespace std;

int search(int vR[], int b, int e, float n){
  if (b == e) return (n > vR[e] ? e+1 : e);
  int m = (b+e)/2;
  if (vR[m] == n) return m;
  if (n > vR[m]) return search(vR, m+1, e, n);
  return search(vR, b, m-1, n);
}

int main() {
  int r, s, x, y, rVal, p = 0;
  float d = 0.0;

  cin >> r >> s;

  int vR[r];

  for (int i = 0; i < r; i++){
    scanf("%d", &rVal);
    vR[i] = rVal;
  }

  for (int i = 0; i < s; i++){
    scanf("%d %d", &x, &y);
    d = sqrt(x*x + y*y);
    p += search(vR, 0, r-1, d);
  }

  cout <<  (r*s) - p << endl;

  return 0;
}
