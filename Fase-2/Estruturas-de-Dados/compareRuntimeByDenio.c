#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define SIZE 200000 // 1

// doubly linked list
struct DList {
  int value;
  struct DList *left, *right;
};
// simply linked list
struct SList {
  int value;
  struct SList *next;
};
// new type names for both type of lists.
typedef struct DList ListD; 
typedef struct SList ListS;

// ***** Code for doubly list
// allocate memory for doubly list
ListD *getMemD()
{
	ListD *new=(ListD *)malloc(sizeof(ListD));
	if (new==NULL)
	{
		printf("FATAL ERROR! NO MEMORY AVAILABLE!\n");
		exit(0); // program is aborted
	}
	new->right=NULL;
	new->left=NULL;
	return new;
}
// Recursive insertion for doubly list
// put the lesser values in the left and the greater in the right
ListD *insertD(ListD *h, int vl)
{
    if (h==NULL)
    {
		ListD *new=getMemD();
		new->value=vl;
		return new;
	}
	if (vl>=h->value)
	{
		if (h->right==NULL)
		{
  		    ListD *new=getMemD();
		    new->value=vl;
			h->right=new;
			return new;
		}
		return insertD(h->right,vl);
	} else
	{
		if (h->left==NULL)
		{
  		    ListD *new=getMemD();
		    new->value=vl;
			h->left=new;
			return new;
		}
		return insertD(h->left,vl);
	}
}

// Find value recursively in the doubly list
ListD *searchD(ListD *h, int vl)
{
	if (h==NULL) return NULL;
	if (h->value==vl) return h;
	if (vl>=h->value) return searchD(h->right,vl);
	else              return searchD(h->left,vl);
}
// Clean up the doubly list
void cleanDList(ListD *h)
{
	if (h==NULL) return;
	cleanDList(h->left);
	cleanDList(h->right);
    free(h);
}	

// ***** Code for simply list
// allocate memory for simply list
ListS *getMemS()
{
	ListS *new=(ListS *)malloc(sizeof(ListS));
	if (new==NULL)
	{
		printf("FATAL ERROR! NO MEMORY AVAILABLE!\n");
		return NULL;
	}
	new->next=NULL;
	return new;
}
// insert a new value to the end of the list
// using head
ListS *insertSH(ListS *h, int vl)
{
    ListS *new, *aux;
    new=getMemS();
    new->value=vl;
    new->next=NULL;
    if (h==NULL) // lista vazia
    {
		return new;
    }
    aux=h; // aux recebe o endereço da cabeça da lista (primeiro)
    while (aux->next!=NULL) 
		aux=aux->next;
	aux->next=new;
	return new;
}
//
// insert a new value to the end of the list
// using tail
ListS *insertST(ListS *t, int vl)
{
    ListS *new;
    new=getMemS();
    new->value=vl;
    new->next=NULL;
    if (t==NULL) // lista vazia
    {
		return new;
    }
    t->next=new;
	return new; // caller must assign the result to tail
}
//
ListS *searchS(ListS *p,int vl)
{
	ListS *aux;
	while (p!=NULL)
	{
	   aux=p->next;
	   if (p->value==vl) return p; 
	   p=aux;
    }
	return NULL;
}

// Clean up the simply list
void cleanSList(ListS *p)
{
	ListS *aux;
	while (p!=NULL)
	{
	   aux=p->next;
	   free(p);
	   p=aux;
    }
}
////
//// Copy from stackoverflow
void printfpoint (long int n) {
    if (n < 0) {
        printf ("-");
        printfpoint (-n);
        return;
    }
    if (n < 1000) {
        printf ("%ld", n);
        return;
    }
    printfpoint (n/1000);
    printf (".%03ld", n%1000);
}
/////
int main()
{
    ListD *myD=NULL, *headD=NULL;
    ListS *myS=NULL, *headS=NULL, *tailS=NULL;
    long int i, SIZE;
    int n;
    printf("Número de elementos para teste: ");
    scanf("%ld",&SIZE);
    //// DUBLY LIST
    printf("Testing execution time for doubly list...\n");
    clock_t begin, end;
    double time_spent;
    printf("Inserting ");
    printfpoint(SIZE);
    printf(" values into doubly list...\n");
    begin=clock();
    for (i=1;i<=SIZE;i++)
    {
		printf("%ld\r\r\r\r\r\r\r\r\r\r\r",i);
		myD=insertD(headD,rand());
		if (headD==NULL) headD=myD;
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time (in s): %5.2f\n",time_spent);
    n=rand();
    printf("Searching value %d...\n",n);
    begin=clock();
    searchD(headD,n);
    end=clock();
    time_spent=(double)(end-begin); // / (CLOCKS_PER_SEC/1000); 
    printf("Execution time (in cloks): %5.2f\n",time_spent);
    //
    // free memory for next test
    cleanDList(headD);
    /////////////////////////////////
    //
    printf("\n\nInserting ");
    printfpoint(SIZE);
    printf(" values into simply list (without tail) ...\n");
    begin=clock();
    for (i=1;i<=SIZE;i++)
    {
		printf("%ld\r\r\r\r\r\r\r\r\r\r\r",i);
		// myS=insertSH(headS,rand());
		if (headS==NULL) headS=myS;
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time (in s): %5.2f\n",time_spent);
    ////
    cleanSList(headS);
    ////
    headS=NULL; // reset headS
    printf("\n\nInserting ");
    printfpoint(SIZE);
    printf(" values into simply list (with tail) ...\n");
    begin=clock();
    for (i=1;i<=SIZE;i++)
    {
		printf("%ld\r\r\r\r\r\r\r\r\r\r\r",i);
		tailS=insertST(tailS,rand());
		if (headS==NULL) headS=tailS;
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time (in s): %5.2f\n",time_spent);
    ////
    n=rand();
    printf("Searching value %d...\n",n);
    begin=clock();
    searchS(headS,n);
    end=clock();
    time_spent=(double)(end-begin); //  / (CLOCKS_PER_SEC/1000); 
    printf("Execution time (in cloks): %5.2f\n",time_spent);
    //
    // free memory for next test
    cleanSList(headS);
    return 0;
}
