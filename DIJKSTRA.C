//Created by Nihar Anant Koli

#include<conio.h>
#include<stdio.h>

int n;
int d[20];
int pi[20];
int q[20];

int extract_min()
{
   int pos,i,min;

   for(i=0;i<n;i++)
   {
      if(q[i]!=-1)
      {
	 min=d[i];
	 pos=i;
	 break;
      }
   }
   for(i=0;i<n;i++)
   {
      if(d[i]<min && q[i]!=-1)
      {
	 min=d[i];
	 pos=i;
      }
   }
   return pos+1;
}

void MSTprims(int wt[][10],int r)
{
   int i,u,v,count;

   for(i=0;i<n;i++)
   {
      d[i]=999;
   }
   for(i=0;i<n;i++)
   {
      pi[i]=-1;
   }
   d[r-1]=0;

   for(i=0;i<n;i++)
   {
      q[i]=i+1;
   }
   count=n;

   while(count!=0)
   {
      u=extract_min();
      q[u-1]=-1;
      count--;


      for(i=0;i<n;i++)
      {
	 v=q[i];
	 if(wt[u-1][v-1]!=999 && v!=-1)
	 {
	    if((wt[u-1][v-1]+d[u-1])<d[v-1])
	    {
	       d[v-1]=wt[u-1][v-1]+d[u-1];
	       pi[v-1]=u;
	    }
	 }
      }
      printf("\n");
      printf("\nd: ");
      for(i=0;i<n;i++)
	 printf("%d ",d[i]);

      printf("\npi: ");
      for(i=0;i<n;i++)
	 printf("%d ",pi[i]);
   }
   getch();
}

void main()
{
    int wt[10][10],i,j,r,t=0;
    clrscr();
    flushall();
    printf("\n\n Enter number of vertices : ");
    scanf("%d",&n);
    flushall();

    printf("\n\n Enter weight adj. matrix (999 for infinity) : ");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
	  scanf("%d",&wt[i][j]);
       }
    }
    flushall();

    printf("\n\n Enter starting node : ");
    scanf("%d",&r);

    MSTprims(wt,r);

    printf("\n\nFinal value of d: ");
    for(i=0;i<n;i++)
    {
       printf("%d ",d[i]);
       t=t+d[i];
    }

    printf("\n\nFinal value of pi: ");
    for(i=0;i<n;i++)
    {
       printf("%d ",pi[i]);
    }

    printf("\n\nTotal Cost : %d",t);

    for(i=0;i<n;i++)
    {
       printf("\nCOst from %d to %d : %d",r,i,d[i]);
    }
    getch();
}
