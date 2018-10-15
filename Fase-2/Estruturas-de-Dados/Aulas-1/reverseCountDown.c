#include <stdio.h>

void reverse(int y){
    if (y == 1){
      printf("%d\n", y);
      return;
    }

    reverse(y - 1);
    printf("%d\n", y);
}

int times(int y, int x){
    if (x == 0){
        return 0;
    }
    return y + times(y, x - 1);
}

int power(int y, int x){
    if (x == 1)
        return y;

    return y * power(y, x - 1);
}

int main(){
  //reverse(10);
  //printf("%d\n", times(100,3));
  printf("%d\n", power(2,5));
  return 0;
}
