#include <iostream>
#include <vector>

using namespace std;

struct node {
    int card_number, id;
    struct node * parent;
    struct node * left;
    struct node * right;
};

void inOrder(node * root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d : %d\n", root->id+1, root->card_number);
    inOrder(root->right);
}

int main(){

    node * no = NULL;
    int n_cards, card_number, c1, c2, c3;
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


    /*for (int i=0; i < card_pos.size(); i++) {
        cout << card_pos.at(i)->id << endl;
    }*/

    for (int i=0; i < n_cards -1 ; i++) {
        scanf("%d %d", &c1, &c2);

        if (card_pos.at(c2-1)->parent != NULL) {
            c3 = c2;
            c2 = c1;
            c1 = c3;
        }

        if (card_pos.at(c1-1)->left == NULL){
            card_pos.at(c1-1)->left = card_pos.at(c2-1);
            card_pos.at(c2-1)->parent = card_pos.at(c1-1);
        }
        else if (card_pos.at(c1-1)->right == NULL) {
            card_pos.at(c1-1)->right = card_pos.at(c2-1);
            card_pos.at(c2-1)->parent = card_pos.at(c1-1);
        }

    }

    inOrder(card_pos.at(0));

    return 0;
}
