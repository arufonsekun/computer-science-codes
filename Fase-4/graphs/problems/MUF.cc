#include <iostream>
#include <vector>

using namespace std;

int vertex, edges, xp;

int* MakeRank(int *rank) {

    for (int i=1; i<=vertex; i++) {
        rank[i]=1;
    }
    return rank;
}

int* MakeParent(int* parent) {

    for (int i=1; i<=vertex; i++) {
        *parent = i;
        parent++;
    }

    for (int i=1; i<=vertex; i++) {
        parent--;
    }

    return parent;
}

int Find(int* parent, int x) {

    if (x == parent[x])
        return x;
    xp = Find(parent, parent[x]);
    parent[x] = xp;
    return xp;

}

int main() {
    int *rank = NULL, *parent = NULL;

    int vertex, edges, v1, v2, w;

    vector<vector<pair<int, int>> > graph;
    vector<pair<int, int>> row;
    pair<int, int> vertex_weight;

    scanf("%d %d", &vertex, &edges);
   
    rank = (int*) malloc(vertex * sizeof(int));
    parent = (int*) malloc(vertex * sizeof(int));

    parent = MakeParent(parent);

    for (int i=0; i < vertex; i++) {
        cout << *parent << endl;
        parent++;
    }

    // free(parent);
    // free(rank);

    //rank = MakeRank(rank);
    parent = MakeParent(parent);

    /*graph.assign(vertex+1, row);

    int rank[vertex], parent[vertex];

    for (int i=0; i < edges; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        vertex_weight.second = w;
        vertex_weight.first = v1;
        
        graph.at(v2).push_back(vertex_weight);

        vertex_weight.first = v2;
        graph.at(v1).push_back(vertex_weight);

    }
    
    int parent[n];
    int rank[n];
*/


    return 0;
}

