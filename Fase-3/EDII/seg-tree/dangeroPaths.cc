#include <iostream>
#include <vector>
#include <tuple>
#include <bitset>
using namespace std;

typedef tuple<int,int,int> iii;

vector<int> monsters;
vector<iii> tree;

int query(int b, int e, int i = 1){
	if (get<0>(tree[i]) == b && get<1>(tree[i]) == e)
		return get<2>(tree[i]);

    if (e < get<0>(tree[i])) return 0;
    if (get<1>(tree[i]) < b) return 0;

    int c = query(b, e, i*2);
    int d = query(b, e, i*2 + 1);
    return (c | d);
}

int update(int cor, int mN, int i = 1){
	if (get<0>(tree[i]) == cor && get<1>(tree[i]) == cor){
		get<2>(tree[i]) = 1 << (mN - 1);
		return get<2>(tree[i]);
	}

	if (cor < get<0>(tree[i])) return get<2>(tree[i]);
    if (get<1>(tree[i]) < cor) return get<2>(tree[i]);

	int c = update(cor, mN, i*2);
	int d = update(cor, mN, i*2+1);

	return get<2>(tree[i]) =  (c | d);
}

int fill(int b, int e, int i = 1){
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
    iii no = {0,0,0};// n from tree node

    cin >> n >> q >> m;
    monsters.assign(n+1, 0);
    tree.assign(n*2+1, no);

    for (int i = 0; i < n; i++){
        cin >> monN;
        monsters.at(i) = 1 << (monN -1);
    }

    fill(1, n);
	// cout << bitset<5>(query(2,2)) << endl;
	// cout << bitset<5>(query(3,3)) << endl;
	// update(3, 3);

	//cout << bitset<5>(get<2>(tree[4])) << endl;

	// for (unsigned int i = 1; i < tree.size(); i++){
	//     cout << "b = " << get<0>(tree[i]);
	//     cout << " e = " << get<1>(tree[i]);
	//     cout << " q = " << bitset<5>(get<2>(tree[i])) << endl;
	// }

   for (int i = 0; i < q; i++){
       cin >> o >> b >> e;
       if (o == 1) cout << bitset<51>((query(b, e))).count() << endl;
       else update(b, e);
   }

    return 0;
}
