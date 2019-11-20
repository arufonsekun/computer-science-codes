#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n_cards;

pair<int, int> card_pos(int n1, vector<int> card_pos) {

    pair<int, int> pos (0,0);
    int counter = 0;

    for (int number : card_pos) {	
        if (number == n1) {
            if(pos.first == 0)
                pos.first = counter;
            else {
	   	        pos.second = counter;
	   	        return pos;
	        }
	    }
    }
}

void print(vector<vector<int> > tree) {
    
    for(unsigned i=0; i < tree.size(); i++) {
	    for(unsigned j=0; j < tree.at(i).size(); j++) {
	        cout << tree.at(i).at(j) << endl;
	    }
    }
}

int solve(vector<vector<int> > tree, int s, int d) {
    
    int current = s, previous, score;
    vector<int> visited;
    visited.assign(n_cards, 0);


    for (unsigned i=0; i < tree.at(current).size(); i++) {
        
        visited.at(current - 1) = 1;

        if (!visited.at(tree.at(s - 1).at(i))) {
            
        }
    }
}

int main(){
    
    vector<int> card_pos;
    int v1, v2, card_number;

    cin >> n_cards;
    
    vector<vector<int>> tree(n_cards);

    for (int i=0; i < n_cards; i++) {
	    cin >> card_number;
    	card_pos.push_back(card_number);
    }


    for(int i=0; i < n_cards-1; i++) {
	    cin >> v1 >> v2;
	    tree[v1-1].push_back(v2);
	    tree.at[v2-1].push_back(v1);
    }

    
    return 0;
}
