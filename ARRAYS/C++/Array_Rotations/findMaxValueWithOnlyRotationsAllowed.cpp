#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

/* 
                    A = 1 20 2 10

                    after 2 rotations 

                    2 10 1 20

                    the sum becomes 72

                    which is max;


                    COMPLEXITIES:

                    TimeComplexity is most probably 2O(n*k), where k = no of rotations
                    SpaceComplexity is O(m+n);



*/

/* Brute force method */
void printSumArr(int * , int);
int Calculate_Rotation_Sum(int * arr, int size){
    int eachRotationSum = 0; 
    for(int i = 0 ; i < size ; i++ ){
        eachRotationSum += arr[i]*i;
    }

    return eachRotationSum;
}

void RotateArray(int * arr ,int size){
        int temp = arr[0];

        for(int i = 0 ; i < size - 1 ; i++){
            arr[i] = arr[i+1];
        }

        arr[size-1] = temp;
    } 

int findMaxWithOnly_Rotations(int *arr,int size){
    
    int firstSum = 0,j=0,rotations = 0,foundMax = 0;
    int *rotationSum = new int[size];
    /* find all rotations and sum them */
    
    for(int i = 0 ; i < size ; i++){
            firstSum += arr[i]*i; 
    } //O(n)
    rotationSum[j] = firstSum;
    j = 1;

    while(rotations < size){
    RotateArray(arr,size);
    rotationSum[j++] = Calculate_Rotation_Sum(arr,size);
    rotations++;
    }

    printSumArr(rotationSum , size);
    for(int i = 0 ; i < j ; i++){
            foundMax = max(rotationSum[i],foundMax);
        }

    return foundMax;
}

void printSumArr(int * arr , int size){

    cout<<"The array rotations are"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    printf("\n");
}
int main(){

    int size,*arr;
    cout<<"Enter the size"<<endl;
    cin>>size;
    arr = new int[size];

    cout<<"Enter the array"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    int Max_Sum = findMaxWithOnly_Rotations(arr,size);
    cout<<"The max sum is "<<Max_Sum<<endl;
}