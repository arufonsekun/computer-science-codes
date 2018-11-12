#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h" 

int main()
 {
     TTree *myTree=NULL, *root=NULL;
     long int i;
     int n;
     clock_t begin, end;
     double time_spent;
     srand(time(NULL));   // New seed for random numbers
     printf("Inserindo %d números recursivamente...\n",SIZE);
     begin=clock();
     for (i=1;i<=SIZE;i++)
     {
 
         //n=rand()%1500000;
         //printf("Digite o valor do nó\n");
         scanf("%d", &n);
 
         myTree=insertBST(root,n);
         if (root==NULL) root=myTree;
     }
     end=clock();
     time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
     printf("\nTempo (em s)%5.2f: \n",time_spent);
     printf("\n# of nodes: %d\n",numberOfNodes(root));
     printf("\nAltura (raiz): %d\n",treeHeight(root));
     /*printf("\nAltura (1o. filho esq.): %d\n",treeHeight(root->left));
     printf("\nAltura (1o. filho dir.): %d\n",treeHeight(root->right));
     printf("\nAltura (1o. filho esq. do 1o. filho dir.): %d\n",treeHeight(root->right->left));
     printf("\nAltura (1o. filho dir. do 1o. filho dir.): %d\n",treeHeight(root->right->right));*/
     PrintInOrder(root);
     printf("\n");
     cleanTree(root);
     return 0;
 }

