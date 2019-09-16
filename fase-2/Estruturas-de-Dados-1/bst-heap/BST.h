#ifndef BST
#define BST

#define SIZE 10
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
 int treeHeight(TTree *n);
 //
 int numberOfNodes(TTree *);
#endif
