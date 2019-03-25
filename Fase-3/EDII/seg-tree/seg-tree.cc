#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef tuple<int, int, int> tiii;

vector <tiii> segTree;

void bfs(){
    for (unsigned int i = 1; i < segTree.size(); i++){
        cout << "SegTree[" << get<0>(segTree[i]) << ", " << get<1>(segTree[i]) << "]" <<" = " << get<2>(segTree[i]) << endl;
    }
}

int fill(int b, int e, int i = 1){
    get<0>(segTree[i]) = b;
    get<1>(segTree[i]) = e;
    
    if (b == e) return (get<2>(segTree[i]) = e);
    get<2>(segTree[i]) = min(fill(b, (b+e)/2, i*2), fill(((b+e)/2)+1, e, (i*2)+1));

    /* Just fill:
     if(b == e) return;
     fill(b, (b+e)/2, i*2);
     fill(((b+e)/2)+1, e, (i*2)+1);
    */
}

int query(int b, int e, int i=1){
    if (b == e) return get<2>(segTree[i]);
    if (get<0>(segTree[i]) == get<1>(segTree[i])) return get<2>(segTree[i]);
    if (b == get<0>(segTree[i]) and e == get<1>(segTree[i])) return get<2>(segTree[i]);
    
    int mid = (get<0>(segTree[i]) + get<1>(segTree[i])) / 2;

    if (b <= mid and e > mid)
        cout << "entrou aqui" << endl;
        return min(query(b, e, i*2), query(b, e, (i*2) +1));

    if (e <= mid)
        return query(b, e, i*2);
    else
        return query(b, e, (i*2)+1);
}

int main(){
    int n, b, e;
    tiii seg = {0, 0, 0};

    printf("n: ");
    scanf("%d", &n);
    segTree.assign(n*2, seg);

    fill(1, n);
    bfs();
    cout << "Set the intervals: " << endl;
    cin >> b >> e; 
    cout << query(b, e) << endl;

    return 0;
}
