#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tiii;

int n_cards;
vector<int> height;
vector<bool> visited;
vector<int> euler_tour_vertices;
vector<int> euler_tour_dist;
vector<tiii> segment_tree;
vector<int> card_order;

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
    euler_tour_dist.push_back(height[current]);
    euler_tour_vertices.push_back(current);

    for (int adj_vertex :  tree.at(current)) {
        if (!visited.at(adj_vertex)) {
            euler_tour(tree, current, adj_vertex);
        }
    }

    if (parent != current) {
        visited.at(parent) = true;
        euler_tour_dist.push_back(height[parent]);
        euler_tour_vertices.push_back(parent);
    }
}

int fill_seg_tree(int left, int right, int i = 1) {
    get<0>(segment_tree[i]) = left;
    get<1>(segment_tree[i]) = right;

    if (left == right) {
        //cout << "index : " << left << " : height :"<< euler_tour_dist[left] << endl;
        return get<2>(segment_tree[i]) = left;
    }

    int half_1 = fill_seg_tree(left, (left + right) / 2, i*2);
    int half_2 = fill_seg_tree(((left + right) / 2) + 1, right, (i*2)+1);
    return get<2>(segment_tree[i]) = euler_tour_dist[half_1] < euler_tour_dist[half_2] ? half_1 : half_2;
}

int query_lca(int b, int e, int i = 1) {
    
    if (b == e) return get<2>(segment_tree[i]);
    if (get<0>(segment_tree[i]) == get<1>(segment_tree[i])) return get<2>(segment_tree[i]);
    if (b == get<0>(segment_tree[i]) && e == get<1>(segment_tree[i])) return get<2>(segment_tree[i]);
    
    int mid = (get<0>(segment_tree[i]) + get<1>(segment_tree[i])) / 2;

    if (b <= mid && e > mid)
        return min(query_lca(b, e, i*2), query_lca(b, e, (i*2) +1));

    if (e <= mid)
        return query_lca(b, e, i*2);
    else
        return query_lca(b, e, (i*2)+1);
    return INF;
}

/*
void dfs(vector<vector<int>> tree, int parent) {
    visited.at(parent) = true;
    for(int adj_vertex : tree[parent]) {
        if (!visited.at(adj_vertex)) {
            cout << "Node: " << card_order.at(adj_vertex) << " Height: " << height.at(adj_vertex) << endl;
            dfs(tree, adj_vertex);
        }
    }
}
*/

int main(){

    int v1, v2, card_number;
    tiii seg = {0, 0, 0};

    cin >> n_cards;

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

    visited.assign(n_cards, false);
    height.at(0) = 0;
    computeHeight(tree, 0);

    visited.assign(n_cards, false);
    visited.at(0) = true;
    euler_tour(tree, 0, 0);

    int size = euler_tour_vertices.size();
    int seg_tree_size = pow(2, *max_element(begin(height), end(height)));
    segment_tree.assign( seg_tree_size, seg);
    //euler_tour_dist.insert(euler_tour_dist.begin(), 0);
    fill_seg_tree(0, size-1);

    cout << seg_tree_size << endl;

    /*for (int i=1; i < segment_tree.size(); i++)
    {
        cout << "[" << get<0>(segment_tree[i]) << ","
         << get<1>(segment_tree[i])        << "] = "
         << euler_tour_dist.at(get<2>(segment_tree[i])) << endl;
    }*/
    

    int pos1 = 2, pos2 = 3;

    cout << "LCA("<< card_order[pos1] << "," << card_order[pos2] << ") = " << query_lca(pos1, pos2) << endl;
    
    /*
    for (int i=0; i < tree.size(); i++) {
        for (int j=0; j < tree[i].size(); j++)
        cout << tree[i][j] << " ";
        cout << endl;
    }
    */

    /*for (int i=0; i < euler_tour_vertices.size(); i++)
    {
        cout << euler_tour_vertices.at(i) << " : " << euler_tour_dist.at(i) << endl;
    }*/

    return 0;
}
