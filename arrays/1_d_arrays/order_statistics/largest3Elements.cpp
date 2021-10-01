/* find the largest 3 elements of the array */





#include<iostream>
#include<algorithm>
using namespace std;



int findLargest(int *arr,int size){

  sort(arr, arr + size);
  int check = 0, count = 1; 
          
    for(int i = 1; i <= n; i++) 
    { 
              
        if(count<4) 
        { 
            if(check != arr[n - i])  
            {  
                // to handle duplicate values 
                cout << arr[n - i] << " "; 
                check = arr[n - i]; 
                count++; 
            } 
        } 
        else
            break; 
    } 
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