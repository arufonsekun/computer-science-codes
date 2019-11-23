#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int n_cards;
vector<int> height;
vector<bool> visited;
vector<int> visited_nodes;
vector<int> euler_tour_dist;
vector<tuple<int, int, int>> segment_tree;
vector<int> card_order;
vector<pair<int, int>> card_pos;

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

    euler_tour_dist.push_back(height[current]);
    visited_nodes.push_back(card_order[current]);

    if (!visited.at(current)) {
        if (card_pos.at(card_order[current]-1).first == -1)
            card_pos.at(card_order[current]-1).first = visited_nodes.size() - 1;
        else
            card_pos.at(card_order[current]-1).second = visited_nodes.size() - 1;
    }

    visited.at(current) = true;

    for (int adj_vertex :  tree.at(current)) {
        if (!visited.at(adj_vertex)) {
            euler_tour(tree, current, adj_vertex);
        }
    }

    if (parent != current) {
        visited.at(parent) = true;
        euler_tour_dist.push_back(height[parent]);
        visited_nodes.push_back(card_order[parent]);
    }
}

int fill_seg_tree(int left, int right, int i = 1) {
    get<0>(segment_tree[i]) = left;
    get<1>(segment_tree[i]) = right;

    if (left == right) {
        return get<2>(segment_tree[i]) = left;
    }

    int half_1 = fill_seg_tree(left, (left + right) / 2, i*2);
    int half_2 = fill_seg_tree(((left + right) / 2) + 1, right, (i*2)+1);
    return get<2>(segment_tree[i]) = euler_tour_dist[half_1] < euler_tour_dist[half_2] ? half_1 : half_2;
}

int query_lca(int b, int e, int i = 1) {

    if (b == e) return euler_tour_dist.at(get<2>(segment_tree[i]));
    if (get<0>(segment_tree[i]) == get<1>(segment_tree[i])) return euler_tour_dist.at(get<2>(segment_tree[i]));
    if (b == get<0>(segment_tree[i]) && e == get<1>(segment_tree[i])) return euler_tour_dist.at(get<2>(segment_tree[i]));

    int mid = (get<0>(segment_tree[i]) + get<1>(segment_tree[i])) / 2;

    if (b <= mid && e > mid)
        return min(query_lca(b, e, i*2), query_lca(b, e, (i*2) +1));

    if (e <= mid)
        return query_lca(b, e, i*2);
    else
        return query_lca(b, e, (i*2)+1);
}

int main(){

    int v1, v2, card_number;
    tuple<int, int, int> seg = make_tuple(0, 0, 0);

    cin >> n_cards;
    card_pos.assign(n_cards/2, {-1,-1});

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
    euler_tour(tree, 0, 0);

    int seg_tree_size = pow(2, visited_nodes.size() / 2);
    segment_tree.assign( seg_tree_size, seg);
    fill_seg_tree(0, visited_nodes.size()-1);

    int total=0;
    int n1, n2, hlca;
    for (int i=0; i < card_pos.size(); i++) {

        n1 = card_pos.at(i).first;
        n2 = card_pos.at(i).second;

        hlca = query_lca(n1, n2);
        total += (euler_tour_dist.at(n1) + euler_tour_dist.at(n2)) - hlca * 2;
    }

    cout << total << endl;

    return 0;
}
