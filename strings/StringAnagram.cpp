#include<iostream>
#include<string>
#include<limits>
#include<ctype.h>
#include<algorithm>
#include<map>

using namespace std;


/* COUNT ALL THE CHARACTERS THAT NEED TO BE DELETED OR INSERTED TO MAKE THE STRING ANAGRAM */

int makeAnagram(string a, string b) {

    map <char,int> storeCounts;
    map <char,int> storeCounts1;

    map <char,int> :: iterator it;
    int count  = 0;


    for(int i = 0 ; i < a.length() ; i++){
        storeCounts[a[i]]++;
    }
    for(int i = 0 ; i < b.length() ; i++){
        storeCounts[b[i]]--;
    }
    for(it = storeCounts.begin() ; it != storeCounts.end() ; it++){
       // cout<<"{"<<it->first<<","<<it->second<<"}"<<endl;
        count += abs(it->second);  
    }
    return count;

}


int main(){
    
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);
    cout<<res<<endl;
}
