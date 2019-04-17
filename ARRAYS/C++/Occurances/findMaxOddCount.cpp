#include<iostream>
#include<limits>
#include<map>
#include<iterator>
using namespace std;

long int findMaxOdd(long int *,long int);

int main(){
    long int size;
    cin>>size;
    long int * arr = new long int[size];

    for(long int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    long int result = findMaxOdd(arr,size);
    cout<<"The result is "<<result<<endl;
}

long int findMaxOdd(long int *arr,long int size){
    map <long int,long int> store;
    map <long int,long int> :: iterator it;
    long int maximum = INT_MIN;
    for(long int i = 0 ; i < size ; i++){
        if(arr[i] % 2 != 0){
            store[arr[i]]++;
        }
    }

    for(it = store.begin() ; it != store.end() ; it++){
        maximum = max(it->second,maximum);
        }
        it = store.find(maximum);

    
    return it->first;
}