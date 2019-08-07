#include <iostream>
#include <set>

using namespace std;

int PRIM() {
    return 0;
}

int main() {

    set<pair<int, int>> q;
    
    int v=1, e=1, v1, v2, w;
    pair<int, int> vertex_weight;

    while (v or e) {
        
        cin >> v >> e;
        int visited[v];
        
        for (int i = 0; i < e; i++){
            cin >> v1 >> v2 >> w;
            vertex_weight.first = w;
            vertex_weight.second = v1;
            q.insert(vertex_weight);
            vertex_weight.second = v2;
            q.insert(vertex_weight);
        }

    }
    
    cout << "Hello world";
    return 0;
}
