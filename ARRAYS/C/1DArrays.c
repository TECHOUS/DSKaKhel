/*I DIMENSIONAL ARRAY*/

#include <stdio.h>
int main()
{
    int n;                                      //size of the array
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];                                 //declared array of size n

    printf("Enter elements of the array\n");
    for(register int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Entered array by the user\n");
    for(register int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%d\n",arr[i]);    
        }
        else
        {
            printf("%d ",arr[i]);
        }
    }
}