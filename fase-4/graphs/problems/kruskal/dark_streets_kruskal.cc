#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

struct Edge {
	int w, v1, v2;
};

vector<int> v_rank;
vector<int> parent;
vector<Edge> graph;

int vertices, edges;

void Make() {
	for (int i=0; i < vertices; i++) {
		v_rank.push_back(1);
		parent.push_back(i);
	}
}

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	int x_parent = Find(parent[x]);
	parent[x] = x_parent;
	return x_parent;
}

int Union(int x, int y) {
	int x_p = Find(x);
	int y_p = Find(y);

	if (v_rank[x_p] > v_rank[y_p])
		parent[y_p] = x_p;
	else if(v_rank[y_p] > v_rank[x_p])
		parent[x_p] = y_p;
	else {
		v_rank[x_p] += 1;
		parent[y_p] = x_p;
	}
}

bool compareWeight(Edge edge1, Edge edge2) {
	return (edge1.w < edge2.w);
}

int Kruskal() {

	int coast = 0;

	v_rank.clear();
	parent.clear();

	Make();
	sort(graph.begin(), graph.end(), compareWeight);

	for (int i=0; i < edges; i++) {
		
		if (Find(graph.at(i).v1) != Find(graph.at(i).v2)){
			coast += graph.at(i).w;
			Union(graph.at(i).v1, graph.at(i).v2);
		}
	}
	graph.clear();
	
	return coast;
}

int main() {
	Edge edge = {0,0,0};
	int v1, v2, w, totalWeight = 0;

	scanf("%d %d", &vertices, &edges);

	while (vertices || edges) {

		graph.assign(edges, edge);

		for (int i=0; i < edges; i++) {
			scanf("%d %d %d", &v1, &v2, &w);
			totalWeight += graph[i].w = w;
			graph[i].v1 = v1;
			graph[i].v2 = v2;
		}

		cout << totalWeight - Kruskal() << endl;
		totalWeight = 0;
		
		scanf("%d %d", &vertices, &edges);
	}
	
	return 	0;
}
