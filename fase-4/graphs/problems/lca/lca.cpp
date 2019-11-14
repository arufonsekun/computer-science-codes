#include <iostream>
#include <vector>

using namespace std;

struct node {
    int card_number, id, height;
    struct node * parent;
    struct node * left;
    struct node * right;
};

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
  
    if (node->parent == NULL){
        node->height = 1;
    }else{
        node->height = node->parent->height + 1;
    }
  
    /* then recur on left sutree */
    computeHeight(node->left);  
  
    /* now recur on right subtree */
    computeHeight(node->right); 
}


 //https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

bool findPath(node *root, vector<int> &path, int k) 
{ 
    // base case 
    if (root == NULL) return false; 
  
    // Store this node in path vector. The node will be removed if 
    // not in path from root to k 
    path.push_back(root->id); 
  
    // See if the k is same as root's key 
    if (root->id == k) 
        return true; 
  
    // Check if k is found in left or right sub-tree 
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    // If not present in subtree rooted with root, remove root from 
    // path[] and return false 
    path.pop_back(); 
    return false;
} 

int findLCA(node *root, int n1, int n2) 
{ 
    // to store paths to n1 and n2 from the root 
    vector<int> path1, path2; 
  
    // Find paths from root to n1 and root to n1. If either n1 or n2 
    // is not present, return -1 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
  
    /* Compare the paths to get the first different value */
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
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
        no->height = 0;
        no->id = i;
        no->parent = NULL;
        no->right = NULL;
        no->left = NULL;
        card_pos.push_back(no);
    }

    //bfs para altura




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

    computeHeight(card_pos.at(0));

    inOrder(card_pos.at(0));

    printf("%d\n", 1 + findLCA(card_pos.at(0),2,3));

    return 0;
}