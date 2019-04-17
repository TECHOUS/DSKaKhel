#include<iostream>
#include<limits>
#include<algorithm>
#include<stdlib.h>
using namespace std;
/* not working for large testcases */


int search(long int arr[], long int l, long int h, long int key) 
{ 
    if(l > h){
        return -1;
    }

    long int mid = (l+h)/2;

    if(arr[mid] == key){
        return mid;
    }

    if(key >= arr[l] && key <= arr[mid]){

        return search(arr,l,mid-1,key);

    }
    else{
        return search(arr,mid+1,h,key);
    }


    if(key > arr[mid] && key < arr[h] ){
        return search(arr,mid+1,h,key);
    }
    else{
        return search(arr,l,mid-1,key);
    }
} 

int main(){

    long int testcases,size,element,foundIndex;
    long int *arr;
    cout<<"Enter the testcases"<<endl;
    cin>>testcases;
    while(testcases--){
        cout<<"Enter the size"<<endl;
        cin>>size;
        arr = new long int[size];
        cout<<"Enter the array"<<endl;
        for(int i = 0 ; i < size ; i++){
            cin>>arr[i];
        }
        cout<<"Enter the element to be searched"<<endl;
        cin>>element;
        foundIndex = search(arr,0,size-1,element);
        if(foundIndex != -1){
        cout<<foundIndex<<endl;
        }
        else{
            cout<<foundIndex<<endl;
        }
    }
    delete[] arr;
}