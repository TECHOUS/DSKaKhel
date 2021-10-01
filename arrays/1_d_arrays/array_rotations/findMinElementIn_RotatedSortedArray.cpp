#include<iostream>
#include<limits>

using namespace std;

/* O(n) approach , can be done in O(log(n)) using binary search */

int findMinElementInRotatedArray(int *arr , int size){

    int min = INT_MAX;

    for(int i = 0 ; i < size ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
        if(min == INT_MAX){
            return -1;
        }
    return min;
}

int main(){
    int size;
    cout<<"enter the size"<<endl;
    cin>>size;
    int *arr = new int[size];

    cout<<"Enter the elements in the array"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    int result = findMinElementInRotatedArray(arr,size);
    cout<<"The minimum element is "<<endl;
    cout<<result<<endl;

}