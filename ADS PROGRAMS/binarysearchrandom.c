#include<stdio.h>
#include <stdlib.h> 
int Randoms(int lower, int upper) 
{ 
    	int num = (rand() % (upper - lower + 1)) + lower; 
        return num;
 } 
 int main()
  {
        int binarysearch (int A[],int low,int high,int key);
	int n;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	int A[n],i,key;
        printf("Enter the elements : \n");
	for(i=0;i<=n-1;i++)
		 scanf("%d",&A[i]);
	printf("Enter the search element : \n");
	scanf("%d",&key);
	if(binarysearch(A,0,n-1,key))
            printf("ELEMENT %d IS FOUND\n",key);
        else
            printf("ELEMENT %d IS NOT FOUND\n",key);
     return 0;
  }
int binarysearch (int A[],int low,int high,int key)
   {
        int mid;
	srand(time(0));   
	if(low <= high)
	    {
		mid=Randoms(low,high);
		if(key == A[mid])
			return 1;
		else if(key < A[mid])
			return binarysearch(A,low,mid-1,key);
		else
			return binarysearch(A,mid+1,high,key);
	   }
      return 0;
}

