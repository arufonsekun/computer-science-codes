//Name: Junior Vitor Ramisch
//email: junior.ramisch@gmail.com
//code: 1811100034
#include <stdio.h>
#include <stdlib.h>
#include "RBT.h"

#define WHITE "\033[37;1m %d \033[0m\t"
#define WHITE_STRING "\033[37;1m%s\033[0m"

int main(){
    Node* root = NULL;
    int operation, size;

    menu();//show menu
    printf("Type the operation: ");
    scanf("%d", &operation);
    while(operation != 13){
        if (operation == 1){
            printf("Type the tree size: ");
            scanf("%d", &size);
            if (root != NULL) {destroy(root); root = NULL;};
            if (size != 0) {
                root = generateNodes(root, size);
                printf(WHITE_STRING, "Done!\n");
            }
        }

        else if (operation == 2){
            printf("Type the node to remove: ");
            scanf("%d", &size);//reusing vars
            Node* rNode = getNode(root, size);
            root = deleteNode(root, rNode);
        }

        else if (operation == 3){
            if (root == NULL) printf("Tree is empty!\n");
            else {
                printf(WHITE_STRING, "In-order\n → ");
                inOrder(root);
                printf("\n");
            }
        }

        else if (operation == 4){
            if (root == NULL) printf("Tree is empty!\n");
            else{
                printf(WHITE_STRING, "Pre-order\n → ");
                preOrder(root); printf("\n");}
        }

        else if (operation == 5){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else {
                printf(WHITE_STRING, "Pos-order\n → ");
                posOrder(root);
                printf("\n");}
        }

        else if (operation == 6){
            printf("    \n");
            breadthFirstSearch(root);
        }

        else if(operation == 7){
            printf(WHITE_STRING, "Tree number of nodes is ");
            printf("%d\n", treeSize(root));
        }

        else if (operation == 8){
            printf(WHITE_STRING, "Tree height is ");
            printf("%d\n", height(root));
        }

        else if (operation == 9){
            printf("Type the node key: ");
            scanf("%d", &size);//reusing variables
            Node* s = getNode(root, size);

            if (s == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
            else{
                s = successor(s);
                if (s->parent != NULL){
                    printf(WHITE_STRING, "\nSUCCESSSOR\n");
                    printf(" → Sucessor key: %d\n", s->key);
                    s->parent->parent != NULL ? printf(" → Successor's parent-key: %d\n", s->parent->key) : printf(" → Successor s no parent\n");
                    s->left != NULL ? printf(" → Successor left-child key: %d\n", s->left->key) : printf(" → Successor's left-child is null\n");
                    s->right != NULL ? printf(" → Successor's right-child key: %d\n", s->right->key) : printf(" → Successor's right-child is null\n");
                    printf("\n");
                }
                else{
                    printf(WHITE_STRING, "Sucessor doesn't exist\n");
                }
            }
        }

        else if (operation == 10){
            printf("Type the node key: ");
            scanf("%d", &size);//reusing variables
            Node* p = getNode(root, size);
            if (p == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
            else{
                p = predecessor(p);
                printf(WHITE_STRING, "\nPREDECESSOR\n");
                printf(" → Predecessor key: %d\n", p->key);
            }
        }

        else if (operation == 11){
            destroy(root);
            printf(WHITE_STRING, "Tree memory is clear!\n");
        }

        else if(operation == 12) {
            system("clear");
            menu();
        }

        //printf("Altura da sub arvore da esq.: %d e da direita %d\n", height(root->left), height(root->right));
        printf("Type the operation: ");
        scanf("%d", &operation);
    }
    return 0;
}
