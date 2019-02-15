#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;


/* base logic of find sum with pairs k

nput  :  arr[] = {1, 5, 7, -1},
  sum = 6
Output :  2
Pairs with sum 6 a

Input  :  arr[] = {1, 5, 7, -1, 5},
  sum = 6
Output :  3
Pairs with sum 6 are (1, 5), (7, -1) &
             (1, 5)

Input  :  arr[] = {1, 1, 1, 1},
  sum = 2
Output :  6
There are 3! pairs with sum 2.

Input  :  arr[] = {10, 12, 10, 15, -1, 7, 6,
           5, 4, 2, 1, 1, 1},
  sum = 11
Output :  9
    */


    // this codes complexity = O(n^2);
int findPairsWithk(int arr[], int size , int sum){
int count = 0;
  for(int i = 0 ; i < size ; i++)
  {
      for(int j = i+1 ; j < size ; j++){
          if(arr[i]+arr[j] == sum){
              count++;
          }
        }
  }
  return count;
}
int main()
{

    int size = 13;
    int arr[] =  {10, 12, 10, 15, -1, 7, 6,
               5, 4, 2, 1, 1, 1};
    int sum = 11;

    int foundSum = findPairsWithk(arr,size,sum);

    cout<<"The count of pairs with sum k is "<<foundSum<<endl;

}
