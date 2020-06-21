#include<stdio.h>
#include <stdlib.h>
int Randoms(int lower, int upper) 
{ 
    	int num = (rand() % (upper - lower + 1)) + lower; 
        return num;
 } 
void quick(int a[],int low,int high)
{
 int i,j,temp,piv;
  if(low < high)
    {
      i=low;
      j=high;
      srand(time(0));
      piv=a[Randoms(low,high)];
      while(i < j)
       {
         while(a[i] < piv)
          {
            i++;
          }
         while(a[j] > piv)
           {
             j--;
           }
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
       }
    quick(a,low,j-1);
    quick(a,j+1,high);
   }
 }
main()
 {
   int n;
   printf("ENter The Size\n");
   scanf("%d",&n);
   int b[n],i;
   printf("Enter the Elements\n");
    for(i=0;i<n;i++)
       scanf("%d",&b[i]);
    quick(b,0,n-1);
    printf("\nFINAL SORTED ARRAY\n");
    for(i=0;i<n;i++)
     {
       printf("%d\t",b[i]);
      }
  }
