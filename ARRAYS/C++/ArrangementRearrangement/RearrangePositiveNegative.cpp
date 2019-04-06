/*
    Rearrange positive and negative numbers in O(n) time and O(1) extra space
An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

Note: The partition process changes relative order of elements. I.e. the order of the appearance of elements is not maintained with this approach. See this for maintaining order of appearance of elements in this problem.


*/
#include<iostream>
#include<limits>
using namespace std;


void arrangePosNegAlt(int *arr,int size){
    
    int count = 0,idx = 0,storeElements = 0,counter = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < 0){
            // counting the negative values so that we can arrange to that limit only 
            count++;
        }
    } // O(n)

    //if exactly half of the elements are negative
    if(count == (size/2)){
        // perform the basic alternative operations
        // if arr[i] is positive it will occupy the even spaces
        // if arr[i] is odd it will occupy the odd spaces
        while( counter < size){
            //search for first negative number
        }
    }
}


int main(){
    int size;
    cin>>size;
    int *arr = new int[size];

    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    arrangePosNegAlt(arr,size);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }

}