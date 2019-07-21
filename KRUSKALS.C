//Created by Nihar Anant koli

#include<conio.h>
#include<stdio.h>
int set[100];

typedef struct weight
{
   int u,v,wit;
}weight;

void sort(weight wt[],int m)
{
   weight t;
   int i,j;
   for(i=0;i<m;i++)
   {
      for(j=0;j<m-1;j++)
      {
	 if(wt[j].wit>wt[j+1].wit)
	 {
	    t=wt[j+1];
	    wt[j+1]=wt[j];
	    wt[j]=t;
	 }
      }
   }
}

int check(int k,int m)
{
   int i;
   for(i=0;i<m;i++)
   {
      if(set[i]==k)
      {
	 set[i]=-1;
	 return 1;
      }
   }
   return 0;
}

void MSTkruskals(weight wt[],int m)
{
   int uk,vk,witk,i=0,unio[5][3],cost=0,l,r;

   while(i<m)
   {
      uk=wt[i].u;
      vk=wt[i].v;
      witk=wt[i].wit;

      l=check(uk,m);
      r=check(vk,m);

      if(l||r)
      {
	 unio[i][0]=uk;
	 unio[i][1]=vk;
	 unio[i][2]=witk;
      }
      else
      {
	 unio[i][0]=0;
	 unio[i][1]=0;
	 unio[i][2]=0;
      }
      i++;
   }

   for(i=0;i<m;i++)
   {
      if(unio[i][0]!=0 && unio[i][1]!=0)
      {
	 printf("(%d,%d)",unio[i][0],unio[i][1]);
      }
   }

   for(i=0;i<m;i++)
   {
      cost = cost + unio[i][2];
   }

   printf("\n Cost : %d\n",cost);
}

void main()
{
    int i,n,m;
    weight wt[100];

    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    printf("\nEnter the vertices : ");
    for(i=0;i<n;i++)
    {
       scanf("%d",&set[i]);
    }

    printf("\nEnter number of edges : ");
    scanf("%d",&m);

    printf("\nEnter edged aong with weights \nu v wt\n");
    for(i=0;i>m;i++)
    {
       scanf("%d%d%d",&wt[i].u,&wt[i].v,&wt[i].wit);
    }

    sort(wt,m);
    printf("\nSorted : \n");
    for(i=0;i<m;i++)
    {
       printf("\n%d\t%d\t%d\t",wt[i].u,wt[i].v,wt[i].wit);
    }

    printf("\nMST Kruskals : \n");
    MSTkruskals(wt,m);

    getch();
}
