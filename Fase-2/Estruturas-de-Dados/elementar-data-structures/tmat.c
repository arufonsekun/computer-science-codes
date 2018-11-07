//tmat struct by Denio
#include <stdio.h>

#define MAXR 10
#define MAXC 5

struct TMat{
   int last_row, last_col;
   int mat[MAXR][MAXC];
};

void initMat(struct TMat *m)
{
   m->last_row=-1;
   m->last_col=-1;
}

void setMat(struct TMat *m, int value)
{
   m->last_col++;
   if (m->last_col>=MAXC)
   {
       m->last_col=0;
       m->last_row++;
   }

   if (m->last_row>=MAXR)
   {
       printf("No available space!\n");
       return;
   }
   if (m->last_row==-1) m->last_row++;
   m->mat[m->last_row][m->last_col]=value;
}

void printMat(struct TMat m)
{
    int i,j;
    for (j=0;j<=m.last_row && j<MAXR;j++)
    {
        if (j==m.last_row)
           for (i=0;i<=m.last_col;i++)
               printf(" %d",m.mat[j][i]);
        else
           for (i=0;i<MAXC;i++)
               printf(" %d",m.mat[j][i]);

        printf("\n");
    }
    return;
}

void getValue(struct TMat m, int el){
    int i, j;
    int find = 0;
    for (j = 0; j <= m.last_row; j++){
        for (i = 0; i <= MAXC; i++){
            if (m.mat[i][j] == el)
                find = 1;
        }
    }

    printf("%d\n", (find == 1 ? 1 : 0) );

}

int main()
{
   struct TMat matriz;
   initMat(&matriz);
   for (int i=0;i<27;i++)
      setMat(&matriz,i);

   getValue(matriz, 50);
   printMat(matriz);
   return 0;
}
