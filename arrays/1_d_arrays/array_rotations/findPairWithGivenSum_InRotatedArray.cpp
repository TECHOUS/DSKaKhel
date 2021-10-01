#include<iostream>
#include<algorithm>
#include<limits>
#include<map>
#include<iterator>

using namespace std;

/* 
        BruteForce with least complexity :

        MergeSort => O(nlog(n));
        BinarySearch => O(log(n));

        T(n) = T(nlog(n))+T(log(n));

        MAX COMPLEXITY O( n * log(n));



        */
int binarySearch(int * arr , int start , int end , int key){

    if(start > end){
        return 0 ;
    }
    int mid = (start + end)/2;

    if(arr[mid] == key){
        return mid;
    }
    else if(key > arr[mid]){
        binarySearch(arr,mid+1,end,key);
    }
    else{
        binarySearch(arr,start,mid-1,key);
    }


}

void findSumIn_Rotated_Sorted_Array(int *arr,int size , int sum){
    map<int,int> storePairs;
    map<int,int> :: iterator it;
    bool flag = false;
    /* CODE WITH THE MAXIMUM COMPLEXITY */
    // Sort the array , best would have been mergeSort 
    sort(arr,arr+size);
    int i = 0;
    while(i < size){
        int temp = arr[i];
        int findNextSum = (sum - temp);
        int index = binarySearch(arr,0,size-1,findNextSum);
        

        if(index == 0){
        }
        else{
            storePairs.insert(pair<int,int>(temp,arr[index]));
            flag = true;
        }
        i++;
    }

    if(flag == true){
        cout<<"true"<<endl;

        cout<<"The pairs are"<<endl;

        for(it = storePairs.begin(); it!= storePairs.end() ; it++){
            cout<<"{ "<<it->first<<" , "<<it->second<<"}"<<endl;
        }
    }
    else{
        cout<<"false"<<endl;
    }

}
int main(){

    int size,*arr,sum;
    cout<<"Enter the size"<<endl;
    cin>>size;
    arr = new int[size];
    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cout<<"Give the sum whose pair is to be found"<<endl;
    cin>>sum;

    findSumIn_Rotated_Sorted_Array(arr,size,sum);
    delete[] arr;


}