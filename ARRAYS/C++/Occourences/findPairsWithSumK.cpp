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
int binarySearch(int arr[],int start,int end,int key){
  int mid = (start + end)/2;
  //cout<<start<<"-"<<end<<endl;

  if(start>end){
    return 0;
    }
  if(arr[mid] == key){
    return mid;
  }
  else if(arr[mid] > key){
    return binarySearch(arr,start,mid-1,key);
  }
  else{
    return binarySearch(arr,mid+1,end,key);
  }
}

int findPairsWithk(int arr[], int size , int sum){

  int index = 0;
  int counter = 0;
    sort(arr,arr+size);

    while(size--){
      int findSumOf = sum-arr[index];
      int secondPair = binarySearch(arr,0,size,findSumOf);

      if(arr[index]+arr[secondPair] == sum){
      cout<<"{"<<arr[index]<<", "<<arr[secondPair]<<"}"<<endl;
      counter++;

      }

      index++;


    }
    return counter;

  }
int main()
{

    int size = 4;
    int arr[] =  {2,3,3,2};
    int sum = 5;

    int foundSum = findPairsWithk(arr,size,sum);

    cout<<"The count of pairs with sum k is "<<foundSum<<endl;

}
