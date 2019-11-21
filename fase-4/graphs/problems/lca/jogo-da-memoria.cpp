#include <iostream>
#include <vector>
#include <utility>
#include <tuple>


using namespace std;

typedef tuple<int, int, int> tiii;

int n_cards;
vector<int> height;
vector<bool> visited;
vector<int> euler_tour_vertices;
vector<int> euler_tour_dist;
vector<tiii> segment_tree;

void print(vector<vector<int> > tree) {

    for(unsigned i=0; i < tree.size(); i++) {
	    for(unsigned j=0; j < tree.at(i).size(); j++) {
	        cout << tree.at(i).at(j) << endl;
	    }
    }
}

void computeHeight(vector<vector<int>> tree, int parent) {

    visited.at(parent) = true;

    for(int adj_vertex : tree[parent]) {
        if (!visited.at(adj_vertex)) {
            height.at(adj_vertex) = height.at(parent) + 1;
            computeHeight(tree, adj_vertex);
        }
    }
}

void euler_tour(vector<vector<int>> tree, int parent, int current) {

    visited.at(current) = true;
    euler_tour_dist.push_back(height[current-1]);
    euler_tour_vertices.push_back(current);

    for (int adj_vertex :  tree.at(current)) {
        if (!visited.at(adj_vertex)) {
            euler_tour(tree, current, adj_vertex);
        }
    }

    if (parent != -1){
        visited.at(parent) = true;
        euler_tour_dist.push_back(height[parent]);
        euler_tour_vertices.push_back(parent);
    }
        
}

/*int fill_seg_tree(int left, int right, int i = 1) {
    get<0>(segment_tree[i]) = left;
    get<1>(segment_tree[i]) = right;

    if (left == right)
        return get<2>(segment_tree) = euler_tour_vertices(left);
    return get<2>(segment_tree[i]) = min( fill_seg_tree(left, (left + right) / 2, i*2), fill_seg_tree((left + right) / 2 + 1, right, i*2+1) );
}*/

int main(){

    vector<int> card_order;
    int v1, v2, card_number;
    tiii seg = {0, 0, 0};

    cin >> n_cards;

    visited.assign(n_cards, false);
    height.assign(n_cards, 0);
    vector<vector<int>> tree(n_cards);

    for (int i=0; i < n_cards; i++) {
	    cin >> card_number;
    	card_order.push_back(card_number);
    }

    for(int i=0; i < n_cards-1; i++) {
	    cin >> v1 >> v2;
        v1--; v2--;
	    tree[v1].push_back(v2);
	    tree[v2].push_back(v1);
    }


    height.at(0) = 0;
    computeHeight(tree, 0);

    visited.assign(n_cards, false);

    visited.at(0) = true;
    euler_tour(tree, tree[0][0], tree[0][0]);

    int size = euler_tour_vertices.size() * 2;

    /*segment_tree.assign(size, seg);

    cout << "Nodes: ";
    for (int vertex : euler_tour_vertices) {
        cout << vertex + 1 << " ";
    }
    cout << "\nhaght: ";
    for (int height : euler_tour_dist) {
        cout << height << " ";
    }

    cout << endl;
    /*for (int i=0; i < tree.size(); i++) {
        for (int j=0; j < tree[i].size(); j++)
        cout << tree[i][j] << " ";
        cout << endl;
    }
    for (int i=0; i < card_order.size(); i++) {
        printf("Vertex: %d  height: %d \n", card_order.at(i), height.at(i));
    }
    */

    return 0;
}
