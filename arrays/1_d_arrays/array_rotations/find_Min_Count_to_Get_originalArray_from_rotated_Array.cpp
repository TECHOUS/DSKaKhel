#include <iostream>
#include <limits>
using namespace std;


int findMin_RotatedArray(int *arr,int size){

    int min = INT_MAX;

    for(int i = 0 ; i < size ; i++){
        if(arr[i] > arr[i+1]){
            min = i+1;
            break;
        }
    }

    if(min == INT_MAX){
        return 0;
    }

    return min;
}

int main(){
    int testcases,size,*arr,getMin=0;
    cout<<"Enter ammount of testcases"<<endl;
    cin>>testcases;

    while(testcases--){
        cout<<"Enter the size"<<endl;
        cin>>size;
        arr = new int[size];
        cout<<"Enter the elements in the array"<<endl;
        for(int i = 0 ; i < size ; i++){
            cin>>arr[i];
        }

        getMin = findMin_RotatedArray(arr,size);
        cout<<"The minimum value is "<<endl;
        cout<<getMin<<endl;
    }

}