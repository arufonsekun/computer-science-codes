#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    set<pair<int, int> > priority_queue;
    
    int v=1, e=1, v1, v2, w, total, u, res = 0;
    pair<int, int> weight_vertex = make_pair(0, 0);
    set<pair<int, int> >::iterator front;
    vector<bool> visited;
    vector<vector<pair<int, int>> > graph;
    vector<pair<int, int>> row;

    cin >> v >> e;

    while (v or e) {
        
	visited.resize(v);
	visited.assign(v, false);
	graph.resize(v);
	graph.assign(v, row);

	total=0;

    for (int i = 0; i < e; i++){
		
	    cin >> v1 >> v2 >> w;

	    weight_vertex.first = w;
	    weight_vertex.second = v1;

	    graph.at(v2).push_back(weight_vertex);

	    weight_vertex.second = v2;
	    graph.at(v1).push_back(weight_vertex);

        total+=w;

    }

	weight_vertex.first = 0;
	weight_vertex.second = 0;
	priority_queue.insert(weight_vertex);

    while (!priority_queue.empty()) {

      front = priority_queue.begin();

      w = front->first;
      u = front->second;

      priority_queue.erase(front);
  
      if (!visited[u]){

  	    res += w;

        for (int i = 0; i < graph[u].size(); i++) priority_queue.insert(graph[u][i]);

        visited.at(u) = true;
      }
    }

	visited.clear();
	graph.clear();

    cout << total - res << endl;
	res = 0;
	w = 0;
	cin >> v >> e;

    }

    return 0;
}
