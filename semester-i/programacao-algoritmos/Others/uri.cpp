#include <iostream>
using namespace std;

int main(){
  double R;
  cin >> R;
  double volume = (4.0 * 3.14159 * R * R * R)/3 ;
  printf("VOLUME = %.2lf\n", volume);
  return 0;
}
