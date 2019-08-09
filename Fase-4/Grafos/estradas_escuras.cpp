
#include <iostream>
#include <set>

using namespace std;

int PRIM(int visited[], set<pair<int, int>> priority_queue, int v, int graph[v][v]) {
    return 0;
}

int main() {

    set<pair<int, int>> priority_queue;
    
    int v=1, e=1, v1, v2, w, total;
    pair<int, int> weight_vertex;

    while (v or e) {
        
        cin >> v >> e;
        int visited[v];
	int graph[v][v];

	total=0;

	for (int i=0; i < v; i++) {
	     visited[i] = 0;
	     for (int j=0; j < v; j++) graph[i][j] = -1;
	}

        for (int i = 0; i < e; i++){
		
	    cin >> v1 >> v2 >> w;
            graph[v1][v2] = w;
	    graph[v1][v2] = w;

	    total+=w;

	    weight_vertex.first = w;
            weight_vertex.second = v1;
            priority_queue.insert(weight_vertex);
            weight_vertex.second = v2;
            priority_queue.insert(weight_vertex);
        }

	cout << total - PRIM(visited, priority_queue, v, graph) << endl;

    }
    
    cout << "Hello world";
    return 0;
}
