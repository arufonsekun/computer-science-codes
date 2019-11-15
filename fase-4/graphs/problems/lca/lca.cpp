#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node {
    int card_number, id, height;
    struct node * parent;
    struct node * left;
    struct node * right;
};
vector<node *> card_pos;

void inOrder(node * root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d : %d : %d\n", root->id+1, root->card_number, root->height);
    inOrder(root->right);
}

void computeHeight(struct node* node)
{
    if (node == NULL)
        return;

    if (node->parent == NULL) {
        node->height = 1;
    }
    else {
        node->height = node->parent->height + 1;
    }

    computeHeight(node->left);
    computeHeight(node->right);
}

bool findPath(node *root, vector<int> &path, int k)
{
    if (root == NULL) return false;

    path.push_back(root->id);

    if (root->id == k)
        return true;

    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;

    path.pop_back();
    return false;
}

int findLCA(node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

pair<int, int> getCardPos(int card_number) {

    int p1 = -1, p2 = -1;

    for (int i=0; i < card_pos.size(); i++) {
        if (card_pos.at(i)->card_number == card_number) {
            if (p1 == -1)
                p1 = i;
            else
            {
                p2 = i;
                return pair<int, int>(p1, p2);
            }
        }
    }
}

int main(){

    node * no = NULL;
    int n_cards, card_number, c1, c2, c3=0;
    pair<int, int> pos_card (0,0);
    map<int, pair<int, int> > card_number_pos;

    scanf("%d", &n_cards);
    for (int i=0; i < n_cards; i++)
    {
        scanf("%d", &card_number);
        no = (node*) malloc(sizeof(node));
        no->card_number = card_number;
        no->height = 0;
        no->id = i;
        no->parent = NULL;
        no->right = NULL;
        no->left = NULL;
        card_pos.push_back(no);
        if (card_number_pos.find(card_number) == card_number_pos.end())
            card_number_pos.insert(card_number_pos, pair<int,int>(i, 0));
        else
            card_number_pos.at(card_number)->second = i;
    }

    for (int i=0; i < n_cards -1 ; i++) {
        cin >> c1 >> c2;
        c1--; c2--;1

        if (card_pos.at(c2)->parent != NULL) {
            c3 = c2;
            c2 = c1;
            c1 = c3;
        }

        if (card_pos.at(c1)->left == NULL){
            card_pos.at(c1)->left = card_pos.at(c2);
        }
        else if (card_pos.at(c1)->right == NULL) {
            card_pos.at(c1)->right = card_pos.at(c2);
        }
        card_pos.at(c2)->parent = card_pos.at(c1);

    }

    computeHeight(card_pos.at(0));
    int total_score = 0, Hn1=0, Hn2=0, lca_index=0;
    map<int, pair<int, int> >::iterator it;
    for (it=card_number_pos.begin(); it != card_number_pos.end(); ++it)
    {
        pos_card = getCardPos(i);
        Hn1 = card_pos.at(it.second->first)-> height;
        Hn2 = card_pos.at(it.second->second)-> height;
        lca_index = findLCA(card_pos.at(0),pos_card.first, pos_card.second);
        total_score += Hn1 + Hn2 - card_pos.at(lca_index)->height * 2;
    }

    // inOrder(card_pos.at(0));

    cout << total_score << endl;

    return 0;
}
