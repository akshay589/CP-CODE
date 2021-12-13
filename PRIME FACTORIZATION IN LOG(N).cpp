#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         10000000000000
#define MAXN        1000002
#define mod         1000000007 
#define pi          3.1415926535897932384626433
#define check(n,pos)    (n & (1<<pos))
#define sett(n,pos)     (n | (1<<pos))
#define unset(n,pos)    (n & ~(1<<pos))
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll spf[MAXN],i,j;
    spf[1]=1;
    for(i=2;i<MAXN;i++){
        spf[i]=i;
    }
    for(i=4;i<MAXN;i+=2){
        spf[i]=2;
    }
    for(i=3;i*i<MAXN;i++){
        if(spf[i]==i){
            for(j=i*i;j<MAXN;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    ll n;
    cin>>n;
    vector<ll> vi;
    while(n!=1){
        vi.pb(spf[n]);
        n=n/spf[n];
    }
    for(auto x:vi){
        cout<<x<<" ";
    } 
}