#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector<char> graph;
vector<int> visited;

void dfs(int index, int edges){
	printf("%c\n",graph[0][0] + 97);
	for (int i = 0; i < edges; i++){
		for (int node = 0; node < graph[index].size(); node++){
			//printf("%c\n",graph[index][node] + 97);
			visited[graph[index][node]] = 1;
		}
		//printf("%c\n", graph[index][i]+'a');
	}
	if (index < edges){
		dfs(index+1, edges);
	}
}

void fillVisited(){
	if (visited.size() == 0){
		for (int value = 0; value < 26; value++){
			visited.push_back(0);
		}
	}
	else{
		for (int value = 0; value < visited.size(); value++){
			visited[value] = 0;
		}
	}

}

void unfillGraph(){
	for (int v = 0; v < 26; v++){
		graph[v].clear();
	}
}

void showVisited(){
	for(int i = 0; i < visited.size(); i++){
		//printf("%c\n", graph[index]);
		printf("%d ", visited[i]);
	}
	cout << endl;
}

int main(){
	int N; // casos de teste
	int V, E;//vertices e arestas
	char v1, v2;
	int ind1, ind2;
	cin >> N;
	for (int i = 0; i < N; i++){
		fillVisited();
		unfillGraph();
		//cout << visited.size() << endl;
		cin >> V;
		cin >> E;
		for (int conect = 0; conect < E; conect++){
			cin >> v1;
			cin >> v2;
			cout << v1 << v2 << endl;
			graph[v1 - 'a'].push_back(v2 - 'a');
			graph[v2 - 'a'].push_back(v1 - 'a');
			//printf("%d\n", v2-97);
			//printf("%c\n", graph[v2 - 97][0] +'a');

			//v1 = ' '; v2 = ' ';
		}

		dfs(0, E);
		showVisited();
		cout << ' ' << endl;
	}

	return 0;
}
