
//TODO: imlementar a nao insercao de nos repetidos
//TODO: insertBST:
//TODO: implementar as duas funcoes q faltam
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

int max(int a, int b){
    return (a > b ? a : b);    
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
	int lh, rh;
	if (n== NULL) return 0;
	lh=treeHeight(n->left);
	rh=treeHeight(n->right);
	if (lh > rh) return lh+1;
	else return rh+1;	
}
//
int numberOfNodes(TTree *n)
{
   	if (n == NULL) return 0;
	return numberOfNodes(n->left) + numberOfNodes(n->right) +1;
}
