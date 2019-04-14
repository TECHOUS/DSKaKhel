#include<iostream>
#include<algorithm>
using namespace std;



int findLargest(int *arr,int size){

    int max = INT_MIN;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}
int main(){
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    int result = findLargest(arr,size);
    cout<<"The largest element is "<<result<<endl;

}