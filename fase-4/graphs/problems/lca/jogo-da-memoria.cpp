#include <iostream>
#include <vector>
#include <utility>

using namespace std;

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

int main(){
    
    vector<int> card_pos;
    int n_cards, card_number, card_number_1;
    vector<vector<int> > tree;
    vector<int> row;

    for (int i=0; i < n_cards; i++) {
	cin >> card_number;
	card_pos.push_back(card_number);
	tree.push_back(row);
    }


    for(int i=0; i < n_cards-1; i++) {
	cin >> card_number >> card_number_1;
	tree.at(card_number - 1).push_back(card_number_1);
	tree.at(card_number_1 - 1).push_back(card_number);
    }

    for(int i=0; i < tree.size(); i++) {
	for(int j=0; j < tree.at(i).size(); j++) {
	    cout << tree.at(i).at(j) << endl;
	}
    }

    
    return 0;
}
