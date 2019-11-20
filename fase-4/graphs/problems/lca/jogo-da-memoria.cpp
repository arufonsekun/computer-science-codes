#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n_cards;
vector<int> height;
vector<bool> visited;
vector<int> euler_tour_vertices;
vector<int> euler_tour_dist;

void print(vector<vector<int> > tree) {

    for(unsigned i=0; i < tree.size(); i++) {
	    for(unsigned j=0; j < tree.at(i).size(); j++) {
	        cout << tree.at(i).at(j) << endl;
	    }
    }
}

void computeHeight(vector<vector<int>> tree, int parent) {

    visited.at(parent) = true;

    for(int adj_vertex :  tree[parent]) {
        if (!visited.at(adj_vertex)) {
            height.at(adj_vertex) = height.at(parent) + 1;
            computeHeight(tree, adj_vertex);
        }
    }
}

void euler_tour(vector<vector<int>> tree, int parent, int current) {

    visited.at(current) = true;
    euler_tour_dist.push_back(height[current]);
    euler_tour_vertices.push_back(current);

    for (int adj_vertex :  tree.at(current)) {
        if (!visited.at(adj_vertex)) {
            euler_tour(tree, current, adj_vertex);
        }
    }

    visited.at(parent) = true;
    euler_tour_dist.push_back(height[current]);
    euler_tour_vertices.push_back(current);
}

int main(){

    vector<int> card_pos;
    int v1, v2, card_number;

    cin >> n_cards;

    visited.assign(n_cards, false);
    height.assign(n_cards, 0);
    vector<vector<int>> tree(n_cards);

    for (int i=0; i < n_cards; i++) {
	    cin >> card_number;
    	card_pos.push_back(card_number);
    }

    for(int i=0; i < n_cards-1; i++) {
	    cin >> v1 >> v2;
        v1--; v2--;
	    tree[v1].push_back(v2);
	    tree[v2].push_back(v1);
    }


    height.at(tree[0][0]) = 0;
    computeHeight(tree, tree[0][0]);
    visited.assign(n_cards, false);
    euler_tour(tree, 0, 0);

    for (int vertex : euler_tour_vertices) {
        cout << vertex << " ";
    }

    cout << endl;
    /*for (int i=0; i < tree.size(); i++) {
        for (int j=0; j < tree[i].size(); j++)
        cout << tree[i][j] << " ";
        cout << endl;
    }
    for (int i=0; i < card_pos.size(); i++) {
        printf("Vertex: %d  height: %d \n", card_pos.at(i), height.at(card_pos.at(i)));
    }*/

    return 0;
}
