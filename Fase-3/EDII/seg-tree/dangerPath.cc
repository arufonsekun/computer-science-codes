#include <iostream>
#include <vector>
#include <tuple>
#include <bitset>
using namespace std;

typedef tuple<int,int,int> iii;

vector<int> monsters;
vector<iii> tree;

int query(int b, int e, int i){
    if (get<0>(tree[i]) == b and get<1>(tree[i]) == e) 
        return get<2>(tree[i]);
    if (get<0>(tree[i]) == get<1>(tree[i])) return get<2>(tree[i]);

    if (get<0>(tree[i]) >= b and get<1>(tree[i]) <= e) return get<2>(tree[i]);

    if (get<0>(tree[i]) > e) return 0;
    if (get<1>(tree[i]) < b) return 0;

    if (get<0>(tree[i]) <= b and get<1>(tree[i]) >= e){
        int ql = query(b, e, i*2);
        int qr = query(b, e, i*2 +1);
        return ql | qr;
    }
}

void update(int b){

}

int fill(int b, int e, int i){
    get<0>(tree[i]) = b;
    get<1>(tree[i]) = e;
    if (b == e){
        return get<2>(tree[i]) = monsters[b-1];
    }
    
    int ql = fill(b, (b+e)/2, i*2);
    int qr = fill(((b+e)/2)+1, e, i*2 + 1);
    return get<2>(tree[i]) = ql | qr; 
}

int main(){
    int n, q, m;
    int o, b, e;// o eh a operacao 1 ou 2
    int monN;// n° do mostru
    iii no = {0,0,0};// n from treee node

    cin >> n >> q >> m;
    monsters.assign(n, 0);
    tree.assign(n*2+1, no);

    for (int i = 0; i < m; i++){
        cin >> monN; 
        monsters.at(i) = 1 << (monN -1);
    }

    //3th parameter =1 cause i'm ignoring index 0
    fill(1, n, 1);

    for (unsigned int i = 1; i < tree.size(); i++){
        cout << "b = " << get<0>(tree[i]);
        cout << " e = " << get<1>(tree[i]);
        cout << " q = " << bitset<5>(get<2>(tree[i])) << endl;
    }

    cout << bitset<5>(query(1,4, 1)) << endl;

    /*
       for (int i = 0; i < q; i++){
       cin >> o >> b >> e;

       if (o == 1) cout << query(b, e);
       else cout << update(b);
       }*/

    return 0;
}
