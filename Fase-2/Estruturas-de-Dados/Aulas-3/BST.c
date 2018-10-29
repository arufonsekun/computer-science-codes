//TODO: imlementar a nao insercao de nos repetidos
//TODO: insertBST:
//TODO: implementar as duas funcoes q faltam

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // 10.000.000

struct STree {
  int value;
  struct STree *left, *right;
};

typedef struct STree TTree;

// get free memory for storing the value and pointers
// return the address of the spot
TTree *getMem();
// Insert following Binary Search Tree rules
TTree *insertBST(TTree *, int );
// Delete value from the Binary Search Tree (its properties must be kept)
TTree *deleteBST(TTree *, int );
// Search for a value in the tree from address pointed by r 
TTree *searchSBT(TTree *, int );
//  Impressões ordenada
void PrintInOrder(TTree *);
//
void PrintPreOrder(TTree *);
//
void PrintPosOrder(TTree *);
//
// free up the allocated spaces
void cleanTree(TTree *);
//
int treeHeight(TTree *);
//
int numberOfNodes(TTree *);

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
		
		n=rand()%1500000;
		printf("%d", n);
        //scanf("%d", &n);

		myTree=insertBST(root,n);
		if (root==NULL) root=myTree;
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTempo (em s)%5.2f: \n",time_spent);
    printf("\n# of nodes: %d\n",numberOfNodes(root));
    printf("\nAltura (raiz): %d\n",treeHeight(root));
    printf("\nAltura (1o. filho esq.): %d\n",treeHeight(root->left));
    printf("\nAltura (1o. filho dir.): %d\n",treeHeight(root->right));
    printf("\nAltura (1o. filho esq. do 1o. filho dir.): %d\n",treeHeight(root->right->left));
    printf("\nAltura (1o. filho dir. do 1o. filho dir.): %d\n",treeHeight(root->right->right));
    PrintInOrder(root);
    printf("\n");
    cleanTree(root);
    return 0;
}

TTree *getMem()
{
	TTree *new=(TTree *)malloc(sizeof(TTree));
	if (new==NULL)
	{
		printf("FATAL ERROR! NO MEMORY AVAILABLE!\n");
		return NULL;
	}
	new->right=NULL;
	new->left=NULL;
	return new;
}
// Insert following Binary Search Tree rules
TTree *insertBST(TTree *r, int vl)
{
    if (r==NULL)
    {
		TTree *new=getMem();
		new->value=vl;
		return new;
	}
    else if (r->value != vl){
	    if (vl>=r->value)
	    {
		    if (r->right==NULL)
		    {
  		        TTree *new=getMem();
		        new->value=vl;
			    r->right=new;
			    return new;
		    }
		    return insertBST(r->right,vl);
	    } else
	    {
		    if (r->left==NULL)
		    {
  		        TTree *new=getMem();
		        new->value=vl;
			    r->left=new;
			    return new;
		    }
		    return insertBST(r->left,vl);
	    }
    }
}
// Search for a value in the tree from address pointed by r 
TTree *searchSBT(TTree *r, int vl)
{
	if (r==NULL) return NULL;
	if (r->value==vl) return r;
	if (vl>=r->value) return searchSBT(r->right,vl);
	else              return searchSBT(r->left,vl);
}
//  Impressões ordenada
void PrintInOrder(TTree *r)
{
	if (r==NULL) return;
	PrintInOrder(r->left);
	printf("%d ",r->value);
	PrintInOrder(r->right);
}
//
void PrintPreOrder(TTree *r)
{
	if (r==NULL) return;
	printf("%d ",r->value);
	PrintPreOrder(r->left);
	PrintPreOrder(r->right);
}
//
void PrintPosOrder(TTree *r)
{
	if (r==NULL) return;
	PrintPosOrder(r->left);
	PrintPosOrder(r->right);
	printf("%d ",r->value);
}
//
// free up the allocated spaces
void cleanTree(TTree *r)
{
	if (r==NULL) return;
	cleanTree(r->left);
	cleanTree(r->right);
    free(r);
}	
//
int treeHeight(TTree *n)
{
	return 0;
}
//
int numberOfNodes(TTree *n)
{
   return 0;
}
