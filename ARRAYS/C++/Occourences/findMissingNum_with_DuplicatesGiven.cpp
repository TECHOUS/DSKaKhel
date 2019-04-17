#include<iostream>
#include<limits>
#include<map>
#include<iterator>
using namespace std;


/* Question 

This is a really good question
        always the input will be 1 -> n

        INPUT : 3 1 3 2 5
        OUTPUT : 3 -> duplicate
                 4 -> missing number


                 Method 1:

                 using map store the counts of values.
                if value count >= 2
                that is the duplicate number.
                and if the count of that number is 0
                then the missing number is that only.
*/
void findMissingNum(long long int *arr,long long int size){

    map <int,int> storeCount;
    map <int,int> :: iterator it;
    int duplicateNum = 0,missingNum = 0;
    for(int i = 0 ; i < size ; i++){
        storeCount[arr[i]]++;
        storeCount[i+1]++;
    }

    for(it = storeCount.begin() ; it != storeCount.end() ; it++){
        
      cout<<"{"<<it->first<<" , "<<it->second<<"}"<<endl;
       if(it->second > 2){
           duplicateNum  = it->first;
       }
       else if(it->second == 1){
           missingNum = it->first;
       }
    }

    cout<<"The dup number is "<< duplicateNum<<endl;
    cout<<"The miss number is "<< missingNum<<endl;


   
}
int main(){
    long long int size;
    cin>>size;
    long long int *arr = new long long int[size];
    for(long long int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    findMissingNum(arr,size);
}