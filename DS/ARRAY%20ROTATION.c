#include <stdio.h>
 
void rotate(int arr[], int n)
{
   int x = arr[n-1], i;
   for (i = n-1; i > 0; i--)
      arr[i] = arr[i-1];
   arr[0] = x;
}
 
int main()
{
    int arr[5] , i,j;
   for(i=0;i<5;i++)
{
scanf("%d",&arr[i]);
}
    int n = 5;
 
    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
 for (j = 0; j < 3; j++)
{
    
rotate(arr, n);}
 
    printf("\nRotated array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    return 0;
}
