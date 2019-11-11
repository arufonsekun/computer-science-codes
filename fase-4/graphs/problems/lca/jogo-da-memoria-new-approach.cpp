#include <iostream>
#include <vector>

using namespace std;

struct node {
    int card_number, id;
    struct node * parent;
    struct node * left;
    struct node * right; 
};

int main(){

    node * no = NULL;
    int n_cards, card_number, c1, c2;
    vector<node *> card_pos;

    scanf("%d", &n_cards);
    for (int i=0; i < n_cards; i++)
    {    
        scanf("%d", &card_number);
        no = (node*) malloc(sizeof(node));
        no->card_number = card_number;
        no->id = i;
        no->parent = NULL;
        no->right = NULL;
        no->left = NULL;
        card_pos.push_back(no);
    }

    for (int i=0; i < n_cards -1 ; i++) {
        scanf("%d %d", c1, c2);

    }

    for (int i=0; i < card_pos.size(); i++) {
        cout << card_pos.at(i)->id << endl;
    }


    return 0;
}