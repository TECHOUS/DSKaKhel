#include<bits/stdc++.h>
using namespace std;




int KthLargestMaxSumSubarray(int *arr,int size,int k){


    
    return 0;
}
int main(){

    int size,k;
    cin>>size;
    int *arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cin>>k;

    int result = KthLargestMaxSumSubarray(arr,size,k);
    cout<<result<<endl;
    return 0;
}