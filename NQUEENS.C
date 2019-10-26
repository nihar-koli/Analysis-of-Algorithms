//Implementation of NQueens Algorithm
//Created by Nihar Anant koli

#include<stdio.h>
#include<conio.h>
#include<math.h>

int n;
int x[10]={0};

void display()
{
   int i,j;

   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
	 if(x[i]==j)
	    printf("Q ");
	 else
	    printf("0 ");
      }
      printf("\n");
   }
   printf("\n\n");
}

void nextvalue(int k)
{
   int j;
   label2 :
   x[k]=(x[k]+1)%(n+1);
   if(x[k]==0)
      return;

   for(j=1;j<k;j++)
      if((x[k]==x[j]) || (abs(x[k]-x[j])==abs(k-j)))
	  goto label2;
   return;
}

void nqueens(int k)
{
   label : nextvalue(k);

   if(x[k]==0)
      return;
   if(k==n)
      display();
   else
      nqueens(k+1);
   goto label;
}

void main()
{
   clrscr();
   printf("\n\n Enter n : ");
   scanf("%d",&n);
   nqueens(1);
   getch();
}
