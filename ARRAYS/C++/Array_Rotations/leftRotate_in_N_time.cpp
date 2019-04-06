#include<iostream>
#include<limits>
using namespace std;

void rotateInN_Time(int *arr,int size,int k){
    int mod = k % size;
    cout<<"The starting point is "<<mod<<endl;

    for(int i = 0 ; i < size ; i++){
        cout<<"The equation values are comming to be "<< (mod+i)%size<<endl;
        cout<<arr[(mod+i)%size]<<" ";
    }
    printf("\n");
}
int main(){
    int size,k;
    cin>>size;
    cin>>k;
    int *arr = new int[size];

    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    rotateInN_Time(arr,size,k);
}