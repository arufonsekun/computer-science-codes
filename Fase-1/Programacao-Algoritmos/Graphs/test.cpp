#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<vector<char> > graph{256};
  vector<char> vertex;
  vertex.push_back('1');
  graph.push_back(vertex);
  cout << graph[0][0];
  return 0;
}
