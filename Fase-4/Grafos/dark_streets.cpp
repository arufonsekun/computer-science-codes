#include <iostream>
#include <set>

using namespace std;

int main() {

    set<pair<int, int> > priority_queue;
    
    int v=1, e=1, v1, v2, w, total, u, res = 0;
    pair<int, int> weight_vertex;
    set<pair<int, int> >::iterator front;

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
	    graph[v2][v1] = w;

            total+=w;

            weight_vertex.first = w;
            weight_vertex.second = v1;
            priority_queue.insert(weight_vertex);

//	    weight_vertex.clean();

	    //weight_vertex.first = w;
            //weight_vertex.second = v2;
            //priority_queue.insert(weight_vertex);
        }

        while (!priority_queue.empty()) {

          front = priority_queue.begin();

          w = front->first;
          u = front->second;

	  priority_queue.erase(front);
	  
//	  weight_vertex.clean();

          if (!visited[u]){

      	    res += w;

	    cout << "peso : " << w << endl;

            for (int i = 0; i < v; i++){
              if (graph[u][i] != -1){
                 weight_vertex.first = graph[u][i];
                 weight_vertex.second = i;
                 priority_queue.insert(weight_vertex);
              }
            }
            visited[u] = 1;
          }
        }

        cout << total - res << endl;

    }

    return 0;
}
