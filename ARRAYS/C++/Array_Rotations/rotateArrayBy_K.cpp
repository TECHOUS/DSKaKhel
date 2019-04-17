#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;



/* This is the basic algorithm with :

    Time Complexity O(n * k) where k is the no of elements to rotate it by
    Space Complexity = 0(n);

    */
void rotateArrayByK(int *arr , int size, int k){

    int j = 1;

    while(k--){
        // take the first element of the array [ before or after rotation ]
        int temp = arr[0];

        // shift the array by 1 element array[0th index ] = its next index and so on.
    for(int i = 0 ; i < size - 1 ; i++){

        // Shifting the elements to the left by 1 element
        arr[i] = arr[i+1];
    }
    // attaching the first to the end by 1 rotation
    // replace the last element with the first for anticlockwise rotation
    arr[size-1] = temp;
    }
}

void printArr(int *arr,int size){
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){

int size,k;
cout<<"Enter the size"<<endl;
cin>>size;
cout<<"Enter the no of elements to rotate by"<<endl;
cin>>k;

int *arr = new int(size);

cout<<"Enter the elements "<<endl;

for(int i = 0 ; i < size ; i++){
    cin>>arr[i];
}

cout<<"performing the rotation"<<endl;
rotateArrayByK(arr,size,k);
cout<<"The array after rotating is "<<endl;
printArr(arr,size);


}