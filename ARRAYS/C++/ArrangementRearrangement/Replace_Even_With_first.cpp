#include<iostream>
#include<limits>
#include<stack>
using namespace std;

/*

    The question states

    Input:

    3 -> odd so array will not be bothered
    6
    36
    61
    121
    38
    56
    36
    3
    6
    -1
    
    Output:

    3
    6
    61
    121
    38
    3
    6

    



*/
int processArray(int *arr,int len){
    stack <int> st;
    int j = 0;
    for(int i = 0 ; i < len ; i++){
        if(arr[i] % 2 != 0){
            st.push(arr[i]);
        }
        else if(arr[i] % 2 == 0){
            st.push(arr[i]);
            while(arr[i] % 2 == 0){
                i++;
            }
            st.push(arr[i]);
        }
    }

    while(!st.empty()){
        arr[j++] = st.top();
        st.pop();
        
    }

    
    len = j;
    

return len;
}

int main(){
    int x;
    int len = 1;
    int *arr = new int [10000];
    cin>>x;
    arr[0] = x;

    while(x != -1){
        cin>>x;
        arr[len++] = x;
        }

    int res = processArray(arr,len);
    cout<<"The length of the modified array is " <<res<<endl;

    for(int i = res-1 ; i > 0 ; i--){
        cout<<arr[i]<<endl;
    }


}