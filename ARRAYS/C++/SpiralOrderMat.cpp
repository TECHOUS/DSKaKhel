#include<stdio.h>
#include<malloc.h>

int main()
{
  int rows,cols,i,j,k;
  scanf("%d",&rows);
  scanf("%d",&cols);
  int arr[rows][cols] = {0};

  for(i = 0 ; i < rows ; i++)
  {
    for(j = 0 ; j < cols ; j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }

  int startingRow = 0;
  int startingCol = 0;
  int endingRow = rows-1;
  int endingCol = cols-1;

  while(startingRow <= endingRow && startingCol <= endingCol)
  {
    for(j = startingCol ; j <= endingCol ; j++)
    {
      printf("%d\n",arr[startingRow][j]);
    }
    startingRow++;

    for(j = startingRow ; j <= endingRow ; j++)
    {
      printf("%d\n",arr[j][endingCol]);
    }
    endingCol--;

    if(startingCol < endingRow)
    {
      for(j = endingCol ; j>=startingCol ; --j)
      {
        printf("%d\n",arr[endingRow][j]);
      }
      endingRow--;
    }
    if(startingCol<endingCol)
    {
      for(j = endingRow ; j>=startingRow ; --j)
      {
        printf("%d\n",arr[j][startingCol]);
      }
      startingCol++;
    }
  }
  return 0 ;
}
