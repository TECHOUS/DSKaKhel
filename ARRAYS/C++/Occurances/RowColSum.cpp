#include<stdio.h>
#include<malloc.h>

int main()
{
  int testcases;
  scanf("%d\n",&testcases );
  while(testcases--)
  {
    int N,W;
    int X;
    char R;
    scanf("%d %d",&N,&W );
    scanf("%d %c",&X,&R);
    int i , j, k;
    int arr[100][100]={0};
    int sum = 0;
    k = 1;
    for(i = 0 ; k <=N ; i++)
    {
      for(j = 0 ; j < W && k <= N ; j++ )
      {
        arr[i][j] = k;
        k = k+1;
      }
    }
    k = i;

    if(R == 'C')
    {
      for(i = 0 ; i <= k ; i++)
      {
          sum += arr[i][X-1];
      }
    }
    else
    {
      for(i = 0 ; i < W ; i++)
      {
        sum = sum + arr[X-1][i];
      }
    }
    printf("%d\n",sum );
  }

  return 0;
}
