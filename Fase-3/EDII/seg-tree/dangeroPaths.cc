#include <iostream>
#include <vector>
#include <tuple>
#include <bitset>
using namespace std;

typedef unsigned long long ull;
typedef tuple<ull,ull,ull> iii;

vector<ull> monsters;
vector<iii> tree;

ull query(ull b, ull e, int i = 1){
	if (get<0>(tree[i]) == b && get<1>(tree[i]) == e)
		return get<2>(tree[i]);

	if (e < get<0>(tree[i])) return 0;
	if (get<1>(tree[i]) < b) return 0;

	if (get<0>(tree[i]) == get<1>(tree[i])){
		if (e < get<0>(tree[i])) return 0;
		if (get<1>(tree[i]) < b) return 0;
		else return get<2>(tree[i]);
	}

	ull c = query(b, e, i*2);
	ull d = query(b, e, i*2 + 1);
	return (c | d);
}

ull update(ull cor, ull mN, int i = 1){
	if (get<0>(tree[i]) == cor && get<1>(tree[i]) == cor){
		get<2>(tree[i]) = (1ull << (mN - 1));
		return get<2>(tree[i]);
	}

	if (cor < get<0>(tree[i])) return get<2>(tree[i]);
    if (get<1>(tree[i]) < cor) return get<2>(tree[i]);

	if (get<0>(tree[i]) == get<1>(tree[i])){
		if (cor < get<0>(tree[i])) return 0;
		if (get<1>(tree[i]) < cor) return 0;
		else return get<2>(tree[i]);
	}

	ull c = update(cor, mN, i*2);
	ull d = update(cor, mN, i*2+1);

	return get<2>(tree[i]) =  (c | d);
}

ull fill(ull b, ull e, int i = 1){
    get<0>(tree[i]) = b;
    get<1>(tree[i]) = e;
    if (b == e){
        return get<2>(tree[i]) = monsters[b-1];
    }

    ull ql = fill(b, (b+e)/2, i*2);
    ull qr = fill(((b+e)/2)+1, e, i*2 + 1);
    return get<2>(tree[i]) = ql | qr;
}

int main(){
    ull  n, q, m;
    ull o, b, e;
    ull monN;
    iii no = {0,0,0};

    cin >> n >> q >> m;
    tree.assign(n*n, no);

    for (int i = 0; i < n; i++){
		scanf("%ull", &monN);
		m = 1ull << (monN -1);
        monsters.push_back(m);
    }

    fill(1, n);

   for (int i = 0; i < q; i++){
       cin >> o >> b >> e;
       if (o == 1) cout << __builtin_popcountll(query(b, e)) << endl;
       else update(b, e);
   }

    return 0;
}
