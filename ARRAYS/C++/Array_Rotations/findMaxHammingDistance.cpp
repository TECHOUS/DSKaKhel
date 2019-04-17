#include<iostream>
#include<limits>
#include<math.h>
using namespace std;

int maxHammingDistance(int *arr,int n){
    // arr[] to brr[] two times so that 
    // we can traverse through all rotations. 
    int brr[2 *n + 1];
    for (int i = 0; i < n; i++) 
        brr[i] = arr[i]; 
    for (int i = 0; i < n; i++)  
        brr[n+i] = arr[i]; 
  
    // We know hamming distance with 0 rotation 
    // would be 0. 
    int maxHam = 0;     
  
    // We try other rotations one by one and compute 
    // Hamming distance of every rotation 
    for (int i = 1; i < n; i++) 
    { 
        cout<<"This is the iteration no "<<i<<endl;
        int currHam = 0; 
        for (int j = i, k=0; j < (i + n); j++,k++){
            cout<<"comparing "<<brr[j]<<" with "<<arr[k]<<endl;  
            if (brr[j] != arr[k]){ 
                 currHam++; 
            }
        }
  
        // We can never get more than n.  
        if (currHam == n) 
            return n; 
  
        maxHam = max(maxHam, currHam); 
    } 
  
    return maxHam; 
}

int main(){
    int size,*arr;
    cout<<"Enter the size"<<endl;
    cin>>size;
    arr = new int[size];
    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    int h_distance = maxHammingDistance(arr,size);
    cout<< h_distance<<endl;
}