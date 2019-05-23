//Implementation of Fractional knapsack algorithm

#include<conio.h>
#include<stdio.h>

typedef struct input
{
   float p,w;
   int prono;
}input;

typedef struct inlist
{
   input data[50];
   int n;
}inlist;

inlist list1;
int n;
float m;
float x[50];
float cp=0.0;
float cw=0.0;

void sort()
{
   input temp;
   int i,j;

   for(i=1;i<list1.n;i++)
   {
      for(j=1;j<list1.n;j++)
      {
	 if((list1.data[j].p/list1.data[j].w) < (list1.data[j+1].p/list1.data[j+1].w))
	 {
	    temp = list1.data[j];
	    list1.data[j]=list1.data[j+1];
	    list1.data[j+1]=temp;
	 }
      }
   }
}

void fknap()
{
   int i,j;

   for(i=1;i<=n;i++)
   {
      if(cw+list1.data[i].w < m)
      {
	 x[list1.data[i].prono]=1.0;
	 printf("\n\nProduct %d is taken",list1.data[i].prono);
	 cw = cw + list1.data[i].w;
	 cp = cp + list1.data[i].p;
      }
      else
      {
	 x[list1.data[i].prono]=(float)(m-cw)/list1.data[i].w;
	 cp = cp + list1.data[i].p * x[i];
	 cw = m;
	 printf("\n\nProduct %d is taken",list1.data[i].prono);
	 return;
      }
   }
}

void main()
{
   int i;
   clrscr();

   printf("\n\nEnter number of items : ");
   scanf("%d",&n);

   printf("\n\nEnter maximum capacity : ");
   scanf("%f",&m);

   list1.n=1;

   for(i=1;i<=n;i++)
   {
      printf("\n Enter profit and weight for item %d : ",i);
      scanf("%f%f",&list1.data[list1.n].p,&list1.data[list1.n].w);
      list1.data[list1.n].prono=list1.n;
      list1.n++;
      printf("\n");
   }

   sort();

   printf("\n\nSorted : \n");
   for(i=1;i<=list1.n;i++)
   {
     printf("%f\t%f\t%d",list1.data[i].p,list1.data[i].w,list1.data[i].prono);
     printf("\n");
   }

   fknap();

   for(i=1;i<=n;i++)
   {
      printf("%f\t",x[i]);
   }

   printf("\n\nTotal profit : %f",cp);
   printf("\n\nTotal weight : %f",cw);

   getch();
}
