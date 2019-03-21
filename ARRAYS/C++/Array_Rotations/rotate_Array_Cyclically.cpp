#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

/* Time complexity of my programme is O(n * k);

        k stands for the no of rotations needed
        */
       


void cyclicallyRotateArray(int *arr,int size,int k){
    

    while(k--){


    int temp = arr[size-1];

    for(int i = size-1; i > 0 ; i--){

        arr[i] = arr[i-1];
    }

    arr[0] = temp;
    }

}

void printArray(int *arr,int size){

    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<endl;
    }

}
int main(){
    int size,k;
    cout<<"Enter the size"<<endl;
    cin>>size;
    cout<<"Enter the no of rotations"<<endl;
    cin>>k;
    int *arr = new int(size);

    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    cout<<"Rotating the array cyclically"<<endl;
    cyclicallyRotateArray(arr,size,k);
    cout<<"The array after rotating is "<<endl;
    printArray(arr,size);
}