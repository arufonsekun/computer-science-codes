#include <iostream>
#include <cmath>

using namespace std;
int r;

long int search(int vR[], int b, int e, float n){
    if(e==b) return (n > vR[e] ? e+1 : e);

    int mid = b + (e-b)/2;
    if (vR[mid] == n) return mid;
    if (vR[mid] > n) return search(vR, b, mid-1, n);
    return search(vR, mid+1, e, n);

}

int main() {
  int s, x, y, rVal;
  long int p = 0;
  float d = 0.0;

  scanf("%d %d", &r, &s);

  int vR[r];

  for (int i = 0; i < r; i++){
    scanf("%d", &rVal);
    vR[i] = rVal;
  }

  for (int i = 0; i < s; i++){
    scanf("%d %d", &x, &y);
    d = sqrt(x*x + y*y);
    p += r - search(vR, 0, r-1, d);
    //printf("Distancia = %.2lf\n", d);
    //printf("Posiçao = %ld\n", p);
    // cout << p << endl;
  }
  cout << p << endl;

  return 0;
}
