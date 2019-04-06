#include <iostream>
#include<map>
#include<iterator>
#include<stdlib.h>
using namespace std;
/*

Given an sorted array of size N with duplicate eliments,
find the count of the given number k in the array arr */

// input :
//  N = 7 k = 2
//  arr = 1 1 2 2 2  3
//
//

/*Build logic    1 1 2 2 2 2 3                        */

void findCountOf(int arr[], int n , int k){
  int *countArr = (int *) malloc (n * sizeof(int));
  map <int , int> storeCounts;
  map <int,int> :: iterator it;
  countArr[n] = {-1};
  for (int i = 0; i < n; i++) {
    storeCounts[arr[i]]++;
  }
  for(it = storeCounts.begin() ; it!= storeCounts.end() ; it++){
    cout<<"{"<<it->first<<","<<it->second<<"}"<<endl;
  }
  it = storeCounts.find(k);


  cout<<it->second<<endl;
}
int main() {
  int testcases;
  cout<<"Enter the number of testcases"<<endl;
  cin>>testcases;

  while(testcases--){
  int size,toFindCountOf;
  cout<<"Enter the size"<<endl;
  cin>>size;
  cout<<"Enter the number to find the count of"<<endl;
  cin>>toFindCountOf;

  int *arr = (int *) malloc ( size * sizeof(int));

  cout<<"Enter the elements in the array"<<endl;
  for(int i = 0 ; i < size ; i++){
    cin>>arr[i];
  }

    findCountOf(arr,size,toFindCountOf);
  }
}
