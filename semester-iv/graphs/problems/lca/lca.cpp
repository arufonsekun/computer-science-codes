#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iterator>

using namespace std;

struct node {
    int card_number, id, height;
    struct node * parent;
    struct node * left;
    struct node * right;
};

vector<node *> card_pos;

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

    if ( (root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)) )
        return true;

    path.pop_back();
    return false;
}

void inOrder(node * root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d : %d : %d\n", root->id+1, root->card_number, root->height);
    inOrder(root->right);
}

int findLCA(node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
      return -1;

    int i = 0;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1.at(i) != path2.at(i))
            break;
    return path1.at(i-1);
}

int main(){

    node * no = NULL;
    int n_cards, card_number, c1, c2, c3=0;
    pair<int, int> pos_card (0,0);
    unordered_map<int, pair<int, int> > card_number_pos;

    scanf("%d", &n_cards);
    for (int i=0; i < n_cards; i++)
    {
        cin >> card_number;

        no = (node*) malloc(sizeof(node));
        no->card_number = card_number;
        no->height = 0;
        no->id = i;
        no->parent = NULL;
        no->right = NULL;
        no->left = NULL;
        card_pos.push_back(no);

        auto it = card_number_pos.find(card_number);
        if (it == card_number_pos.end()) {
            card_number_pos[card_number] = make_pair(i, 0);
        } else {
            it->second.second = i;
        }

    }

    for (int i=0; i < n_cards -1 ; i++) {
        cin >> c1 >> c2;
        c1--; c2--;

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
    int total_score, Hn1, Hn2, lca_index=0, pos1, pos2 = 0;

    for (auto value : card_number_pos)
    {
        pos1 = value.second.first;
        Hn1 = card_pos.at(pos1)->height;

        pos2 =  value.second.second;
        Hn2 = card_pos.at(pos2)->height;

        //cout << pos1 << " " << pos2 << endl;

        lca_index = findLCA(card_pos.at(0),pos1, pos2);
        //cout << lca_index << endl;

        if (lca_index != -1)
            total_score += Hn1 + Hn2 - card_pos[lca_index]->height * 2;
        //cout << value.first << endl;
        //cout << value.first << " : " << value.second.first << " : " << value.second.second << endl;
    }

    //inOrder(card_pos.at(0));

    cout << total_score << endl;

    return 0;
}
