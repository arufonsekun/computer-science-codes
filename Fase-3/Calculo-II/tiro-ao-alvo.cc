#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//vector<int> distancias;
vector<int> raios;
int n;

int getPos(int i, int f, float r){
    if (i == f)
        return i+1;
    int m = (i+f)/2;
    if (raios.at(m) == r) return n-m+1;
    if(r > raios.at(m)) return getPos(m+1, f, r);
    else return getPos(i, m-1, r);
}

int main(){
    int r, t, x, y, pontos = 0;
    float d = 0.0;
    cin >> n >> t;
    
    for (int i = 0; i < n; i++){
        scanf("%d", &r);
        raios.push_back(r);
    }

    for (int i = 0; i < t; i++){
        scanf("%d %d", &x, &y);
        d = sqrt((x*x) + (y*y));
        pontos = getPos(0, n-1, d);  
        printf("(%d, %d) = %.2f, pontos=%d\n", x, y, d, pontos);
    }
    cout << pontos << endl;
    
    return 0;
}
