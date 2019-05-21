#include<stdio.h>
#include<conio.h>
#include<math.h>

int adj[10][10];
int n,m,x[10]={0};

void display()
{
   int i;

   for(i=1;i<=n;i++)
   {
      printf("%d ",x[i]);
   }
   printf("\n");
}

void nextvalue(int k)
{
   int j;
   label2 :
   x[k]=(x[k]+1)%(m+1);
   if(x[k]==0)
      return;

   for(j=1;j<k;j++)
      if((x[k]==x[j]) && adj[k][j]==1)
	  goto label2;
   return;
}

void colorgraph(int k)
{
   label : nextvalue(k);

   if(x[k]==0)
      return;
   if(k==n)
      display();
   else
      colorgraph(k+1);
   goto label;
}

void main()
{
   int i,e,v1,v2;
   clrscr();
   printf("\n\n Enter n : ");
   scanf("%d",&n);

   printf("\n\n Enter e : ");
   scanf("%d",&e);

   for(i=0;i<e;i++)
   {
      printf("\n\n Enter end co-ordinates : ");
      scanf("%d%d",&v1,&v2);
      adj[v1][v2]=adj[v2][v1]=1;
   }

   printf("\n\nEnter m : ");
   scanf("%d",&m);

   colorgraph(1);
   getch();
}