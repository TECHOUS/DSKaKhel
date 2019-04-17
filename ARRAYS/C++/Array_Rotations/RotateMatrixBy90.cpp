#include<stdio.h>
#include<malloc.h>
#define size 3
void rotate90clockwise(int arr[size][size])
{
  for(int i = 0 ; i < size/2 ; i++ )
  {
    for(int j = 0 ; j < size - i - 1 ; j++)
    {
      int temp = arr[i][j];
      arr[i][j] = arr[size - 1 -j][i];
      arr[size-1-j][i] = arr[size-1- i][size-1-j];
      arr[size-1-i][size-1-j] = arr[j][size-1-i];
      arr[j][size-1-i] = temp;
    }
  }
}

void printMatrix(int arr[size][size])
{
  for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++)
              printf("%d ",arr[i][j]);
          printf("\n");
      }
}
int main()
{
  int arr[size][size];
  for(int i = 0 ; i < size ; i++)
  {
    for(int j = 0 ; j < size ; j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }

  rotate90clockwise(arr);
  printf("The printed matrix is \n");
  printMatrix(arr);
}
