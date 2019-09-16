#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {

    set<pair<int, int> > priority_queue;
    pair<int, int> weight_vertex = make_pair(0, 0);
    set<pair<int, int> >::iterator front;
    vector<vector<pair<int, int>> > graph;
    vector<pair<int, int> > row;
    vector<int> dist;
    int v, e, v1, v2, w, s, u, d;

    scanf("%d %d", &v, &e);
    dist.resize(v+1);
    dist.assign(v+1, INF);
    graph.resize(v+1);
    graph.assign(v+1, row);

    for (int i=0; i < e; i++) {
	    scanf("%d %d %d", &v1, &v2, &w);
	    weight_vertex.first = w;
	    weight_vertex.second = v2;
	    graph.at(v1).push_back(weight_vertex);

	    weight_vertex.second = v1;
	    graph.at(v2).push_back(weight_vertex);
    }

    scanf("%d", &s);
    dist.at(s) = 0;

    weight_vertex.first = 0;
    weight_vertex.second = s;

    priority_queue.insert(weight_vertex);
    
    while (!priority_queue.empty()) {

	    front = priority_queue.begin();
	    u = front->second;
	    d = front->first;
	    priority_queue.erase(front);

	    for (int i=0; i < graph[u].size(); i++) {

	        if (dist.at(u) + graph[u][i].first < dist.at(graph[u][i].second)) {
		    dist[graph[u][i].second] = dist[u] + graph[u][i].first;
		    weight_vertex.first = dist[graph[u][i].second];
		    weight_vertex.second = graph[u][i].second;
		    priority_queue.insert(weight_vertex);
	        }

	    }
    }

    auto result = minmax_element(dist.begin(), dist.end());
    dist.erase(result.first);
    dist.erase(result.second);

    result = minmax_element(dist.begin(), dist.end()); 

    cout << (*result.second - *result.first) << endl;

    return 0;
}
