#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;


/*Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.*/

int maxContigeous(int *arr,int size){
    int max_ending = 0,max_so_far = INT_MIN,beg = 0, end = 0;

    for(int i = 0 ; i < size ; i++){
        max_ending  = max_ending + arr[i];
        

        if(max_so_far < max_ending){
            max_so_far = max_ending;
            end = i;
        }
        if(max_ending < 0){
            beg = i+1;
            max_ending = 0;
        }
    }

    for(int i = beg ; i < end ; i++){
        cout<<arr[i]<<" ";
    }
    return max_so_far;
}
int main(){
int size,result;
cin>>size;
int *arr = new int[size];
for(int i = 0 ; i < size ;i++){
    cin>>arr[i];
}

result= maxContigeous(arr,size);
cout<<"\nThe max contigious subarray is "<<result<<endl;
}
