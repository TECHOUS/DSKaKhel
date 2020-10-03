#include<bits/stdc++.h>
typedef long long int ll;
#define vi vector<ll>
#define pi pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define B begin()
#define E end()
#define mp make_pair
using namespace std;
 
 
suffixArray(string str, int n){
    str+='$'; 
    n+=1;
    vector<pair<char,int> >index;
    for(int i =0; i < n; i++){
        index.pb(mp(str[i],i));
    }
    sort(index.B,index.E);
    vector<int> p(n),c(n);
    int idx = 0;
    for(int i = 0; i < n; i++) p[i] = index[i].S;
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(index[i].F == index[i-1].F){
            c[p[i]] = c[p[i-1]];
        }
        else{
            c[p[i]] = c[p[i-1]]+1;
        }
    }
    int k = 1, len = 1, diff = 0;
    while(len < n && diff< n){
        vector<pair<pair<int,int>,int> > aux(n);
        for(int i = 0; i < n; i++){
            aux[i] =  {{c[i],c[(i+len)%n]},i};
        }
        sort(aux.B,aux.E);
        for(int i = 0; i < n; i++) p[i] = aux[i].S;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(aux[i].F == aux[i-1].F){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]]+1;
            }
        }
        len*=2;
    }
    for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }
    cout<<"\n";
}
 
 
 
 
int main ()
{
    string str;
    cin>>str;
    int n = str.length();
    suffixArray(str,n);
    return 0;
}