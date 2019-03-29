#include <iostream>
#include <vector>
using namespace std;

vector<int> monsters; 

int main(){
    int n, q, m;//o eh a operacao 1 ou 2
    int o, b, e;
    cin >> n >> q >> m;
    monsters.assign(n, 0);

    for (int i = 0; i < m; i++){
        cin >> monsters.at(i);
    }

    for (int i = 0; i < q; i++){
        cin >> o >> b >> e;
        
        if (o == 1) cout << query(b, e);
        else cout << update(b, b);
    }

    return 0;
}
