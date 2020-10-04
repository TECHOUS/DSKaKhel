/* Program to search wether a substrings t exists in one string S */

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
 
 
void count_sort(vector<int> &p, vector<int> &c){
    int n =p.size();
    vector<int> cnt(n); 
    for(auto x: c){
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
 
}
 
 
vector<int> suffixArray(string str, int n){
    str+='$'; 
    n+=1;
    vector<pair<char,int> >index;
    for(int i =0; i < n; i++){
        index.pb(mp(str[i],i));
    }
    sort(index.B,index.E);
    vector<int> p(n),c(n);
    for(int i = 0; i < n; i++) p[i] = index[i].S;
    int idx = 0;
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(index[i].F == index[i-1].F){
            c[p[i]] = c[p[i-1]];
        }
        else{
            c[p[i]] = c[p[i-1]]+1;
        }
    }
    int k = 1, len = 1;
    while(len < n){
        for(int i = 0; i < n; i++){
            p[i] = (p[i]- len +n) %n;
        }
 
        count_sort(p,c);
        
 
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        
        for(int i = 1; i < n; i++){
            pair<int,int> prev = mp(c[p[i-1]], c[(p[i-1]+len)%n]);
            pair<int,int> now = mp(c[p[i]], c[ ( p[i] + len ) % n ]);
            if(now == prev){
                c_new[p[i]] = c_new[p[i-1]];
            }
            else{
                c_new[p[i]] = c_new[p[i-1]]+1;
            }
        }
        c = c_new;
        len*=2;
    }
    /*for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }
    cout<<"\n"; */
    return p;
}
 
vector<int> pr;
string str,s;
 
 
bool searchWord(int start, int end){
    int mid = start + (end- start)/2;
    //cout<<"start: "<<start<<" end: "<<end<<" mid: "<<mid<<"\n";
    if(end >= start){
        int nstart,nend;
        bool sw = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == str[pr[mid]+i]){
                continue;
            }
            else{
                if(s[i] > str[pr[mid]+i]){
                    nstart = mid+1;
                    nend = end;
                }
                else{
                    nstart = start;
                    nend = mid-1;
                }
                sw = false;
                break;
            }
        }
        if(sw){
            return true;
        }
        else{
            return searchWord(nstart,nend);
        }
    }
    else{
        return false;
    }
}
 
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>str;
    int n = str.length();
    pr= suffixArray(str,n);
    int cas;
    cin>>cas;
    while(cas--){
        cin>>s;
        bool res = searchWord(0,str.size());
        if(res){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}