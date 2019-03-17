#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  long long int s = 0, r = 0;
  long long int x = 0, y = 0, rVal = 0;
  long long int p = 0;
  double d = 0.0;

  scanf("%lld %lld", &r, &s);

  vector<long int> vR;
  vector<long int>::iterator lower;

  for (long long int i = 0; i < r; i++){
    scanf("%lld", &rVal);
    vR.push_back(rVal);
  }

  for (long long int i = 0; i < s; i++){
    scanf("%lld %lld", &x, &y);
    d = sqrt(x*x + y*y);
    lower = lower_bound(vR.begin(), vR.end(), d);
    //cout << "Distancia: " << d << "Posição" << *lower << endl;
    rVal = (lower - vR.begin());
    p += r - rVal; //;
  }
  printf("%lld\n", p);

  return 0;
}
