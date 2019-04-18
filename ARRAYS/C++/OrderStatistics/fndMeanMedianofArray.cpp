/*
Program for Mean and median of an unsorted array
Given n size unsorted array, find its mean and median.

Mean of an array = (sum of all elements) /
                   (number of elements)

Median of a sorted array of size n is defined 
as below : 
It is middle element when n is odd and average
of middle two elements when n is even.

Since the array is not sorted here, we sort 
the array first, then apply above formula.
Examples:

Input  : a[] = {1, 3, 4, 2, 6, 5, 8, 7}
Output : Mean = 4.5
         Median = 4.5
Sum of the elements is 1 + 3 + 4 + 2 + 6 + 
5 + 8 + 7 = 36
Mean = 36/8 = 4.5
Since number of elements are even, median
is average of 4th and 5th largest elements.
which means (4 + 5)/2 = 4.5

Input  : a[] = {4, 4, 4, 4, 4}
Output : Mean = 4
         Median = 4 
*/

#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

int findMean(int *arr,int size){
    float sum = 0;
    for(int i = 0 ; i < size ; i++){
        sum += arr[i];
    }

    return (float)sum/size;

}
int findMedian(int *arr,int size){
    sort(arr,arr+size);
    int median;

    if(size % 2 == 0){
        median = (arr[(size/2)-1]+arr[size/2])/2;
    }else{
        median = arr[(size/2)];
    }
    return float(median);
}
int main(){
    int size;
    cin>>size;
    int * arr = new int[size];

    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    cout<<"The mean is "<<(float)findMean(arr,size)<<endl;
    cout<<"The median is"<<(float)findMedian(arr,size)<<endl;


}